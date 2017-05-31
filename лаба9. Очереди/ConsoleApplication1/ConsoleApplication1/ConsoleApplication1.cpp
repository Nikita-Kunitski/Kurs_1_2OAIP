#include "stdafx.h"
#include "list.h"
#include <iostream>
using namespace std;


void main() 
{	setlocale(LC_ALL, "Rus");
	Queue Q;
	Creation(&Q);
	int number;
	do
	{	cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести верхний элемент" << endl;
		cout << "4. Узнать размер очереди" << endl;
		cout << "5. Выввести очередь" << endl;
		cout << "6. Реверс очереди" << endl;
		cout << "0. Выйти\n\n";
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{     case 1:  Add(&Q); break;
		       case 2:  if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
			             else
	             {      Delete(&Q);
		           cout << endl << "Элемент удален из очереди\n\n";
		    } break;
	        case 3:  if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
			   else cout << "\nНачальный элемент: " << Top(&Q) << "\n\n";
			   break;
	        case 4:  if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
			   else cout << "\nРазмер очереди: " << Size(&Q) << "\n\n";
			   break;
			   case 5:  vivod(&Q); break;
				   case 6:  revers(&Q); break;
	       case 0:   break;
	       default:   cout << endl << "Команда не определена\n\n"; 
			   break;
	}
	} while (number != 0);
}
