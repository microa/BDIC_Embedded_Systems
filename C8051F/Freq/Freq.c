/****************************************************
*	Title: Zero-Cross Freq Test			*
*	BDIC Embedded System	     		*
*	Re.Binhua, Version:06,Apr.2025		*
****************************************************/

#include "my_c8051f020.h"  // 硬件相关的 SFR 定义头文件
/*********************************************************************
 * 1) 定义基础类型
 *********************************************************************/
typedef unsigned char  uint8;
typedef signed   char   int8;

typedef unsigned int   uint16;
typedef signed   int    int16;

typedef unsigned long  uint32;
typedef signed   long   int32;

#ifndef TRUE
  #define TRUE  1
#endif
#ifndef FALSE
  #define FALSE 0
#endif

/*********************************************************************
 * 2) 全局或静态变量，用于测频相关
 *********************************************************************/
// 零交越计数
static volatile uint16 g_zero_cross_count = 0;
// 标记是否到达 1 秒测量窗口
static volatile uint8  g_one_sec_elapsed  = FALSE;

/*********************************************************************
 * 3) 禁用看门狗、切换到外部晶振
 *    （可根据自身需求保留或删除）
 *********************************************************************/
void disable_watchdog(void)
{
    EA = 0;        // 全局中断先关
    WDTCN = 0xDE;  // 解锁
    WDTCN = 0xAD;  // 关闭看门狗
}

void enable_xtal(void)
{
    // 以下仅供示例，需根据具体晶振配置和寄存器定义来写
    // 假设外部 22.1184 MHz 晶振
    OSCXCN = 0x67; // XOSCMD=0110b + XFCN=0111b => 外部晶振模式
    // 简单等待上电稳定
    {
        volatile uint16 i = 60000;
        while (i--) {}
    }
    // 等待晶振稳定
    while((OSCXCN & 0x80) == 0) {;} // XTLVLD=1 表示外部晶振稳定

    // 切换系统时钟到外部晶振
    OSCICN = 0x08; // CLKSL=1(外部振荡器), 假设与芯片对应
}

/*********************************************************************
 * 4) Timer2 中断配置，用于 1 秒测量窗口
 *********************************************************************/
/*
 * 假设外部晶振为 22.1184 MHz
 * Timer2 输入时钟 = sysclk / 12
 * 令 Timer2 以 1/32 秒中断一次 => 32 次中断即 1 秒
 */
#define XTAL_FREQ_HZ   22118400ul
#define TIMER_CLK_HZ   (XTAL_FREQ_HZ / 12)
#define TIMER2_HZ      32  // 1/32 秒中断一次

/*
 * 计算自动重装值
 * 16-bit auto-reload: 65536 - (TIMER_CLK_HZ / TIMER2_HZ)
 */
#define TIMER2_16BIT_VAL  (0xFFFF - (TIMER_CLK_HZ / TIMER2_HZ) + 1)
#define RCAP2H_VAL        ((uint8)((TIMER2_16BIT_VAL >> 8) & 0xFF))
#define RCAP2L_VAL        ((uint8)(TIMER2_16BIT_VAL & 0xFF))

/*
 * Timer2 初始化，只配置与测频相关寄存器
 */
static void init_timer2_for_freq(void)
{
    // 1) 配置 Timer2 的输入时钟 = SYSCLK/12
    //    CKCON: T2M=0 => timer2 用 /12
    CKCON &= ~(1 << 2); // T2M=0

    // 2) 配置 Timer2 为 auto-reload 模式
    //    T2CON: CPRL2=0, CT2=0 => 计时器模式 (sysclk), auto-reload
    T2CON &= ~0x04; // CT2=0
    T2CON &= ~0x01; // CPRL2=0

    // 3) 装入重载值
    RCAP2H = RCAP2H_VAL;
    RCAP2L = RCAP2L_VAL;

    // 4) 清中断标志、开中断
    TF2  = 0;
    ET2  = 1;     // 使能 Timer2 中断
    EA   = 1;     // 开 CPU 全局中断
}

/*
 * Timer2 中断服务程序 => interrupt 5 (针对 C51 编译器)
 * 每次进中断说明经过了 1/32 秒。到第 32 次（1 秒）时，设置 g_one_sec_elapsed=TRUE。
 */
void timer2_isr(void) interrupt 5
{
    static uint8 t2_count = 0;

    t2_count++;
    if (t2_count >= TIMER2_HZ)
    {
        // 1秒到了
        g_one_sec_elapsed = TRUE;
        t2_count = 0;
    }
    // 清除中断标志
    TF2 = 0;
}

/*********************************************************************
 * 5) 零交越检测(示例存根)：
 *    实际项目应根据硬件/输入捕获等方式实现。
 *********************************************************************/
static bit check_for_zero_crosings(void)
{
    // TODO: 这里根据实际硬件读取输入并判断是否发生零交越
    //       返回1表示本次调用发现了新的零交越，否则0
    // 以下仅做示例：一直返回0
    return 0;
}

/*********************************************************************
 * 6) 模块对外接口：
 *    1) freq_init(): 完成测频所需的硬件配置(不含显示)
 *    2) measure_frequency(): 每调一次，返回当前频率
 *********************************************************************/

/*
 * freq_init():
 *   - 可在程序启动时调用
 */
void freq_init(void)
{
    disable_watchdog();
    enable_xtal();
    init_timer2_for_freq();
    // 如果有更多 GPIO/ADC/Comparator 等零交越相关初始化，可在此加入
}

/*
 * measure_frequency():
 *   - 阻塞式测量：开始 1 秒窗口并统计零交越
 *   - 返回测得的频率(Hz)
 */
uint16 measure_frequency(void)
{
    uint16 freq;
    // 清计数与标志
    g_zero_cross_count = 0;
    g_one_sec_elapsed  = FALSE;

    // 启动 Timer2
    TR2 = 1;  // 使能 Timer2

    // 在 1 秒内循环检测零交越
    while(!g_one_sec_elapsed)
    {
        if (check_for_zero_crosings())
        {
            g_zero_cross_count++;
        }
    }

    // 时间到 => 关闭 Timer2
    TR2 = 0;

    // 2 次零交越 = 1 个完整周期 => 频率 = 零交越计数 / 2
    freq = (g_zero_cross_count >> 1);

    return freq;
}

/*********************************************************************
 * 7) main()函数示例：演示如何调用
 *********************************************************************/
void main(void)
{
    uint16 current_freq;

    // 先完成一次性硬件配置
    freq_init();

    // 循环测频
    while(1)
    {
        current_freq = measure_frequency();
        // 此处可以将 freq 打印到串口、或做其他处理
        // 比如：printf("freq = %u Hz\n", current_freq);
    }
}
