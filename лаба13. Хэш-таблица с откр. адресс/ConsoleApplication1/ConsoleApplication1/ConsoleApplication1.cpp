
#include "stdafx.h"
#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char *mas;
	AAA(int k, char*z)
	{
		key = k;  mas = z;
	} AAA() {}
};
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
void AAA_print(void* d)
{
	cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	AAA a1(1, "one"), a2(2, "two"), a3(4, "three"), a4(2, "fo");
	int siz = 10;
	cout << "������� ������ ���-�������" << endl;  cin >> siz;
	Object H = Create(siz, key);   //�������	
	int choise=0;  int k;
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;   cin >> choise;
		switch (choise)
		{
		case 0:  exit(0);
		case 1:  H.Scan(AAA_print);  break;
		case 2: {
					AAA *a = new AAA;  
					char *str = new char[20];
					cout << "������� ����" << endl;
					cin >> k;
					a->key = k; 
					cout << "������� ������" << endl;
					cin >> str; 
					a->mas = str;
					if (H.N == H.Size)  
						cout << "������� ���������" << endl;
					else 
						H.Insert(a);
					break; 
				}
		case 3: 
					cout << "������� ���� ��� ��������" << endl;  
					cin >> k;
					H.Delete(k); 
					break;
		case 4: 
					cout << "������� ���� ��� ������" << endl;
					cin >> k;
					if (H.Search(k) == NULL) 
						cout << "������� �� ������" << endl;
					else  
						AAA_print(H.Search(k));
					break;
		}
	}
	return 0;
}
