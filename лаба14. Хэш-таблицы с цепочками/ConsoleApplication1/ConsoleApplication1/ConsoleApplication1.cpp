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
	cout<<"������ ������ ���-�������"<<endl;   cin>>current_size;
	hashTC::Object H = hashTC::Create(current_size, hf);	
	int choise;  int k; 
	for(;;)
{   
	cout<<"1 - ����� ���-�������"<<endl;
	cout<<"2 - ���������� ��������"<<endl;
	cout<<"3 - �������� ��������"<<endl;
	cout<<"4 - ����� ��������"<<endl;
	cout<<"0 - �����"<<endl;
	cout<<"�������� �����"<<endl; 
	cin>>choise;
switch(choise)
{    
		case 0:  exit(0);
		case 1:  H.Scan(); break;
		case 2: { 
				AAA *a = new AAA; 
				char *str = new char [20];
				cout<<"������� ����"<<endl;  
				cin>>k;
				a->key = k;   
				cout<<"������� ������"<<endl;
				cin>>str;   
				a->mas = str;   
				H.Insert(a);    
				break;
				}
		case 3: { AAA *b = new AAA; 
				 cout<<"������� ����"<<endl;
				cin>>k;
				b->key = k;
				H.Delete(b);   
				break;
				}
		case 4: { AAA *c = new AAA; 
				cout<<"������� ����"<<endl;
				cin>>k;
				c->key = k;				
					  if (H.Search(c) == NULL) 
						  cout<<"������� �� ������"<<endl;
					  else {
							 cout<<"������ ������� � ������ ������"<<endl;
							 AAA_print(H.Search(c));
							 cout<<endl;    
							}  
					  break;   
				}
}
          }
          return 0;
}
