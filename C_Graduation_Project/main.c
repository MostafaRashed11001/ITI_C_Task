#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include <string.h>
#include <math.h>
#include <time.h>
#include "BIT_CALC.h"
#include "Admin.h"
#include "Client.h"
/* 
   1- Dif array to struct to save account
   2- Dif Admin Username
   3- Dif Admin Password
*/
Account arr_Account[50] = {0};
u8 Admin_Username[10] ="IMT Admin";
u8 Admin_Password[10] ="ITI_g2_MR";
int main()
{
	//Dif void pointer to arrey
	void* check[50];
	u8 Window = 0;
	//Dif color to screen
	system("color b");
	//Clear Screen
	system("cls");
	printf("----------Welcome in IMT Bank---------- \n");
	while (1)
	{
		//Input Window
		printf(" For Admin Window press '1' \n For Client Window press '2'\n For Exit press '0' \n");
		printf(" Window :");
		fflush(stdin);
		scanf("%c",&Window);
		if (Window == '0')
		{
			//Exit Window
			printf("----------Thank you for chooseing IMT Bank----------\n");
			break;
		}
		else if (Window=='1')
		{
			//Admin Window
			/* 
				1- Dif Admin Username array check
				2- Dif Admin Password array check
			*/
			u8 Admin_Username_ch[10];
			u8 Admin_Password_ch[10];
			printf("----------Welcome to the IMT Admin Window----------\n");
			while (1)
			{
				// Input Admin Username to check it
				printf("Enter Admin Username: \n");
				fflush(stdin);
				scanf("%[^\n]%*c", Admin_Username_ch);
				u8 Username = strcmp(Admin_Username,Admin_Username_ch);
				if (Username == 0)
				{
					//Input Admin Password to check it 
					printf("Enter Admin Password: \n");
					fflush(stdin);
					scanf("%[^\n]%*c", Admin_Password_ch);
					u8 Password = strcmp(Admin_Password,Admin_Password_ch);
					if (Password == 0)
					{
						while(1)
						{
							//Input features to Admin Window
							u8 features=0;
							printf("\nPlease input features :\n");
							printf("For Create New Account   '1'\n");
							printf("For Open Existing Account'2'\n");
							printf("For Exit the System      '3'\n");
							printf("Feature:  ");
							fflush(stdin);
							scanf("%c",&features);
							if(features== '1')
							{
								//Create New Account Function
								for(u16 i=0;i<50;i++)
								{
									 if(check[i]==NULL)
									{
										check[i]=&arr_Account[i];
										Create_New_Account(&arr_Account[i]);
										break;
									} 
								}
							}
							else if (features== '2')
							{
								while(1)
								{
									u32 scan_Account_ID=0;
									u8 check=0;
									//Input Client Bank Account ID
									printf("Enter Client Bank Account ID : \n");
									scanf("%d",&scan_Account_ID);
									for (u16 i=0;i<50;i++)
									{
										if(arr_Account[i].Bank_Account_ID ==scan_Account_ID)
										{
											//Open Existing Account Function
											check=1;
											Open_Existing_Account(&arr_Account[i],arr_Account);
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
							else if (features== '3')
							{
								//Exit the System
								break;
							}
						}
						break;
					}
					else
					{
						printf("Error Admin Password");
					}
				}
				else
				{
					printf("Error Admin Username");
				}
			}
			system("cls");
		}
		else if (Window== '2')
		{
			//Open Client Window
			while(1)
			{
				u32 scan_Account_ID=0;
				u8 check=0;
				//Input Bank Account ID
				printf("Enter Bank Account ID : \n");
				scanf("%d",&scan_Account_ID);
				//for loop to found Bank Account ID
				for (u16 i=0;i<50;i++)
				{
					if(arr_Account[i].Bank_Account_ID ==scan_Account_ID)
					{
						//Input Client_Password and check it 
						u8 Client_Password_ch[10];
						printf("Enter Password:");
						fflush(stdin);
						scanf("%[^\n]%*c", Client_Password_ch);
						u8 Password = strcmp(arr_Account[i].Password,Client_Password_ch);
						if (Password == 0)
						{
							//calling Client Window function
							check=1;
							Client_Window_fun(&arr_Account[i],arr_Account);
							break;
						}
						else 
						{
							printf("Erorr Bank Account ID or Password not correct \n");
						}
					}
				}
				if(check!=1)
				{
					printf("Error Bank Account ID not found \n");
				}
				else
				{
					break;
				}
			}
			system("cls");
		}
		else
		{
			system("cls");
			printf("Error Window \n");
			continue;
		}
	}
	return 0;
}