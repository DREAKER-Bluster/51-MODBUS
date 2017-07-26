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
extern UINT32	dwTickCount,dwIntTick;	//时钟
extern UINT8	idata sendBuf[16],receBuf[16]; //发送接收缓冲区
extern UINT8	idata checkoutError;	// ==2 偶校验错
extern UINT8	idata receTimeOut;		//接收超时

extern UINT8	sendCount;		//发送字节个数
extern UINT8	receCount;	    //接收到的字节个数
extern UINT8	sendPosi;	    //发送位置

#endif // __UART_H__


