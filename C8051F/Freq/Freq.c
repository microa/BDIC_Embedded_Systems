/****************************************************
*	Title: Functions for Zero-Cross Freq Test		*
*	BDIC Embedded System	     		*
*   Module ports: V-   : GND
*                 V+   : VDD
*                 PWM  : AN0.3
*                 GND  : AGND
*	Binhua, Re:17,Apr.2025		    *
****************************************************/

/* ---------- ADC 差分采样 ---------- */
static void init_ADC(void){
    REF0CN=0x03; AMX0CF=0x02; ADC0CF=0x04; AMX0SL=0x02; ADC0CN=0x80;
}
static s16 ADC_Read(void){
    s16 v;
    AD0INT=0; AD0BUSY=1;
    while(!AD0INT);
    ((u8*)&v)[0]=ADC0H;
    ((u8*)&v)[1]=ADC0L;
    return v;
}

/* ---------- 过零检测（滞回） ---------- */
#define RISE  100
#define FALL -100
static bit half_state=0;
static bit Zero_Crossing(void){
    s16 x=ADC_Read();
    if((half_state==0 && x>RISE) || (half_state==1 && x<FALL)){
        half_state^=1;
        return 1;
    }
    return 0;
}

/* ---------- 1 秒窗口 (Timer2) ---------- */
#define XTAL 22118400UL
#define TCLK (XTAL/12)
#define DIV  32
#define PRE (0xFFFF - (TCLK/DIV) + 1)
#define RH  (u8)(PRE>>8)
#define RL  (u8)(PRE&0xFF)
static volatile bit sec_flag=0;
void timer2_isr(void) interrupt 5 using 1 {
    static u8 t=0;
    if(++t >= DIV){
        sec_flag = 1;
        t = 0;
    }
    TF2 = 0;
}
static void init_timer2(void){
    CKCON=0x00;
    CT2=0; CPRL2=0;
    RCAP2H=RH; RCAP2L=RL;
    ET2=1; EA=1; TR2=1;
}


/* ---------- 晶体设置 ---------- */
static void enable_xtal(void){
    OSCXCN=(6<<4)|(7<<0);
    while(!(OSCXCN&0x80));
    OSCICN|=0x08;
}

/* ---------- 初始化 ---------- */
static void init_all(){
    dis_wdt();
    init_IO();
    init_ADC();
    enable_xtal();
    init_timer2();
}
