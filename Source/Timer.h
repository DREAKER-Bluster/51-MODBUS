#ifndef __TIMER_H__
#define __TIMER_H__
//
// Macros definition
//
#define TIMER_HIGHT	0xf8
#define TIMER_LOW	0xcd

//
// Exported functions declare
//
void TimerInit(void);
void timerProc(void);

//
// Exported variables declare
//
extern UINT8	idata c10ms;			//10ms ��ʱ
extern bit		b1ms,bt1ms,b10ms,bt10ms,b100ms,bt100ms;	//��ʱ��־λ

#endif // __TIMER_H__
