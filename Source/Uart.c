#include "Project.H"

UINT32	dwTickCount,dwIntTick;	//ʱ��
UINT8	idata sendBuf[16], receBuf[16]; //���ͽ��ջ�����
UINT8	idata checkoutError;	// ==2 żУ���
UINT8	idata receTimeOut;		//���ճ�ʱ

UINT8	sendCount;		//�����ֽڸ���
UINT8	receCount;	    //���յ����ֽڸ���
UINT8	sendPosi;	    //����λ��

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
	TMOD = (TMOD & 0X0F) | 0X20;	//���ڹ����ڷ�ʽ1
	TH1 = -22118400L/12/32/9600;    //�󵱲�������9600ʱ��ʱ���ĳ�ֵ
	TL1 = -22118400L/12/32/9600;
	TR1 = 1;
	SCON = 0X50;                    //01010000;
	PCON |= 0X80;                   //�����ʼӱ�
}

void commIntProc(void) interrupt 4
{
	if (!RI) return;

	RI = 0;

	receTimeOut = 20;
	receBuf[receCount] = SBUF;
	receCount ++;
	receCount &= 0x0f;		// ���ֻ����16���ֽ�����
}
