#include "stdafx.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;
heap::CMP cmpAAA(void*  a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP     rc = heap::EQUAL;
	if (A1->x  >  A2->x)   rc = heap::GREAT;
	else if (A2->x  > A1->x)  rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
bool BuildHeap(char *FileName, heap::Heap& h)      // ���������� ���� �� �����
{
	bool rc = true;   int n;
	ifstream inFile;
	inFile.open(FileName, std::ios::out);
	if (!inFile)
	{
		cout << "���������� ������� ����" << endl;  exit(1);
	}
	while (inFile >> n)
	{
		int *a = new int;
		*a = n;    h.Insert((void*)a);
	}
	inFile.close(); return rc;
}
int getnum() {
	int k;
	std::cout << "������� �����" << std::endl;
	std::cin >> k;
	return k;
}
void SaveHeap(heap::Heap &h, char *FileName) // ������� ������ � ����
{
	ofstream  outFile(FileName, ios_base::out | ios_base::trunc);
	if (!outFile)
	{
		cout << "������ �������� ��������� �����" << std::endl;
		return;
	}
	int *a = new int;
	for (int u = 0, y = 0; u < h.Size; u++)
	{
		a = (int*)h.Storage[u];
		outFile << *a;
		outFile << endl;
	}
	outFile.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int k;	int choise;  heap::Heap h1 = heap::Create(30, cmpAAA);
	heap::Heap h2 = heap::Create(30, cmpAAA);
	for (;;)
	{
		//system("cls");
		cout << "1. ����� ���� �� �����" << endl;
		cout << "2. �������� �������" << endl;
		cout << "3. ������� ������������ �������" << endl;
		cout << "4. �������� ����" << endl;
		cout << "5. ��������� � ����" << endl;
		cout << "6. ��������� �� �����" << endl;
		cout << "7. ������� ����������� �������" << endl;
		cout << "8. �������  �������" << endl;
		cout << "9. ����������� ���� ���" << endl;
		cout << "10. ���������� �������� �� ������ ����" << endl;

		cout << "0 - �����" << endl;
		cout << "�������� ����� : ";  cin >> choise;
		switch (choise)
		{
		case 0:  exit(0);
		case 1:  h1.Scan(0);   break;
		case 2: {AAA *a = new AAA; cout << "������� ����" << endl;    cin >> k;
			a->x = k;	 h1.Insert(a);   break; }
		case 3:   h1.ExtractMax();   break;
		case 4:   h1.DeleteHeap();    break;
		case 5:   SaveHeap(h1, "G.txt");    break;
		case 6:   h1.DeleteHeap(); BuildHeap( "G.txt", h1); break;
		case 7:   h1.ExtractMin(); break;
		case 8:   h1.ExtractI(getnum()); break;
		case 9:  h1.Union(h2); break;
		case 10: {AAA *a = new AAA; cout << "������� ����" << endl;    cin >> k;
			a->x = k;	 h2.Insert(a);   break; }

			BuildHeap("G.txt", h1); break;
		default:  cout << endl << "������� �������� �������!" << endl;
		}
	} return 0;
}
