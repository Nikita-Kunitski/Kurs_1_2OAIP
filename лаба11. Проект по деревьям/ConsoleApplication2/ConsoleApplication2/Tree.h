#include "stdafx.h"
#include <iostream>
namespace btree   
{
	enum CMP
          { 
			  LESS = -1, EQUAL = 0,   GREAT = 1     
	};  
struct Node                 //Узел бинарного списка 
{       
	Node* Parent;            // указатель на родителя  
	Node* Left;                 // указатель на левую ветвь
	Node* Right;               // указатель на правую ветвь
	void* Data;                  //  данные    
	Node(Node* p, Node* l, Node* r, void* d) // конструктор
	{      Parent = p; Left  =  l; Right =  r; Data  =  d;    }
	Node* Next();              // следующий по ключу
	Node* Prev();              // предыдущий по ключу
	Node* Min();               // минимум в поддереве
	Node* Max();               // максимум в поддереве  
	void ScanDown(void (*f)(void* n));    // обход поддерева сверху  вниз     
	void Scan(int (*f)(void* n));    
	void ScanLevel(void (*f)(void* n), int );
	int GetLevel();
	void Vyvod (void (*f)(void* n), int l);  //Вывод на экран
	void obxod_smesh(void (*f)(void* n));//смешанный обход
	void obxod_niz(void (*f)(void* n));//нисходящий обход
	void ScanByLevel(void (*f)(void* n));   
};  
struct Object               // Интерфейс бинарного дерева 
{         Node* Root;             // указатель на корень
CMP (*Compare)(void*, void*);   // функция сравнения	
Object(CMP (*f)(void*, void*))
{      Root = NULL;      Compare = f;      };  
Node* Max()  {     return Root->Max();     };
Node* Min()   {     return Root->Min();      };
bool isLess(void* x1, void* x2)
const    {       return Compare(x1, x2)  == LESS;     };   
bool isGreat(void* x1, void* x2)
const    {        return Compare(x1, x2) == GREAT;  };
bool isEqual(void* x1, void* x2)
const    {       return Compare(x1, x2) == EQUAL;    };
bool Insert(void* data);                     // добавить элемент
Node* Search(void* d, Node* n );    // найти по ключу
Node* Search(void* d)    {     return Search(d, Root);    }; 
bool Delete(Node* e);                         // удалить по адресу элемента 
bool Delete(void* data)
{     return Delete(Search(data));     }; //удалить по ключу
void ScanDown(void (*f)(void* n))
{     Root->ScanDown(f);     };               // обход дерева   	
btree::Object BuildTree(char *);
void SaveToFile(void *);
void SaveTree(btree::Object tree, char *); 
           };  
Object Create(CMP (*f)(void*, void*));                          // Создать бинарное дерево    
         };
