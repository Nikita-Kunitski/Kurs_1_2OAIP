#include "stdafx.h"
#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::Print()
{
	std::cout << x;
}
int AAA::GetPriority() const
{
	return x;
}
namespace heap {
	//—оздаение кучи
	Heap Create(int maxsize, CMP(*f)(void*, void*)) {
		return *(new Heap(maxsize, f));
	}
	void Heap::Insert(void* x)
	{
		int i;
		if (!isFull()) {
			Storage[i = ++Size - 1] = (void*)x; //следующий  адрес равен указателю на переданные данные
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))
			{
				Swap(Parent(i), i);	i = Parent(i);					
			}
		}
	}
	int Heap::Left(int cur)
	{
		return (2 * cur + 1 >= Size) ? -1 : (2 * cur + 1);    //формулы вычислени€ потомков и родител€
	}
	int Heap::Right(int cur) {
		return (2 * cur + 2 >= Size) ? -1 : (2 * cur + 2);
	}
	int Heap::Parent(int cur) {
		return (cur + 1) / 2 - 1;
	}
	void Heap::Swap(int i, int j)//перестановка двух элементов массива указателей
	{
		void* buf = Storage[i];
		Storage[i] = Storage[j];
		Storage[j] = buf;
	}
	void Heap::Heapify(int cur)
	{
		int left_cur = Left(cur), right_cur = Right(cur), irl = cur;
		if (left_cur > 0)
		{
			if (isGreat(Storage[left_cur], Storage[cur]))     irl = left_cur; 
			if (right_cur > 0 && isGreat(Storage[right_cur], Storage[irl]))   irl = right_cur; 
			if (irl != cur) {      
				Swap(cur, irl);	
				Heapify(irl);  			}
		}
	}

	void* Heap::ExtractMax()//удаление максимального
	{
		void* rc = NULL;
		if (!isEmpty())
		{
			rc = Storage[0];
			Storage[0] = Storage[Size - 1];
			Size--;
			Heapify(0);
		}
		return rc;
	}
	void* Heap::ExtractMin() //удаление минимального
	{
		void* buf = NULL;
		if (!isEmpty()) {
			buf = Storage[Size];
			Storage[Size] = Storage[Size - 1];
			Size--;
			Heapify(0);
		}
		return buf;
	}
	void* Heap::ExtractI(int num) { //удаление по номеру
		void* buf = NULL;
		if (!isEmpty()) {
			buf = Storage[num];
			Storage[num] = Storage[Size - 1];
			Size--;
			Heapify(0);
		}
		return buf;
	}
	void Heap::Scan(int i) const  //¬ывод значений элементов на экран
	{
		int probel = 20;	std::cout << '\n';
		if (Size == 0)   std::cout << " уча пуста";
		for (int u = 0, y = 0; u < Size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)Storage[u])->Print();
			if (u == y) { std::cout << '\n';   if (y == 0)  y = 2;  else  y += y * 2; }
			probel /= 2;
		}
		std::cout << '\n';
	}

	void Heap::DeleteHeap()
	{
		if (!isEmpty())
		{
			Size = 0;
			this->~Heap();	//очистка кучи через деструктор
		}
	}
	void Heap::Union(heap::Heap h) {
		int i = 0;
		while (h.Size) {
			Insert(h.ExtractMax());
		}
		h.DeleteHeap();
	}
}
