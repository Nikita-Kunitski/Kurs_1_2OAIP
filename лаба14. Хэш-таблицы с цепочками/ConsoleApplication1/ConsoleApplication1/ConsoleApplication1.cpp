#include "stdafx.h"
#include "Hash_Twin_Chain.h"
#include <iostream>
using namespace std;
struct AAA
{  
	int key; 
    char *mas; 
    AAA(int k, char*z)
        {
			key = k;   
			mas = z;   
		} 
        AAA()
        {    
			key = 0;   
			mas = "";   
		}
};

	int hf(void* d)
	{
		AAA* f = (AAA*)d;
		return f->key; 
	}

		void AAA_print(listx::Element* e)
		{ 
			std::cout<<((AAA*)e->Data)->key<<'-'<<((AAA*)e->Data)->mas<<" / ";
		}

int _tmain(int argc, _TCHAR* argv[])
{     
	setlocale(LC_ALL, "rus");    
	int current_size =7;	
	cout<<"Ведите размер хэш-таблицы"<<endl;   cin>>current_size;
	hashTC::Object H = hashTC::Create(current_size, hf);	
	int choise;  int k; 
	for(;;)
{   
	cout<<"1 - вывод хэш-таблицы"<<endl;
	cout<<"2 - добавление элемента"<<endl;
	cout<<"3 - удаление элемента"<<endl;
	cout<<"4 - поиск элемента"<<endl;
	cout<<"0 - выход"<<endl;
	cout<<"сделайте выбор"<<endl; 
	cin>>choise;
switch(choise)
{    
		case 0:  exit(0);
		case 1:  H.Scan(); break;
		case 2: { 
				AAA *a = new AAA; 
				char *str = new char [20];
				cout<<"введите ключ"<<endl;  
				cin>>k;
				a->key = k;   
				cout<<"введите строку"<<endl;
				cin>>str;   
				a->mas = str;   
				H.Insert(a);    
				break;
				}
		case 3: { AAA *b = new AAA; 
				 cout<<"введите ключ"<<endl;
				cin>>k;
				b->key = k;
				H.Delete(b);   
				break;
				}
		case 4: { AAA *c = new AAA; 
				cout<<"введите ключ"<<endl;
				cin>>k;
				c->key = k;				
					  if (H.Search(c) == NULL) 
						  cout<<"Элемент не найден"<<endl;
					  else {
							 cout<<"Первый элемент с данным ключом"<<endl;
							 AAA_print(H.Search(c));
							 cout<<endl;    
							}  
					  break;   
				}
}
          }
          return 0;
}
