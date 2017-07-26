#include "Project.h"

UINT8	idata c10ms;			//10ms ��ʱ
bit		b1ms,bt1ms,b10ms,bt10ms,b100ms,bt100ms;	//��ʱ��־λ

void TimerInit(void)
{
	TMOD = 0x51;
	TH0 = TIMER_HIGHT;
	TL0 = TIMER_LOW;
	TR0 = 1;
    ET0 = 1;
	TH1 = 0;			//9600
    TL1 = 0;
	TR1 = 0;			//��ʱ��1���ڼ�����ʱ��2���ڲ���
	ET1 = 1;
	//PT1 = 1;

	IT0 = 1;
    IT1 = 1;
	EX0 = 0;
	PX0 = 1;
    EX1 = 0;
}

//��ʱ����
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
            if(receTimeOut==0 && receCount>0)   //�ж�ͨѶ�����Ƿ�ʱ
            {
                receCount = 0;      //�����յ�ַƫ�ƼĴ�������
				checkoutError = 0;
            }
        }
	}

	if(bt100ms)
	{
		bt100ms = 0;
		b100ms = 1;
	}
    if(bt10ms)      //�ж��ж�10ms��־λ�Ƿ�1
    {
        bt10ms = 0;     //���ж�10ms��־λ
		b10ms = 1;

        c200ms++;                   //200ms��ʱ����1
        if(c200ms >= 20)            //�ж��Ƿ��ʱ��200ms
        {
            c200ms = 0;             //��200ms��ʱ��
        }
    }
}

//��ʱ��0 1ms �ж�
void timer0IntProc() interrupt 1
{
	TL0 = TIMER_LOW;
    TH0 = TIMER_HIGHT;
    dwIntTick++;
	bt1ms = 1;
    c10ms++;

    if(c10ms >= 10)
    {
        c10ms = 0;      //10ms��ʱ������
        bt10ms = 1;
    }
}

//������1�ж�
void counter1IntProc(void) interrupt 3 using 1
{

}