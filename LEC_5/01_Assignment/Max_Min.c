#include<stdio.h>
#include<limits.h> 

//Main loop
int main()
{
	int arr[10];
	int MAX=0,MIN=INT_MAX;
	for(int i=0;i<10;i++)
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