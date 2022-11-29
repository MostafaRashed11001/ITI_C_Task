#include<stdio.h>

//Main loop
int main()
{
	int number=0,cunter=0;
	int arr[10];
	//input for loop
	for(int i=0;i<10;i++)
	{
		printf("Please Enter Number %d:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Please Enter Number search it:");
	scanf("%d",&number);
	for(int i=0;i<10;i++)
	{
		if(arr[i]==number)
		{
			cunter++;
			printf("Value is excist at element :%d",i+1);
		}
	}
	if(cunter!=1)
	{
		printf("Value isn't excist at element");
	}
	return 0;
}