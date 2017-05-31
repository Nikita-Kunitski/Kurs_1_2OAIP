// OAP_List.cpp: определяет точку входа для консольного приложения.
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

void FindMax()//поиск самого молодого автомобиля
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

void f (void* b)                       //функция используется при выводе 
{      Person *a = (Person*)b;
cout<<a->marka<<"  "<<a->nomer<<"  "<<a->cvet<<"  "<<a->god<<"  "<<a->vladelec<<endl;  
}  


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
     Person a1 = {"Ауди", "Красный",205412,1998,"Владимир"}; 
	 Person a2 = {"Вольксваген","Серый", 255487,2000,"Николай"};  
     Person a3 = {"Вольво","Желытй", 255577,2010,"Петр"};
	 Person a4 = {"Ситроен","Черный", 875487,2007,"Никита"};  
	 Person a5 = {"БМВ","Белый", 258987,2005,"Антон"};  
     Person* aa;
     int lic;
	 do{
		 cout<<"\n1 - Ввод данных в список\n";
		 cout<<"2 - Вывод списка на консоль\n";
		 cout<<"3 - Подсчет элементов списка\n";
		 cout<<"4 - Удаление списка\n";
		 cout<<"5 - Удаление по ссылке\n";
		 cout<<"6 - Поиск самого молодого автомобиля\n";
		 cout<<"0 - Выход\n";
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
			case 3: cout<<"Количество элементов в списке "<< L1.CountList();break;
			case 4:L1.DeleteList();break;
			case 5:cout<<"Удаление 2 элемента списка "<<L1.Delete(&a2);break;
			case 6:FindMax();
			}
	 }while(lic!=0);
     
	return 0;
}

