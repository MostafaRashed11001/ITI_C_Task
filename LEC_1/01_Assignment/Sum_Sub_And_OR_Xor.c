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
//Main loop
int main(){
    int y=0,x=0;
	printf("Enter x =\n");
	scanf("%d",&x);
	printf("Enter y =\n");
	scanf("%d",&y);
    int z = *(sum_number(&y ,&x));
    printf("x+y= %d \n", z);
	z = *(sub_number(&y ,&x));
    printf("x-y= %d \n", z);
	z = *(and_number(&y ,&x));
    printf("x&y= %d \n", z);
	z = *(or_number(&y ,&x));
    printf("x|y= %d \n", z);
	z = *(xor_number(&y ,&x));
    printf("x^y= %d \n", z);
    return 0;
}