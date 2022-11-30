#include<stdio.h>
//Sum
int* sum_number(int *py,int *px)
{
    int d=0;
    d = *py + *px;
    int *p = &d;
    return p;
}
//Sup
int* sub_number(int *py,int *px)
{
    int d=0;
    d = *py - *px;
    int *p = &d;
    return p;
}
//Multiply
int* mul_number(int *py,int *px)
{
    int d=0;
    d = *py * *px;
    int *p = &d;
    return p;
}
//Divide
int* div_number(int *py,int *px)
{
    int d=0;
    d = *py / *px;
    int *p = &d;
    return p;
}
//Reminder
int* Reminder_number(int *py,int *px)
{
    int d=0;
    d = *py % *px;
    int *p = &d;
    return p;
}
//And
int* and_number(int *py,int *px)
{
    int d=0;
    d = *py & *px;
    int *p = &d;
    return p;
}
//Or
int* or_number(int *py,int *px)
{
    int d=0;
    d = *py | *px;
    int *p = &d;
    return p;
}
//Xor 
int* xor_number(int *py,int *px)
{
    int d=0;
    d = *py ^ *px;
    int *p = &d;
    return p;
}
//Not
int* not_number(int *py)
{
    int d=0;
    d = !(*py);
    int *p = &d;
    return p;
}
//increment
int* increment_number(int *py)
{
    int d=0;
    d = ++(*py);
    int *p = &d;
    return p;
}
//Decrement
int* decrement_number(int *py)
{
    int d=0;
    d = --(*py);
    int *p = &d;
    return p;
}
//Main loop
int main(){
    int y=0,x=0,z=0;
	int Op=0;
	printf("Operation:\n");
	printf("for Add       press'1'\n");
	printf("for Subtract  press'2'\n");
	printf("for Multiply  press'3'\n");
	printf("for Divide    press'4'\n");
	printf("for And       press'5'\n");
	printf("for Or        press'6'\n");
	printf("for Not       press'7'\n");
	printf("for Xor       press'8'\n");
	printf("for Reminder  press'9'\n");
	printf("for Increment press'10'\n");
	printf("for Decrement press'11'\n");
	printf("Enter Operation :");
	scanf("%d",&Op);
	if((Op<=9)&&(Op!=7)&&(Op>0))
	{
		printf("Enter x =\n");
		scanf("%d",&x);
		printf("Enter y =\n");
		scanf("%d",&y);
	}
	else if ((Op==10)||(Op==7)||(Op==11))
	{
		printf("Enter x =\n");
		scanf("%d",&x);
	}
	else{
		printf("Error Operation");
	}
	switch(Op)
	{
		case 1:
			z = *(sum_number(&x ,&y));
			printf("x+y= %d \n", z);
			break;
		case 2:
			z = *(sub_number(&x ,&y));
			printf("x-y= %d \n", z);
			break;
		case 3:
			z = *(mul_number(&x ,&y));
			printf("x*y= %d \n", z);
			break;
		case 4:
			z = *(div_number(&x ,&y));
			printf("x/y= %d \n", z);
			break;
		case 5:
			z = *(and_number(&x ,&y));
			printf("x&y= %d \n", z);
			break;
		case 6:
			z = *(or_number(&x ,&y));
			printf("x|y= %d \n", z);
			break;
		case 7:
			z = *(not_number(&x));
			printf("!x= %d \n", z);
			break;
		case 8:
			z = *(xor_number(&x ,&y));
			printf("x^y= %d \n", z);
			break;
		case 9:
			z = *(Reminder_number(&x ,&y));
			printf("x%%y= %d \n", z);
			break;
		case 10:
			z = *(increment_number(&x));
			printf("(x++) =%d \n", z);
			break;
		case 11:
			z = *(decrement_number(&x));
			printf("(x--) =%d \n", z);
			break;
		default:
			break;
	}
    return 0;
}