
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
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	AAA a1(1, "one"), a2(2, "two"), a3(4, "three"), a4(2, "fo");
	int siz = 10;
	cout << "Введите размер хэш-таблицы" << endl;  cin >> siz;
	Object H = Create(siz, key);   //создать	
	int choise=0;  int k;
	for (;;)
	{
		cout << "1 - вывод хэш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choise;
		switch (choise)
		{
		case 0:  exit(0);
		case 1:  H.Scan(AAA_print);  break;
		case 2: {
					AAA *a = new AAA;  
					char *str = new char[20];
					cout << "введите ключ" << endl;
					cin >> k;
					a->key = k; 
					cout << "введите строку" << endl;
					cin >> str; 
					a->mas = str;
					if (H.N == H.Size)  
						cout << "Таблица заполнена" << endl;
					else 
						H.Insert(a);
					break; 
				}
		case 3: 
					cout << "введите ключ для удаления" << endl;  
					cin >> k;
					H.Delete(k); 
					break;
		case 4: 
					cout << "введите ключ для поиска" << endl;
					cin >> k;
					if (H.Search(k) == NULL) 
						cout << "Элемент не найден" << endl;
					else  
						AAA_print(H.Search(k));
					break;
		}
	}
	return 0;
}
