#include<stdio.h>

//Main loop
int main()
{
	int arr[4];
	int MAX=0,MIN=999999;
	for(int i=0;i<4;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
		if(MAX<arr[i])
		{
			MAX=arr[i];
		}
		if(MIN>arr[i])
		{
			MIN=arr[i];
		}
	}
	printf("MAX = %d \n",MAX);
	printf("MIN = %d",MIN);
	return 0;
}