#include "stdafx.h"
#include "list.h"
#include<iostream>
#include <fstream>
using namespace std;


void main()
{    setlocale(LC_ALL, "Rus");
	   int k;
	   stack *MyStk = new stack; //��������� ������ ��� �����
	   MyStk->head = NULL;       //������������� ������� ��������	
	   for (;;)
	   { 	cout<<"������ �� ������. �������� �������:" <<endl;
	          cout<<"1 - ���������� �������� � ����"<<endl;
	          cout<<"2 - ���������� �������� �� �����"<<endl;
	          cout<<"3 - ����� �����" << endl;
			  cout<<"4 - ������� �����" << endl;
			  cout<<"5 - ���� � ���� (a.txt)" << endl;
			  cout<<"6 - �������� �� ������� ����������� ���������"<<endl;
	          cout<<"0 - �����" << endl;		
	          cin >> k;
	          switch (k)
		{        case 1: cout<<"������� ������� ��� �������: "<<endl;
			             cin >> k;
			             push(k,MyStk);
						 cout<<endl;
						 break;
			case 2: k = pop(MyStk); 
                                    if(k != -1) cout <<"����������� �������: "<<k<<endl; cout<<endl; break;
			case 3: cout << "���� ����: " << endl;
			             show(MyStk); cout<<endl;  break;
			case 4:clear(MyStk);
				cout<<"\n ������� ������ ������� \n";
				cout<<endl;
				break;
			case 5:v_file(MyStk);break;
			case 6:prov(MyStk);break;
			case 0: return;break;
		 }
	  }	   
}
