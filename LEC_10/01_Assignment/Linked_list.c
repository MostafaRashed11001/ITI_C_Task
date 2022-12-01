#include <stdio.h>
#include <stdlib.h>
#include"STD_Types.h"
#define Null ((void*)0)

Node *P_first=Null;
Node *P_last=Null;
//Create New Node
Node *Create_node(u32 value)
{
    Node *New_node=(Node*)malloc(1*sizeof(Node));
	New_node->data = value;
    New_node->Next=Null;
    New_node->Prev=Null;
    return New_node;
}
//Add Node
void Add(Node *node)
{
    if(P_first==Null)
    {
        P_first=P_last=node;
    }
    else
    {
        P_last->Next=node;
        node->Prev=P_last;
        P_last=node;
    }
}
//Search
Node *Search(u32 value)
{
    Node *P_search = P_first;
    while(P_search != Null)
    {
        if(P_search->data == value)
        {
            return P_search;
        }
        else
        {
            P_search = P_search->Next;
        }
    }
    return Null;
}
//Insert New Node --> After Node
void InsertAfter(Node *P_after, Node *P_new)
{
        P_new->Prev=P_after;
        P_new->Next=P_after->Next;
        P_after->Next->Prev=P_new;
        P_after->Next=P_new;
}
//Delete Node
void Delete(Node *P_delete)
{
    if(P_delete==P_first)
    {
        if(P_delete==P_last)
        {
            P_first=P_last=Null;
        }
        else
        {
            P_first=P_first->Next;
            P_first->Prev=Null;
        }
    }
    else if(P_delete==P_last)
    {
        P_last=P_last->Prev;
        P_last->Next=Null;
    }
    else
    {
        P_delete->Prev->Next=P_delete->Next;
        P_delete->Next->Prev=P_delete->Prev;
    }
    free(P_delete);
}
//Display All
void DisplayAll()
{
    u8 counter1 = 0;
    Node *P_Display = P_first;
    while(P_Display != Null)
    {
        printf("The value of node %d = %d\n", counter1+1, P_Display->data);
        counter1++;
        P_Display=P_Display->Next;
    }
	
	if(counter1 == 0)
	{
		printf("Linked list is empty\n");
	}
}
//Display Node
void Display_Node(Node *P_Display)
{
	if(P_Display != Null)
	{
		printf("The value of node = %d\n", P_Display->data);
	}
	else if(P_Display == Null)
	{
		printf("Node is not found\n");
	}
}
//Delete node using value
void Delete_node_using_value(u32 value)
{
	Node *P_Display = P_first;
	Node *P_delete=NULL;
    while(P_Display->Next!= Null)
    {
        if(P_Display->data == value)
		{
			printf("Found it");
			P_delete=P_Display;
			break;
		}
		P_Display=P_Display->Next;
    }
	if (P_delete!=NULL)
	{
		if(P_delete==P_first)
		{
			if(P_delete==P_last)
			{
				P_first=P_last=Null;
			}
			else
			{
				P_first=P_first->Next;
				P_first->Prev=Null;
			}
		}
		else if(P_delete==P_last)
		{
			P_last=P_last->Prev;
			P_last->Next=Null;
		}
		else
		{
			P_delete->Prev->Next=P_delete->Next;
			P_delete->Next->Prev=P_delete->Prev;
		}
		free(P_delete);
	}
	else
	{
		printf("value is not found\n");
	}
}
//Add and Insert
void Add_and_Insert(u32 value,u32 Index)
{
	u32 counter=0;
	Node *P_new=Create_node(value);
	Node *P_after= P_first;
	for(u32 i=0;i<(Index-1);i++)
	{
		if (P_after->Next!=NULL)
		{
			counter++;
			P_after=P_after->Next;
		}
		else if (P_after->Next==NULL)
		{
			if(counter==(Index-1))
			{
				Add(P_new);
				counter=-1;
			}
			else
			{
				printf("Error Index \n");
			}
			break;
		}
		
	}
	if(counter==(Index-1))
	{
		if (P_after->Next==NULL)
		{
			Add(P_new);
			counter=-1;
		}
		else if (Index==1)
		{
			P_new->Prev=NULL;
			P_new->Next=P_first;
			P_first->Prev=P_new;
			P_first=P_new;
		}
		else
		{
			InsertAfter(P_after->Prev, P_new);
			counter==0;
		}
	}
}