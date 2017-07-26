/*********************************************************************************
* 【说    明】： 此程序为51单片机与MCGS组态王软件Modbus RTU通讯下位机程序，
                 此程序在STC89C52RC单片机上测试通过，可以移植到其他51系列单片机！
* 【函数功能】： 51单片机与MCGS组态王软件Modbus RTU通讯主程序			   			            			    
* 【修    改】： DREAKER Bluster
* 【修改时间】： 2017年 7月1日
**********************************************************************************/
#include "Project.h"
// unsigned char code led[]={63,6,91,79,102,109,125,7,127,111,};//十进制
// unsinged char code led[]={0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F,};//16进制:


void main(void)
{
	UINT nCounter = 0;
	UCHAR ucLedIndex = 0;

	SYSTEM_DISABLE_INTERRUPT();

	TimerInit();
	UartInit(9600, 1);

	SYSTEM_ENABLE_INTERRUPT();

	P1=0x7f;

	while(1) {
        
		timerProc(); 
		checkComm0Modbus();//检测modbus帧
        


	}
}
