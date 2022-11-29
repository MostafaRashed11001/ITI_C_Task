#include<stdio.h>

//Main loop
int main()
{
	int arr[3];
	int MAX=0;
	for(int i=0;i<3;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
		if(MAX<arr[i])
		{
			MAX=arr[i];
		}
	}
	printf("MAX = %d",MAX);
	return 0;
}
