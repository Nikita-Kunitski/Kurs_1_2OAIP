// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

void heapify (int *A, int pos, int n) 
{      int t, tm; 
        while (2*pos + 1 <  n) 
        {     
			t = 2 * pos + 1;
            if (2 * pos + 2 < n  &&  A[2 * pos + 2] >= A[t])      
				t = 2*pos + 2; 
                if (A[pos] < A[t])     
				{    
					tm = A[pos];  
					A[pos] = A[t];  
					A[t] = tm;   
					pos = t;   
				} 
                else break;  
         }  
  }

void PiramSort(int *A, int n)
{     for (int i = n - 1;  i >= 0;  i--)
              heapify(A, i, n);
       while(n>0)
       {     
		   int tm = A[0];  
		   A[0] = A[n - 1];  
		   A[n - 1] = tm;
           n--;  
		   heapify(A, 0, n);           
	   }
}

void Hoarasort(int* A,int first,int last)
{
	int i=first,j=last;
	int tmp, x=A[(first+last)/2];
	do{
		while(A[i]<x) 
			i++;
		while(A[j]>x)
			j--;
		if(i<=j)
		{
			if(i<j)
			{
				tmp=A[i];
				A[i]=A[j];
				A[j]=tmp;
			}
			i++;
			j--;
		}
	}while(i<=j);
	if(i<last)
		Hoarasort(A,i,last);
	if(first<j)
		Hoarasort(A,first,j);
}

void BubbleSort1(int *A, int N)   
{     int i, j, count, key;
       for (i = 0;  i < N;  i++)
       {      for (j = 0;  j < N - 1;  j++)
              {     key = j + 1;  count = A[key];  
                     if (A[j] > A[key])
                     {     A[key] = A[j];   A[j] = count;    }  
              }  
        }
       /*cout<<"Результирующий массив: ";
       for (i = 0;  i < N;  i++) cout<<A[i]<<" ";          */
}

void SelectSort2(int *A, int n)
{      int k, i, j;
        for ( i = 0;  i < n - 1;  i++)
        {     for (j = i + 1,  k = i;  j < n;  j++)     
                     if (A[j] < A[k])
						 k = j;                    
               int c = A[k];  
			   A[k] = A[i];
			   A[i] = c; 
         }
}        


int _tmain(int argc, _TCHAR* argv[])
{
	clock_t start,stop;
	setlocale(LC_ALL,"Rus");
	int kol, D; //kol - kolichetvo 
	cout<<"Введите размер массива: ";
	cin>>kol;
	int *A=new int[kol], *B=new int[kol], *C=new int[kol];
	srand((unsigned)time(NULL));
	//cout<<"A[i]:";
		for(int i(0); i<kol;i++)
			{
				A[i]=rand()%10000;
				B[i]=rand()%6000;
				cout<<A[i]<<" ";
			}
		cout<<endl;
/*			cout<<"B[i]:";
		for(int i(0); i<kol;i++)
			cout<<B[i]<<" ";*/

				int MAX_B=B[0],j=0;
				for(int i(0);i<kol;i++)
					if(B[i]>MAX_B)
						MAX_B=B[i];
				cout<<"C[i]: ";
				for(int i(0);i<kol;i++)
					if(A[i]>MAX_B)
					{
						C[j]=A[i];
						cout<<C[j]<<" ";
						j++;
					}
					cout<<endl;
					do{
					cout<<"\tМеню:";
					cout<<"\n1-Пирамидальная сортировка;";
					cout<<"\n2-Сортировка разделением(сортировка Хоара);";
					cout<<"\n3-Сортировка выбором;";
					cout<<"\n4-Сортировка пузырьком;";
					cout<<"\n5-Вывести массив;";
					cout<<"\n0-Выход;";
					cout<<"\nВыберите действие: ";
					cin>>D;
					switch(D)
					{

					case 1:start=clock();
							PiramSort(C,j);
							stop=clock();
							cout<<"\nПрошло секунд "<<(float(stop-start))/CLOCKS_PER_SEC<<endl;
							break;
					case 2: start=clock();
							Hoarasort(C,0,j-1);
							stop=clock();
							cout<<"\nПрошло секунд "<<(float(stop-start))/CLOCKS_PER_SEC<<endl;
							break;
					case 3:start=clock();
							SelectSort2(C,j);
							stop=clock();
							cout<<"\nПрошло секунд "<<(float(stop-start))/CLOCKS_PER_SEC<<endl;
							break;
					case 4: start=clock();
							BubbleSort1(C,j);
							stop=clock();
							cout<<"\nПрошло секунд "<<(float(stop-start))/CLOCKS_PER_SEC<<endl;
							break;
					case 5: for(int i=0;i<j;i++)
								cout<<C[i]<<" ";
						break;
					case 0:exit(0);
					}
					}while(D!=0);
	return 0;
}

