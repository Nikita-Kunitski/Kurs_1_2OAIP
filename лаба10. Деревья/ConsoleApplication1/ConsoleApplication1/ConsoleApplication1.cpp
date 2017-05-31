#include "stdafx.h"
#include <iostream>
#include "fstream"
#pragma warning(disable:4703)
#define TRUE 1
#define FALSE 0
int sch;

using namespace std;

struct  node
{      int Key;  
        int Count;  
        node *Left;  
        node *Right;  
 };
node *Tree;     //��������� �� ������ ������
node  *Res;      //��������� �� ��������� �������
int B;                //������� ���������� ������� � ������
fstream file;
node** GetTree() 
{  
	return &Tree;    
}

void Search (int x, node **p)    //����� ����� x
{       if (*p == NULL)   //*p - ��������� �� ������� 
        {       *p = new(node);  
                 (**p).Key = x;  
				 (**p).Count = 1;
                 (**p).Left = (**p).Right = NULL;  
         }
         else   if(x<(**p).Key)  
			 Search (x, &((**p).Left));
                  else   if  (x>(**p).Key)    Search (x, &((**p).Right));
                           else  (**p).Count += 1;
						   
 }

void BuildTree ()      //���������� ��������� ������
{      int el;
        cout<<"������� ����� ������ ������: (���� ��������� - 0)\n";     cin>>el;   
        while  (el != 0)
        {      Search (el, &Tree);    cin>>el;     }
}

void Vyvod (node **w, int l)  //����� �� �����
{      int i;
        if  (*w != NULL)            //*w - ��������� �� ������ 
                  {     Vyvod (&((**w).Right), l + 1);
                         for  (i = 1;  i <= l;  i++)  cout<<"   ";
                         cout<<(**w).Key<<endl;
                         Vyvod (&((**w).Left),  l  + 1); 
         }
}	

int Poisk (int k)        //����� ������� � ������ k 
{       node *p,*q; B = FALSE; p = Tree;
         if  (Tree != NULL)
         do
         {       q = p; 
                  if  ((*p).Key == k)    B = TRUE;
                  else  {   q = p;   if  (k < (*p).Key)  p = (*p).Left;   else  p = (*p).Right;    }   
          }  while  (!B  &&  p != NULL); 
         Res = q;
         return B;
}

void Addition (int k)    //���������� ����� k 
{        node *s;  Poisk (k);
if  (!B)
{      s = new(node);
        (*s).Key  = k;    (*s).Count = 1;
        (*s).Left = (*s).Right = NULL;
        if  (Tree == NULL)   Tree = s;
        else  if  (k<(*Res).Key)   (*Res).Left = s;
                else  (*Res).Right = s;    
}
else  (*Res).Count += 1;
}

void obxod(node*e)
{
	if(e!=NULL)
	{
		obxod(e->Left);
		file<<e->Key<<" ";
		obxod(e->Right);
	}
	
}

void obxod_niz(node *Tree)
{
	if(Tree!=NULL)
	{
		cout<<Tree->Key<<" ";
		obxod_niz(Tree->Left);
		obxod_niz(Tree->Right);
	}
	cout<<endl;
}

void obxod_vosx(node *Tree)
{
	if(Tree->Left!=NULL)
		obxod_vosx(Tree->Left);
	if(Tree->Right!=NULL)
		obxod_vosx(Tree->Right);
	cout<<Tree->Key<<" ";
}

void main ()
{         setlocale (LC_CTYPE, "Russian");
int el;  

do{
	cout<<"1-������� ������\n";
	cout<<"2-����� ������� � ������\n";
	cout<<"3-���� ����� ����������� �������\n";
	cout<<"4-������ � ���� � ������� �����������\n";
	cout<<"5-���������� �����\n";
	cout<<"6-���������� �����\n";
	cout<<"0-�����\n";
		cin>>sch;
		switch (sch)
		{
		case 0:break;
		case 1:BuildTree ();
			Vyvod(&Tree, 0);
			break;
		case 2: cout<<"\n������� ������� ������� ����� �����: ";
				cin>>el;
				if  (Poisk (el))   cout<<"� ������ ���� ����� �������!\n";
				else     cout<<"� ������ ��� ����� �������!\n";
				break;
		case 3: cout<<"������� ���� ����������� �������: ";
				cin>>el;
				Addition (el);  
				Vyvod (GetTree(), 0);
				break;
		case 4:file.open("file.txt");
			obxod(Tree);
			file.close();break;
		case 5: obxod_niz(Tree);break;
		case 6:obxod_vosx(Tree); cout<<endl; 
			break;
		}
}while(sch!=0);

}
