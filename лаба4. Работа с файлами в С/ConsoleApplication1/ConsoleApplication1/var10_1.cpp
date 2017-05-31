#include <iostream>
#include<stdio.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE,"Rus");
	FILE *file;
	int A[30];
	int i=0,j=0, ind;//b- eto "x" po usloviu, sr1- sredn arifm 1 i 2 chisla, sr- sravnenie v cikle, ind- index
int razn1, b, razn;
	file=fopen("a.bin","r");
	while(!feof(file))
	{
		fscanf(file,"%d",&A[i]);
		i++;
		
	}
	fclose (file);
	i=i-1;
	for(j=0;j<i;j++)
	{
		printf("%d ",A[j]);
	}
	printf("\n");
	b=A[0];
	razn1=b-((A[1]+A[2])/2);
	for(j=3;j<=i;j++)
	{
		if(j==i)
			break;
		razn=b-(A[j]+A[j+1])/2;
		if(razn<razn1)//peresmotret
		{
		ind=j;
		razn1=razn;
		}
	}
	
cout<<"Среднее арифметическое чисел А["<<ind<<"]="<< A[ind]<<" и А["<<ind+1<<"]="<< A[ind+1]<<" максимально приближено к "<<b<<endl;
	
}