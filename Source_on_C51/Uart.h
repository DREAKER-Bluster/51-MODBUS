#ifndef __UART_H__
#define __UART_H__

//
// Macros definition
//
#define UART_DISABLE_INTERRUPT()     	ES=0
#define UART_ENABLE_INTERRUPT()      	ES=1

#define UART_RESET()					RI=0

//
// Exported functions declare
//
void UartSendByte (UCHAR);
void UartSendBytes (UCHAR*,UINT);
void UartSendString (CHAR*);
void UartSendInt (INT);
void UartSendHex (UINT);
void UartInit (ULONG baud, UCHAR mode);

//
// Exported variables declare
//
extern UINT32	dwTickCount,dwIntTick;	//ʱ��
extern UINT8	idata sendBuf[16],receBuf[16]; //���ͽ��ջ�����
extern UINT8	idata checkoutError;	// ==2 żУ���
extern UINT8	idata receTimeOut;		//���ճ�ʱ

extern UINT8	sendCount;		//�����ֽڸ���
extern UINT8	receCount;	    //���յ����ֽڸ���
extern UINT8	sendPosi;	    //����λ��

#endif // __UART_H__


