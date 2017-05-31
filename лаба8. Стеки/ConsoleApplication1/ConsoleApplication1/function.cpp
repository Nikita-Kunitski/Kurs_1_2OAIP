#include "stdafx.h"
#include "list.h"
#include <fstream>
#include <iostream>
using namespace std;

void push(int x, stack *MyStk)   //Добавление элемента х в стек	
{   stack* e = new stack;       //выделение памяти для нового элемента
    e->v = x;                             //запись элемента x в поле v 
    e->next = MyStk->head;  //перенос вершины на следующий элемент 
    MyStk->head = e;             //сдвиг вершины на позицию вперед
}

int pop(stack *MyStk)   //Извлечение (удаление) элемента из стека
{	   if (MyStk->head== NULL)
	  {	cout << "Стек пуст!" << endl;
		return -1;    //если стек пуст - возврат -1 
	  }
	   else
	  {	stack*e = MyStk->head;  //е - временная переменная для хранения адреса эле-мента
		int a = MyStk->head->v;   //запись значения из поля v в переменную a 
		MyStk->head = MyStk->head->next; //перенос вершины
		delete e;                             //удаление временной переменной
		return a;                            //возврат значения удаляемого элемента
	  }
}	
void show(stack *MyStk)    //Вывод стека
{	   stack* e = MyStk->head;  //объявляется указатель на вершину стека
      int a;
	   if (e == NULL)
		cout << "Стек пуст!" << endl;	
	   while (e!= NULL)
	   { 	a = e->v;                  //запись значения из поля v в переменную a 
		cout << a << " ";
		e = e->next;
	   }
	   cout << endl;
}

void clear(stack* MyStk)
{
	while (MyStk->head!=NULL)
	{
		stack *temp=MyStk->head->next;
		delete MyStk->head;
		MyStk->head=temp;
	}
}

void v_file(stack* MyStk)
{

fstream fp;
fp.open("a.txt");

	 stack* e = MyStk->head; 
      int a;
	   if (e == NULL)
		cout << "Стек пуст!" << endl;	
	   while (e!= NULL)
	   { 	a = e->v;  
		fp << a << " ";
		e = e->next;
	   }
	   cout << endl;

fp.close();
}

void prov(stack* MyStk)
{
	int a,b;
	stack* e=MyStk->head; 
while(e->next!=NULL)
{
	a=e->v;
	b=e->next->v;
	if(a==b)
		cout<<e->v<<" ";
	e=e->next;
}
}