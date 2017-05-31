#include "stdafx.h"
#include "list.h"
#include <iostream>
using namespace std;
void Creation(Queue *Q)   //Создание очереди Q
{  	Q->last = 0;
}

void revers(Queue *Q)
{
 int rev[N], i=0,j=0;
 for(j=Q->last-1;j>=0;j--,i++)
 {
	 rev[i]=Q->data[j];
	 cout<<rev[i]<<" ";
 }
 cout<<endl;
}

bool Full(Queue *Q)   //Проверка очереди на пустоту
{	if (Q->last == 0) return true;
	else return false;
}

void vivod(Queue *Q)
{
	int i=0;
	for(i;i<Q->last;i++)
		cout<<Q->data[i]<<" ";
	cout<<endl;
}

void Add(Queue *Q)   //Добавление элемента
{	if (Q->last == N)
	{	cout << "\nОчередь заполнена\n\n";   return;    }
	int value;
	cout << "\nЗначение > ";
	cin >> value;
	Q->data[Q->last++] = value;
	cout << endl << "Элемент добавлен в очередь\n\n";
}
void Delete(Queue *Q)    //Удаление элемента
{	for (int i = 0;   i<Q->last  &&  i < N;   i++)    //смещение элементов
		Q->data[i] = Q->data[i + 1];   
          Q->last--;
}
int Top(Queue *Q)     //Вывод начального элемента
{	return Q->data[0];
}
int Size(Queue *Q)    //Размер очереди
{	return Q->last;
}
