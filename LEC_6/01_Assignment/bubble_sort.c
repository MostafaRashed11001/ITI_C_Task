#include <stdio.h>
#include "swap.h"
void bubble_sort(int *arr,int size);
int main ()
{
    int number =3;
    int arr[10]={2,10,11,3,4,1,0,6,9,8};
    int size= sizeof(arr)/sizeof(int);
    bubble_sort(arr,size);
    int middle= size/2;
    if(arr[middle]<number)
    {
        for(int h=middle;h<10;h++)
        {
            if(arr[h]==number)
            {
                printf("the location of number is:%d",h);
            }
        }
    }
    else
    {
        for(int k=0;k<middle;k++)
        {
            if(arr[k]==number)
            {
                printf("the location of number is:%d",k);
            }
        }
    }
    return 0 ; 
}
void bubble_sort(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<(size-i);j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    for(int n=0;n<10;n++)
    {
        printf(" %d ,",arr[n]);
    }
}





