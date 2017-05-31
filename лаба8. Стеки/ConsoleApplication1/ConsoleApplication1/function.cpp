#include "stdafx.h"
#include "list.h"
#include <fstream>
#include <iostream>
using namespace std;

void push(int x, stack *MyStk)   //���������� �������� � � ����	
{   stack* e = new stack;       //��������� ������ ��� ������ ��������
    e->v = x;                             //������ �������� x � ���� v 
    e->next = MyStk->head;  //������� ������� �� ��������� ������� 
    MyStk->head = e;             //����� ������� �� ������� ������
}

int pop(stack *MyStk)   //���������� (��������) �������� �� �����
{	   if (MyStk->head== NULL)
	  {	cout << "���� ����!" << endl;
		return -1;    //���� ���� ���� - ������� -1 
	  }
	   else
	  {	stack*e = MyStk->head;  //� - ��������� ���������� ��� �������� ������ ���-�����
		int a = MyStk->head->v;   //������ �������� �� ���� v � ���������� a 
		MyStk->head = MyStk->head->next; //������� �������
		delete e;                             //�������� ��������� ����������
		return a;                            //������� �������� ���������� ��������
	  }
}	
void show(stack *MyStk)    //����� �����
{	   stack* e = MyStk->head;  //����������� ��������� �� ������� �����
      int a;
	   if (e == NULL)
		cout << "���� ����!" << endl;	
	   while (e!= NULL)
	   { 	a = e->v;                  //������ �������� �� ���� v � ���������� a 
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
		cout << "���� ����!" << endl;	
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