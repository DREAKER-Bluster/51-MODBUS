/*********************************************************************************
* ��˵    ������ �˳���Ϊ51��Ƭ����MCGS��̬�����Modbus RTUͨѶ��λ������
                 �˳�����STC89C52RC��Ƭ���ϲ���ͨ����������ֲ������51ϵ�е�Ƭ����
* ���������ܡ��� 51��Ƭ����MCGS��̬�����Modbus RTUͨѶ������			   			            			    
* ����    �ġ��� DREAKER Bluster
* ���޸�ʱ�䡿�� 2017�� 7��1��
**********************************************************************************/
#include "Project.h"
// unsigned char code led[]={63,6,91,79,102,109,125,7,127,111,};//ʮ����
// unsinged char code led[]={0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F,};//16����:


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
		checkComm0Modbus();//���modbus֡
        


	}
}
