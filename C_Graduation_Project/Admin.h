#ifndef Admin_H_
#define Admin_H_
//Bank account ID function
u32 Bank_account_ID_fun();
//Password function
void Password_fun(Account *ptr);
//Full Name check function
void Full_Name_fun(Account *ptr);
//Create New Account function
void Create_New_Account(Account *ptr);
//Make Transaction Function
void Make_Transaction_fun(Account *ptr,Account *arr_Account);
//Change Account Status Function
void Change_Account_Status_Fun(Account *ptr);
//Get Cash Function
void Get_Cash_fun(Account *ptr);
//Deposit in Account Function
void Deposit_in_Account_fun(Account *ptr);
//Open Existing Account Function
void Open_Existing_Account(Account *ptr,Account *arr_Account);
#endif