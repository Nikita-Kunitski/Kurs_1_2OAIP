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
	{	cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ������� ������� �������" << endl;
		cout << "4. ������ ������ �������" << endl;
		cout << "5. �������� �������" << endl;
		cout << "6. ������ �������" << endl;
		cout << "0. �����\n\n";
		cout << "����� ������� > "; cin >> number;
		switch (number)
		{     case 1:  Add(&Q); break;
		       case 2:  if (Full(&Q)) cout << endl << "������� �����\n\n";
			             else
	             {      Delete(&Q);
		           cout << endl << "������� ������ �� �������\n\n";
		    } break;
	        case 3:  if (Full(&Q)) cout << endl << "������� �����\n\n";
			   else cout << "\n��������� �������: " << Top(&Q) << "\n\n";
			   break;
	        case 4:  if (Full(&Q)) cout << endl << "������� �����\n\n";
			   else cout << "\n������ �������: " << Size(&Q) << "\n\n";
			   break;
			   case 5:  vivod(&Q); break;
				   case 6:  revers(&Q); break;
	       case 0:   break;
	       default:   cout << endl << "������� �� ����������\n\n"; 
			   break;
	}
	} while (number != 0);
}
