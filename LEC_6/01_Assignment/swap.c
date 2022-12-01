#include "swap.h"
#include <stdio.h>
void swap(int *a,int *b) 
{
    int temp = *a; 
    *a = *b ; 
    *b = temp ;
    //printf("a=%d \n b=%d",*a,*b);
}