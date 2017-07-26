/*********************************************************************************
* ��˵    ������ �˳���Ϊ51��Ƭ����MCGS��̬�����Modbus RTUͨѶ��λ������
                 �˳�����STC89C52RC��Ƭ���ϲ���ͨ����������ֲ������51ϵ�е�Ƭ����
* ���������ܡ��� 51��Ƭ����MCGS��̬�����Modbus RTUͨѶ������			   			            			    
* ����    �ġ��� DREAKER Bluster
* ���޸�ʱ�䡿�� 2017�� 7��1��
**********************************************************************************/
#ifndef __MODBUS_H__
#define __MODBUS_H__
//
// Exported functions declare
//
void beginSend(void);
void checkComm0Modbus(void);
void readCoil(void);
void readRegisters(void);
void forceSingleCoil(void);
void presetSingleRegister(void);
void presetMultipleRegisters(void);
void forceMultipleCoils(void);
UINT16 getRegisterVal(UINT16 addr,UINT16 *tempData);
UINT16 setRegisterVal(UINT16 addr,UINT16 tempData);
UINT16 getCoilVal(UINT16 addr,UINT16 *tempData);
UINT16 setCoilVal(UINT16 addr,UINT16 tempData);



//
// External variables declare
//
extern UINT8   localAddr;


extern UINT16 testRegister0,	// ���ԼĴ���
			testRegister1,
			testRegister2,
			testRegister3,//��ŵ�ǰ�¶�
			testRegister4,//��д�Ĵ���  ����P1�����
			testRegister5,
			testRegister6,
			testRegister7,
			testRegister8,
			testRegister9;

#endif // __MODBUS_H__
