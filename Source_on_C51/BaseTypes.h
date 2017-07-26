#ifndef __BASE_TYPES_H__
#define __BASE_TYPES_H__

//
// char,uchar
//
typedef char CHAR,INT8,int8,S8,s8,*PCHAR,*pchar,*PINT8,*pint8,*PS8,*ps8;
typedef unsigned char uchar,UCHAR,U8,u8,UINT8,uint8,BYTE,*puchar,*PUCHAR,*PU8,*pu8,*PUINT8,*puint8,*PBYTE;

// short,ushort

// int,uint
typedef int SHORT,INT,INT16,int16,/*S16,s16,*/WCHAR,wchar,WORD,word,*PSHORT,*pshort,*PINT16,*pint16,*PWCHAR,*S16,*s16,*pwchar,*PWORD,*pword;
typedef unsigned int USHORT,ushort,UINT,UINT16,uint16,U16,u16,*PUSHORT,*pushort,*PUINT16,*puint16,*PU16,*pu16;

// long,ulong
typedef long LONG,*PLONG,*plong;
typedef unsigned long ULONG,ulong,UINT32, uint32, *PULONG,*pulong, *PUINT32, *puint32;

// void
typedef void VOID,*PVOID,*LPVOID;

// convenience
typedef int BOOLEAN,BOOL;

//
// Macros
//
#define TRUE                        1
#define FALSE                       0

#endif // __BASE_TYPES_H__
