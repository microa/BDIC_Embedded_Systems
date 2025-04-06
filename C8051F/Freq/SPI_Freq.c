/****************************************************
*	Title: Zero-Cross Freq Test			*
*	BDIC Embedded System	     		*
*	Re.Binhua, Version:06,Apr.2025		*
****************************************************/

#include "my_c8051f020.h"  // Ӳ����ص� SFR ����ͷ�ļ�
/*********************************************************************
 * 1) �����������
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
 * 2) ȫ�ֻ�̬���������ڲ�Ƶ���
 *********************************************************************/
// �㽻Խ����
static volatile uint16 g_zero_cross_count = 0;
// ����Ƿ񵽴� 1 ���������
static volatile uint8  g_one_sec_elapsed  = FALSE;

/*********************************************************************
 * 3) ���ÿ��Ź����л����ⲿ����
 *    ���ɸ���������������ɾ����
 *********************************************************************/
void disable_watchdog(void)
{
    EA = 0;        // ȫ���ж��ȹ�
    WDTCN = 0xDE;  // ����
    WDTCN = 0xAD;  // �رտ��Ź�
}

void enable_xtal(void)
{
    // ���½���ʾ��������ݾ��徧�����úͼĴ���������д
    // �����ⲿ 22.1184 MHz ����
    OSCXCN = 0x67; // XOSCMD=0110b + XFCN=0111b => �ⲿ����ģʽ
    // �򵥵ȴ��ϵ��ȶ�
    {
        volatile uint16 i = 60000;
        while (i--) {}
    }
    // �ȴ������ȶ�
    while((OSCXCN & 0x80) == 0) {;} // XTLVLD=1 ��ʾ�ⲿ�����ȶ�

    // �л�ϵͳʱ�ӵ��ⲿ����
    OSCICN = 0x08; // CLKSL=1(�ⲿ����), ������оƬ��Ӧ
}

/*********************************************************************
 * 4) Timer2 �ж����ã����� 1 ���������
 *********************************************************************/
/*
 * �����ⲿ����Ϊ 22.1184 MHz
 * Timer2 ����ʱ�� = sysclk / 12
 * �� Timer2 �� 1/32 ���ж�һ�� => 32 ���жϼ� 1 ��
 */
#define XTAL_FREQ_HZ   22118400ul
#define TIMER_CLK_HZ   (XTAL_FREQ_HZ / 12)
#define TIMER2_HZ      32  // 1/32 ���ж�һ��

/*
 * �����Զ���װֵ
 * 16-bit auto-reload: 65536 - (TIMER_CLK_HZ / TIMER2_HZ)
 */
#define TIMER2_16BIT_VAL  (0xFFFF - (TIMER_CLK_HZ / TIMER2_HZ) + 1)
#define RCAP2H_VAL        ((uint8)((TIMER2_16BIT_VAL >> 8) & 0xFF))
#define RCAP2L_VAL        ((uint8)(TIMER2_16BIT_VAL & 0xFF))

/*
 * Timer2 ��ʼ����ֻ�������Ƶ��ؼĴ���
 */
static void init_timer2_for_freq(void)
{
    // 1) ���� Timer2 ������ʱ�� = SYSCLK/12
    //    CKCON: T2M=0 => timer2 �� /12
    CKCON &= ~(1 << 2); // T2M=0

    // 2) ���� Timer2 Ϊ auto-reload ģʽ
    //    T2CON: CPRL2=0, CT2=0 => ��ʱ��ģʽ (sysclk), auto-reload
    T2CON &= ~0x04; // CT2=0
    T2CON &= ~0x01; // CPRL2=0

    // 3) װ������ֵ
    RCAP2H = RCAP2H_VAL;
    RCAP2L = RCAP2L_VAL;

    // 4) ���жϱ�־�����ж�
    TF2  = 0;
    ET2  = 1;     // ʹ�� Timer2 �ж�
    EA   = 1;     // �� CPU ȫ���ж�
}

/*
 * Timer2 �жϷ������ => interrupt 5 (��� C51 ������)
 * ÿ�ν��ж�˵�������� 1/32 �롣���� 32 �Σ�1 �룩ʱ������ g_one_sec_elapsed=TRUE��
 */
void timer2_isr(void) interrupt 5
{
    static uint8 t2_count = 0;

    t2_count++;
    if (t2_count >= TIMER2_HZ)
    {
        // 1�뵽��
        g_one_sec_elapsed = TRUE;
        t2_count = 0;
    }
    // ����жϱ�־
    TF2 = 0;
}

/*********************************************************************
 * 5) �㽻Խ���(ʾ�����)��
 *    ʵ����ĿӦ����Ӳ��/���벶��ȷ�ʽʵ�֡�
 *********************************************************************/
static bit check_for_zero_crosings(void)
{
    // TODO: �������ʵ��Ӳ����ȡ���벢�ж��Ƿ����㽻Խ
    //       ����1��ʾ���ε��÷������µ��㽻Խ������0
    // ���½���ʾ����һֱ����0
    return 0;
}

/*********************************************************************
 * 6) ģ�����ӿڣ�
 *    1) freq_init(): ��ɲ�Ƶ�����Ӳ������(������ʾ)
 *    2) measure_frequency(): ÿ��һ�Σ����ص�ǰƵ��
 *********************************************************************/

/*
 * freq_init():
 *   - ���ڳ�������ʱ����
 */
void freq_init(void)
{
    disable_watchdog();
    enable_xtal();
    init_timer2_for_freq();
    // ����и��� GPIO/ADC/Comparator ���㽻Խ��س�ʼ�������ڴ˼���
}

/*
 * measure_frequency():
 *   - ����ʽ��������ʼ 1 �봰�ڲ�ͳ���㽻Խ
 *   - ���ز�õ�Ƶ��(Hz)
 */
uint16 measure_frequency(void)
{
    uint16 freq;
    // ��������־
    g_zero_cross_count = 0;
    g_one_sec_elapsed  = FALSE;

    // ���� Timer2
    TR2 = 1;  // ʹ�� Timer2

    // �� 1 ����ѭ������㽻Խ
    while(!g_one_sec_elapsed)
    {
        if (check_for_zero_crosings())
        {
            g_zero_cross_count++;
        }
    }

    // ʱ�䵽 => �ر� Timer2
    TR2 = 0;

    // 2 ���㽻Խ = 1 ���������� => Ƶ�� = �㽻Խ���� / 2
    freq = (g_zero_cross_count >> 1);

    return freq;
}

/*********************************************************************
 * 7) main()����ʾ������ʾ��ε���
 *********************************************************************/
void main(void)
{
    uint16 current_freq;

    // �����һ����Ӳ������
    freq_init();

    // ѭ����Ƶ
    while(1)
    {
        current_freq = measure_frequency();
        // �˴����Խ� freq ��ӡ�����ڡ�������������
        // ���磺printf("freq = %u Hz\n", current_freq);
    }
}
