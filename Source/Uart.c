#include "Project.H"

UINT32	dwTickCount,dwIntTick;	//时钟
UINT8	idata sendBuf[16], receBuf[16]; //发送接收缓冲区
UINT8	idata checkoutError;	// ==2 偶校验错
UINT8	idata receTimeOut;		//接收超时

UINT8	sendCount;		//发送字节个数
UINT8	receCount;	    //接收到的字节个数
UINT8	sendPosi;	    //发送位置

void UartSendByte (UCHAR ucByte)
{
	SBUF = ucByte;
	while (!TI);
	TI = 0;
}

void UartSendBytes (UCHAR *buf,UINT nLen)
{
	UINT i;

	for (i = 0;i < nLen;i ++)
		UartSendByte (buf[i]);
}

void UartSendString (CHAR *ucBuf)
{
	UINT i;

	for (i = 0; ucBuf[i]; i ++)
		UartSendByte (ucBuf[i]);
}

void UartSendInt (INT nNumber)
{
	UCHAR idata ucBuf[16];
	UINT nLen;

	nLen = sprintf (ucBuf,"%d\r\n",nNumber);
	UartSendBytes (ucBuf,nLen);
}

void UartSendHex (UINT nNumber)
{
	UCHAR idata ucBuf[16];
	UINT nLen;

	nLen = sprintf (ucBuf,"0x%04X\r\n",nNumber);
	UartSendBytes (ucBuf,nLen);
}

void UartInit (ULONG baud, UCHAR mode)
{
 	IE=0x90;
	TMOD = (TMOD & 0X0F) | 0X20;	//串口工作在方式1
	TH1 = -22118400L/12/32/9600;    //求当波特率是9600时定时器的初值
	TL1 = -22118400L/12/32/9600;
	TR1 = 1;
	SCON = 0X50;                    //01010000;
	PCON |= 0X80;                   //波特率加倍
}

void commIntProc(void) interrupt 4
{
	if (!RI) return;

	RI = 0;

	receTimeOut = 20;
	receBuf[receCount] = SBUF;
	receCount ++;
	receCount &= 0x0f;		// 最多只接收16个字节数据
}
