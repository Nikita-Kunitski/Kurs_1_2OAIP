#include "stdafx.h"
#include "list.h"
#include<iostream>
#include <fstream>
using namespace std;


void main()
{    setlocale(LC_ALL, "Rus");
	   int k;
	   stack *MyStk = new stack; //выделение памяти для стека
	   MyStk->head = NULL;       //инициализация первого элемента	
	   for (;;)
	   { 	cout<<"Работа со стеком. Выберите команду:" <<endl;
	          cout<<"1 - Добавление элемента в стек"<<endl;
	          cout<<"2 - Извлечение элемента из стека"<<endl;
	          cout<<"3 - Вывод стека" << endl;
			  cout<<"4 - Очистка стека" << endl;
			  cout<<"5 - Ввод в файл (a.txt)" << endl;
			  cout<<"6 - Проверка на наличее совпадающих элементов"<<endl;
	          cout<<"0 - Выход" << endl;		
	          cin >> k;
	          switch (k)
		{        case 1: cout<<"Введите элемент для вставки: "<<endl;
			             cin >> k;
			             push(k,MyStk);
						 cout<<endl;
						 break;
			case 2: k = pop(MyStk); 
                                    if(k != -1) cout <<"Извлеченный элемент: "<<k<<endl; cout<<endl; break;
			case 3: cout << "Весь стек: " << endl;
			             show(MyStk); cout<<endl;  break;
			case 4:clear(MyStk);
				cout<<"\n Очистка прошла успешно \n";
				cout<<endl;
				break;
			case 5:v_file(MyStk);break;
			case 6:prov(MyStk);break;
			case 0: return;break;
		 }
	  }	   
}
