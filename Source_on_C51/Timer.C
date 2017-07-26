#include "Project.h"

UINT8	idata c10ms;			//10ms 计时
bit		b1ms,bt1ms,b10ms,bt10ms,b100ms,bt100ms;	//定时标志位

void TimerInit(void)
{
	TMOD = 0x51;
	TH0 = TIMER_HIGHT;
	TL0 = TIMER_LOW;
	TR0 = 1;
    ET0 = 1;
	TH1 = 0;			//9600
    TL1 = 0;
	TR1 = 0;			//定时器1用于计数定时器2用于波特
	ET1 = 1;
	//PT1 = 1;

	IT0 = 1;
    IT1 = 1;
	EX0 = 0;
	PX0 = 1;
    EX1 = 0;
}

//定时处理
void timerProc(void)
{
	static UINT8 c200ms;

	b1ms = 0;
	b10ms = 0;
	b100ms = 0;

	ET0 = 0;
	dwTickCount = dwIntTick;
	ET0 = 1;

	if(bt1ms)
	{
		bt1ms = 0;
		b1ms = 1;

        if(receTimeOut>0)
        {
            receTimeOut--;
            if(receTimeOut==0 && receCount>0)   //判断通讯接收是否超时
            {
                receCount = 0;      //将接收地址偏移寄存器清零
				checkoutError = 0;
            }
        }
	}

	if(bt100ms)
	{
		bt100ms = 0;
		b100ms = 1;
	}
    if(bt10ms)      //判断中断10ms标志位是否1
    {
        bt10ms = 0;     //清中断10ms标志位
		b10ms = 1;

        c200ms++;                   //200ms计时器加1
        if(c200ms >= 20)            //判断是否计时到200ms
        {
            c200ms = 0;             //清200ms计时器
        }
    }
}

//定时器0 1ms 中断
void timer0IntProc() interrupt 1
{
	TL0 = TIMER_LOW;
    TH0 = TIMER_HIGHT;
    dwIntTick++;
	bt1ms = 1;
    c10ms++;

    if(c10ms >= 10)
    {
        c10ms = 0;      //10ms计时器清零
        bt10ms = 1;
    }
}

//计数器1中断
void counter1IntProc(void) interrupt 3 using 1
{

}