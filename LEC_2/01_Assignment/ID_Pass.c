#include<stdio.h>

//Main loop
int main()
{
	int ID=0,Pass=0,counter=0;
	int ID_arr[5]={1,2,3,4,5};
	int Pass_arr[5]={0,9,8,7,6};
	char name_arr[5][15]={"Ahmad","Mahmoud","Abdelrahman","Pola","Khaled"};
	printf("Enter ID:");
	scanf("%d",&ID);
	for(int i=0;i<5;i++)
	{
		if(ID_arr[i]==ID)
		{
			counter++;
			printf("Enter Pass:");
			scanf("%d",&Pass);
			if(Pass_arr[i]==Pass)
			{
				printf("Name :%s",name_arr[i]);
				break;
			}
			else{
				printf("Error Pass");
				break;
			}
		}
	}
	if(counter!=1)
	{
		printf("Error ID");
	}
	return 0;
}