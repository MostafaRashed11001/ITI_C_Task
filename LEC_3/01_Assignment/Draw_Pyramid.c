#include<stdio.h>

//Main loop
int main()
{
	int scale=0;
	int number=0;
	printf("Enter scale number: ");
	scanf("%d",&scale);
	
	while(scale!=0)
	{
		for(int i=0;i<scale;i++)
		{
			printf(" ");
		}
		number++;
		for(int i=number;i>0;i--)
		{
			printf("*");
		}
		if(number!=1)
		{
			for(int i=number-1;i>0;i--)
			{
				printf("*");
			}
		}
		printf("\n");
		scale--;
	}
	return 0;
}