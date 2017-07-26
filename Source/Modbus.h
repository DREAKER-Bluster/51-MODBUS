/*********************************************************************************
* 【说    明】： 此程序为51单片机与MCGS组态王软件Modbus RTU通讯下位机程序，
                 此程序在STC89C52RC单片机上测试通过，可以移植到其他51系列单片机！
* 【函数功能】： 51单片机与MCGS组态王软件Modbus RTU通讯主程序			   			            			    
* 【修    改】： DREAKER Bluster
* 【修改时间】： 2017年 7月1日
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


extern UINT16 testRegister0,	// 测试寄存器
			testRegister1,
			testRegister2,
			testRegister3,//存放当前温度
			testRegister4,//读写寄存器  控制P1口输出
			testRegister5,
			testRegister6,
			testRegister7,
			testRegister8,
			testRegister9;

#endif // __MODBUS_H__
