#include<stdio.h>

//Main loop
void main()
{
	int arr[3];
	//input for loop
	for(int i=0;i<3;i++)
	{
		printf("Please Enter Number %d:",i+1);
		fflush(stdin);
		scanf("%d",&arr[i]);
	}
	//Revrese output for loop
	for(int i=2;i>=0;i--)
	{
		printf("number %d = %d \n", i,arr[i]);
	}
}