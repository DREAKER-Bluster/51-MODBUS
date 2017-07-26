#ifndef __SYSTEM_H__
#define __SYSTEM_H__
//
// Macros definition
//
#define	FOSC                  			12000000 	// ¾§ÕñÆµÂÊ12M
//#define	FOSC                  			11059200 	// ¾§ÕñÆµÂÊ11.0592M

#define SYSTEM_DISABLE_INTERRUPT()     EA=0
#define SYSTEM_ENABLE_INTERRUPT()      EA=1

//
// Exported functions declare
//
void SystemInit (void);

#endif // __SYSTEM_H__
