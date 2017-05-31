#pragma once
struct AAA {  // информация об  элементах кучи
	int x;		 // приоритет
	void Print(); //вывод 
	int GetPriority() const;
};
namespace heap
{
	enum CMP    
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap // структура кучи 
	{
		int Size;  
		int MaxSize; 

		void** Storage; //ссылка на хранилище

		CMP(*Compare)(void*, void*); //сравнение двух элементов 

		Heap(int maxsize, CMP(*f)(void*, void*))//конструктор кучи
		{
			Size = 0;    //Размер кучи
			Storage = new void *[MaxSize = maxsize]; 
			Compare = f;
		};

		Heap(int maxsize, CMP(*f)(void*, void*), void* x[])//конструктор кучи
		{
			Size = 0;
			Storage = x;	
			MaxSize = maxsize;
			Compare = f;
		};
		int Left(int ix);  
		int Right(int ix);	
		int Parent(int ix);  
		bool isFull() const {
			return (Size >= MaxSize);
		};// проверка на переполнение
		bool isEmpty() const {
			return (Size <= 0);
		};//проверка на пустоту
		bool isLess(void* x1, void * x2) const {
			return Compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2) const {
			return Compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2) const {
			return Compare(x1, x2) == EQUAL;
		};
		void Swap(int i, int j);//Перестановка 2 элементов 
		void Heapify(int ix);
		void Insert(void* x); //ввод элемента
		void* ExtractMax();//удаление максимального
		void* ExtractMin();//удаление минимального
		void* ExtractI(int num); //удаление элемента по номеру 
		void DeleteHeap();		//очистка кучи	
		void Scan(int i) const;// вывод кучи
		void outMas();// выводит элементы кучи по порядку
		void Union(heap::Heap h);
	};

	Heap Create(int maxsize, CMP(*f)(void*, void*));
};
