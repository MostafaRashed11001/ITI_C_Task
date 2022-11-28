#ifndef STD_Types_H
#define STD_Types_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
// Struct to dif any Bank Account
typedef struct Bank_Account
{
	u8 Full_Name[50];
	u8 Full_Address[70];
	u8 Guardian[50];
	u8 Password[10];
	u8 Age;
	u8 Account_Status;
	u32 National_ID;
	u32 Bank_Account_ID;
	u32 Guardian_National_ID;
	u32 Balance;
}Account;

#endif