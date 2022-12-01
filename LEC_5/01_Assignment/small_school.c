#include<stdio.h>
//main loop
int main()
{
	float pass_student=0,failed_student=0,Highest_grade=0,Lowest_grade=100,Average_grade=0;
	float class_1[10]={20,40,50,60,65,87,98,98,10,78};
	float class_2[10]={90,87,98,56,45,32,45,12,34,98};
	float class_3[10]={32,43,54,65,76,87,98,23,12,42};
	for(int i=0;i<10;i++)
	{
		Average_grade+=(class_1[i]+class_2[i]+class_3[i]);
		//class_1
		if(class_1[i]>=50)
		{
			pass_student++;
		}
		else if(class_1[i]<50)
		{
			failed_student++;
		}
		//
		if (Highest_grade<class_1[i])
		{
			Highest_grade=class_1[i];
		}
		if(Lowest_grade>class_1[i])
		{
			Lowest_grade=class_1[i];
		}
		//class_2
		if(class_2[i]>=50)
		{
			pass_student++;
		}
		else if(class_2[i]<50)
		{
			failed_student++;
		}
		//
		if (Highest_grade<class_2[i])
		{
			Highest_grade=class_2[i];
		}
		if(Lowest_grade>class_2[i])
		{
			Lowest_grade=class_2[i];
		}
		//class_3
		if(class_3[i]>=50)
		{
			pass_student++;
		}
		else if(class_3[i]<50)
		{
			failed_student++;
		}
		//
		if (Highest_grade<class_3[i])
		{
			Highest_grade=class_3[i];
		}
		if(Lowest_grade>class_3[i])
		{
			Lowest_grade=class_3[i];
		}
	}
	Average_grade/=30;
	printf("Number of passed students =%d \n",pass_student);
	printf("Number of Failed students =%d \n",failed_student);
	printf("Highest grade             =%d \n",Highest_grade);
	printf("Lowest grade              =%d \n",Lowest_grade);
	printf("Average grade             =%d \n",Average_grade);
	return 0;
}