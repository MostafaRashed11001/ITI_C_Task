#include <stdio.h>
int main ()
{
	int x=2,y=4,z=6;
	void *temp=NULL;
	int *p=&x;
	int *q=&y;
	int *r=&z;
	printf("x = %d \n",x );
	printf("y = %d \n",y );
	printf("z = %d \n",z );
	printf("p = %d \n",p );
	printf("q = %d \n",q );
	printf("r = %d \n",r );
	printf("*p= %d \n",*p);
	printf("*q= %d \n",*q);
	printf("*r= %d \n",*r);
	printf("Swapping Pointer : \n");
	temp=r;
	r=p;
	p=q;
	q=temp;
	printf("x = %d \n",x );
	printf("y = %d \n",y );
	printf("z = %d \n",z );
	printf("p = %d \n",p );
	printf("q = %d \n",q );
	printf("r = %d \n",r );
	printf("*p= %d \n",*p);
	printf("*q= %d \n",*q);
	printf("*r= %d \n",*r);
	return 0;
}