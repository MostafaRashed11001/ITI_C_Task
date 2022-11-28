#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include <string.h>
#include <math.h>
#include <time.h>
#include "BIT_CALC.h"
////////////////////////////////////Admin Window/////////////////////////////////////////
/////////////////////////////////Create New Account/////////////////////////////////////
/*Bank account ID function
Input 1 : address of struct from Admin
Output : Don't return
*/
u32 Bank_account_ID_fun()
{
	// numbers will be different every time
	time_t t;
	srand((unsigned) time(&t));
	u32 ID = rand() % 50;
	return  ID;
}
/*Password function
Input 1 : address of struct from Admin
Output : Don't return
*/
void Password_fun(Account *ptr)
{
	// numbers will be different every time
	time_t t;
	srand((unsigned) time(&t));
	// Array of numbers
	u8 numbers[] = "0123456789";
	// Array of small alphabets
	u8 letter[] = "abcdefghijklmnoqprstuvwyzx";
	// Array of capital alphabets
	u8 LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
	// Array of all the special symbols
	u8 symbols[] = "!@#$^&*?";
	u16 random = rand() % 4;
	for (u16 i = 0; i < 10; i++) 
	{
		if (random == 1) 
		{
			ptr->Password[i] = numbers[rand() % 10];
			random = rand() % 4;
		}
		else if (random == 2) 
		{
			ptr->Password[i] = symbols[rand() % 8];
			random = rand() % 4;
		}
		else if (random == 3) 
		{
			ptr->Password[i] = LETTER[rand() % 26];
			random = rand() % 4;
		}
		else 
		{
			ptr->Password[i] = letter[rand() % 26];
			random = rand() % 4;
		}
	}
}
/*Full Name check function
Input : address of struct from Admin
Output : Don't return
*/
void Full_Name_fun(Account *ptr)
{
	while(1)
	{
		//counter to cheak of spaceses
		u8 counter=0;
		//Scan Full Name
		printf("Enter  Full Name:");
		fflush(stdin);
		scanf("%[^\n]%*c", ptr->Full_Name);
		//Loop to cheack counter of spaceses
		for(u16 i=0; i<50;i++)
		{
			if((ptr->Full_Name[i]==' ')&&(ptr->Full_Name[i+1]!=' '))
			{
				counter++;
			}
			else
			{
				if(ptr->Full_Name=='\0')
					break;
				continue;
			}
		}
		//cheack entered first four name or not
		if(counter>=3)
		{
			break;
		}
		else{
			printf("Name must be at least first four");
			continue;
		}
	}
}
/*Create New Account function from Admin
Input : address of struct from Admin
Output : Don't return
*/
void Create_New_Account(Account *ptr)
{
	//Input full name
	Full_Name_fun(ptr);
	//Input Full Address
	printf("Enter  Full Address:");
	fflush(stdin);
	scanf("%[^\n]%*c", ptr->Full_Address);
	//Input National ID
	printf("Enter  National ID:");
	fflush(stdin);
	scanf("%d", &(ptr->National_ID)); // if found any character give error  
	//Input Age & cheak Guardian National ID
	printf("Enter  Age:");// if found any character give error 
	scanf("%d", &(ptr->Age));
	if(ptr->Age <21)
	{
		printf("Enter  Guardian National ID:"); // if found any character give error 
		scanf("%d", &(ptr->Guardian_National_ID));
	}
	//Input Balance
	printf("Enter  Balance:");
	scanf("%d",&(ptr->Balance));
	// Account_Status as Active           --> 1
	//					 Restricted State --> 2
	//                   Closed           --> 3
	ptr->Account_Status=1;
	//Bank account ID will be generated automatically
	ptr->Bank_Account_ID = Bank_account_ID_fun();
	//Password will be generated automatically
	Password_fun(ptr);
	//Clear Screen
	system("cls");
	//output Bank_Account_ID & Password
	printf("Bank Account ID : %d                ", ptr->Bank_Account_ID);
	printf("Password : %s ",ptr->Password);
}
/////////////////////////////////////Admin Window/////////////////////////////////////////
/////////////////////////////////Open Existing Account////////////////////////////////////
/*Make Transaction Function for Client 
Input 1 : address of struct from Admin
Input 2 : arr_Account to struct to access account need to Make Transaction it
Output : Don't return
*/
void Make_Transaction_fun(Account *ptr,Account *arr_Account)
{
	u32 scan_Account_ID=0;
	u32 scan_money=0;
	u8 check=0;
	printf("Enter Bank Account ID need to Make Transaction it: \n");
	scanf("%d",&scan_Account_ID);
	printf("Enter amount of money need to Make Transaction it: \n");
	scanf("%d",&scan_money);
	if(ptr->Account_Status==1)
	{
		if(ptr->Balance > scan_money)
		{
			while(1)
			{
				for (u16 i=0;i<50;i++)
				{
					if(arr_Account[i].Bank_Account_ID ==scan_Account_ID)
					{
						check=1;
						ptr->Balance -= scan_money;
						arr_Account[i].Balance +=scan_money;
						printf("Sussessful operation");
						break;
					}
				}
				if(check!=1)
				{
					printf("Error Bank Account ID not found");
				}
				else
				{
					break;
				}
			}
		}
		else{
			system("cls");
			printf("Transaction won’t be completed because amount of money in account Balance is less than money need to Make Transaction it");
		}
		
	}
	else{
		system("cls");
		printf("Transaction won’t be completed because account is Restricted or Closed");
	}
}
/*Change Account Status Function from Admin
Input  :  address of struct from Client
Output :  Don't return
*/
void Change_Account_Status_Fun(Account *ptr)
{
	u8 Status=0;
	// Account_Status as Active           --> 1
	//					 Restricted State --> 2
	//                   Closed           --> 3
	printf("Account_Status Status:\n");
	printf("For Set Account to Active State     '1' \n");
	printf("For Set Account to Restricted State '2' \n");
	printf("For Set Account to Closed           '3' \n");
	printf("Enter Status: \n");
	fflush(stdin);
	scanf("%c",&Status);
	switch(Status)
		{
			case '1':
				ptr->Account_Status=1;
				printf("Account Status is Active");
				break;
			case '2':
				ptr->Account_Status=2;
				printf("Account Status is Restricted State");
				break;
			case '3':
				ptr->Account_Status=3;
				printf("Account Status is Closed");
				break;
			default:
				printf("Error Status");
				break;
		}
}
/*Get Cash Function  from Admin 
Input  :  address of struct from Client
Output :  Don't return
*/
void Get_Cash_fun(Account *ptr)
{
	u32 scan_money=0;
	if(ptr->Account_Status==1)
	{
		printf("Enter amount of money need to Get Cash it: \n");
		scanf("%d",&scan_money);
		if(ptr->Balance > scan_money)
		{
			ptr->Balance -= scan_money;
			printf("Sussessful operation");
		}
		else
		{
			system("cls");
			printf("Transaction won’t be completed because amount of money in account Balance is less than money need to Make Transaction it");
		}
	}
	else{
		system("cls");
		printf("Transaction won’t be completed because account is Restricted or Closed");
	}
}
/*Deposit in Account Function from Admin
Input  :  address of struct from Client
Output :  Don't return
*/
void Deposit_in_Account_fun(Account *ptr)
{
	u32 scan_money=0;
	if(ptr->Account_Status==1)
	{
		printf("Enter amount of money need to Enter it: \n");
		scanf("%d",&scan_money);
		if(ptr->Balance > scan_money)
		{
			ptr->Balance += scan_money;
			printf("Sussessful operation");
		}
		else
		{
			system("cls");
			printf("Transaction won’t be completed because amount of money in account Balance is less than money need to Make Transaction it");
		}
	}
	else{
		system("cls");
		printf("Transaction won’t be completed because account is Restricted or Closed");
	}
}
/*Open Existing Account Function from Admin
Input 1 : address of struct from Admin
Input 2 : arr_Account to struct to access account
Output : Don't return
*/
void Open_Existing_Account(Account *ptr,Account *arr_Account)
{
	while(1)
	{
		u8 Feature=0;
		printf("Feature Open Existing Account: \n");
		printf("For Make Transaction      '1' \n");
		printf("For Change Account Status '2' \n");
		printf("For Get Cash              '3' \n");
		printf("For Deposit in Account    '4' \n");
		printf("For Return to main menu   '5' \n");
		printf("Enter Feature: \n");
		fflush(stdin);
		scanf("%c",&Feature);
		switch(Feature)
		{
			case '1':
				//Make Transaction function
				Make_Transaction_fun(ptr, arr_Account);
				break;
			case '2':
				//Change Account Status Function
				Change_Account_Status_Fun(ptr);
				break;
			case '3':
				//Get Cash Function
				Get_Cash_fun(ptr);
				break;
			case '4':
				//Deposit in Account Function
				Deposit_in_Account_fun(ptr);
				break;
			default:
				//printf("Error Feature Open Existing Account");
				break;
		}
		//Return to main menu Function
		if(Feature == '5')
			break;
	}
	system("cls");
}