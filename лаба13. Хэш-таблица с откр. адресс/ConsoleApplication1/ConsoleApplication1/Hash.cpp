#include "stdafx.h"
#include "Hash.h"
#include <iostream>
#include <math.h>
int HashFunction(int key, int size, int p)  //хэш-функция
{
	double A = (sqrt(5) - 1) / 2;
	int h=fmod(key*A,1)*size;
	//double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return h;	 //return ((int)(p+fmod(((key*(sqrt(5.0)-1))/2), 1)))%size;
}

Object Create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;  
	this->Size = size; 
		this->GetKey = getkey;  
		this->Data = new void*[size];
	for (int i = 0; i < size; ++i)
		Data[i] = NULL;
}
bool Object::Insert(void* d)
{
	bool b = false;
	if (N != Size)
		for (int i = 0, t = GetKey(d), j = HashFunction(t, Size, 0); i != Size && !b;
			j = HashFunction(j, Size, ++i))
			if (Data[j] == NULL || Data[j] == DEL)
			{ Data[j] = d;   N++;    b = true; }
			else{
				if(Data[j] != DEL||Data[j] != NULL)
				{
					while(Data[j]!=NULL)
						j++;
					Data[j]=d;
					N++;
					b=true;
				}
			}
	return b;
}
int Object::SearchInd(int key)
{
	int t = -1;  bool b = false;
	if (N != 0){
		for (int i = 0, j = HashFunction(key, Size, 0);	Data[j] != NULL && i != Size && !b;	j = HashFunction(key, Size, ++i))
		{
			if(Data[j]==DEL)
			{
				j++;
				while(GetKey(Data[j])!=key)
				{	j++;
					if (GetKey(Data[j]) == key)
					{
						t = j;
						b = true;
						return t;
					}
				}
			}
			if (Data[j] != DEL)
				if (GetKey(Data[j]) == key)
				{
					t = j;
					b = true;
				}
		}
	}
	return t;
}
void* Object::Search(int key)
{
	int t = SearchInd(key);
	return(t >= 0) ? (Data[t]) : (NULL);
}

void* Object::Delete(int key)
{
	int i = SearchInd(key);
	void* t = Data[i];
	if (t != NULL)
	{
		Data[i] = DEL;  N--;
	}
	return t;
}

bool Object::Delete(void* d)
{
	return(Delete(GetKey(d)) != NULL);
}
void Object::Scan(void(*f)(void*))
{
	for (int i = 0; i < this->Size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->Data)[i] == NULL)  
			std::cout << "  пусто" << std::endl;
		else  if ((this->Data)[i] == DEL) 
			std::cout << "  удален" << std::endl;
		else 
			f((this->Data)[i]);
	}
}