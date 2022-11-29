#include<stdio.h>
//Sum
int* sum_number(int *py,int *px)
{
    int d=0;
    d = *py + *px;
    int *p = &d;
    return p;
}
//Main loop
int main()
{
	while(1)
	{
		int y=0,x=0;
		printf("Enter x =\n");
		scanf("%d",&x);
		printf("Enter y =\n");
		scanf("%d",&y);
		int z = *(sum_number(&y ,&x));
		printf("x+y= %d \n", z);
	}
	return 0;
}