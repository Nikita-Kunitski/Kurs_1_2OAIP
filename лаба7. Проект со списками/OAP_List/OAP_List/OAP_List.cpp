// OAP_List.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;
struct Person
{    char marka[20];  
	char cvet[20];
      int nomer; 
	  int god;
	  char vladelec[20];

      Person *next;  
 };

Object L1 = Create();  

void FindMax()//����� ������ �������� ����������
{
	Element* e=L1.GetFirst();
	Person* aa;
  int j=0,i=0,b[5];
  int min=0,sch;
  while (e!=NULL)
  {
	 aa=(Person*)e->Data;
	b[i]=aa->god;
	
	i++;
	e=e->GetNext();
  }
  for(j=0;j<i;j++)
  {
	if(b[j]>min)
	{
		min=b[j];
		sch=j;
	}
  }
  e=L1.GetFirst();
  for(j=0;j<=sch;j++)
  {
	  aa=(Person*)e->Data;
	  e=e->GetNext();
  }
  cout<<aa->marka<<" "<<aa->nomer<<" "<<aa->cvet<<" "<<aa->god<<" "<<aa->vladelec<<" "<<endl;
}          

void f (void* b)                       //������� ������������ ��� ������ 
{      Person *a = (Person*)b;
cout<<a->marka<<"  "<<a->nomer<<"  "<<a->cvet<<"  "<<a->god<<"  "<<a->vladelec<<endl;  
}  


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
     Person a1 = {"����", "�������",205412,1998,"��������"}; 
	 Person a2 = {"�����������","�����", 255487,2000,"�������"};  
     Person a3 = {"������","������", 255577,2010,"����"};
	 Person a4 = {"�������","������", 875487,2007,"������"};  
	 Person a5 = {"���","�����", 258987,2005,"�����"};  
     Person* aa;
     int lic;
	 do{
		 cout<<"\n1 - ���� ������ � ������\n";
		 cout<<"2 - ����� ������ �� �������\n";
		 cout<<"3 - ������� ��������� ������\n";
		 cout<<"4 - �������� ������\n";
		 cout<<"5 - �������� �� ������\n";
		 cout<<"6 - ����� ������ �������� ����������\n";
		 cout<<"0 - �����\n";
			cin>>lic;
			switch(lic)
			{
			case 1:
				 L1.Insert(&a1);
				 L1.Insert(&a2);
				 L1.Insert(&a3);
				 L1.Insert(&a4);
				 L1.Insert(&a5);
				 break;
			case 2:     L1.PrintList(f);  
				cout<<"----------------------------"<<endl;
				break;
			case 3: cout<<"���������� ��������� � ������ "<< L1.CountList();break;
			case 4:L1.DeleteList();break;
			case 5:cout<<"�������� 2 �������� ������ "<<L1.Delete(&a2);break;
			case 6:FindMax();
			}
	 }while(lic!=0);
     
	return 0;
}

