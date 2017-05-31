#pragma once
#define HASHDEL (void*) -1
struct Object
{
	void** Data; 	Object(int, int(*)(void*));
	int Size;  int N;
	int(*GetKey)(void*); 	   bool Insert(void*);
	int SearchInd(int key); 	   void* Search(int key);
	void* Delete(int key);       bool Delete(void*);
	void Scan(void(*f)(void*));
};
static void* DEL = (void*)HASHDEL;
Object Create(int size, int(*getkey)(void*));
#undef HASHDEL
