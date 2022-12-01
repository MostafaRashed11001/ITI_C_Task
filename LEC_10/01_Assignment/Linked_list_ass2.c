#include <stdio.h>
#include <stdlib.h>
#include"STD_Types.h"
#include"Linked_list.h"
#define Null 0


int main()
{
	u32 Index=0;
	u32 value=0;
	u8 input=0;
	while(1)
	{
		printf("To add node enter              '0' \n");
		printf("To print the linked list enter '1' \n");
		printf("To exit press                  '2' \n");
		printf("To ADD & Index                 '3' \n");
		printf("Your Choice:\n");
		fflush(stdin);
		scanf("%c",&input);
		switch(input)
		{
			case '0':
				printf("Enter the value :");
				scanf("%d",&value);
				Node *node=Create_node(value);
				Add(node);
				DisplayAll();
				break;
			case '1':
				DisplayAll();
				break;
			case '2':
				break;
			case '3':
				printf("Enter the value :");
				scanf("%d",&value);
				printf("Enter the Index :");
				//fflush(stdin);
				scanf("%d",&Index);
				Add_and_Insert(value,Index);
				DisplayAll();
				break;
			default:
				printf("Error Input");
				break;
		}
		if(input=='2')
		{
			printf("Thank you");
			break;
		}
	}
	return 0;
}