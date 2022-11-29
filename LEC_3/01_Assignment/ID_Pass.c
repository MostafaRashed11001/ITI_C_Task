#include<stdio.h>

//Main loop
int main()
{
	int ID=0,Pass=0,counter=0,num_of_try=0;
	int ID_arr[3]={1234,5678,9870};
	int Pass_arr[5]={7788,5566,1122};
	char name_arr[5][15]={"Ahmad","Amr","Wael"};
	printf("Enter ID:");
	scanf("%d",&ID);
	for(int i=0;i<3;i++)
	{
		if(ID_arr[i]==ID)
		{
			printf("Enter Pass:");
			for(int j=0;j<3;j++)
			{
				num_of_try++;
				scanf("%d",&Pass);
				if(Pass_arr[i]==Pass)
				{
					counter++;
					printf("Name :%s",name_arr[i]);
					break;
				}
				else{
					if(j<2)
					{
						printf("Try again :");
					}
					else{
						printf("Incorrect password for 3 times. No more tries");
					}
				}
			}
			break;
		}
	}
	if((counter!=1)&&(num_of_try==0))
	{
		printf("Error ID");
	}
	return 0;
}