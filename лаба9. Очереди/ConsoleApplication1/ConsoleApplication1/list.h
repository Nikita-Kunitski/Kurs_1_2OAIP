#include "stdafx.h"    //размер очереди
const int N = 4; 
struct Queue
{ 	int data[N];//массив данных
	int last;           //указатель на начало
};

void Creation(Queue *Q);
bool Full(Queue *Q);
void Add(Queue *Q);
void Delete(Queue *Q) ;
int Top(Queue *Q);
int Size(Queue *Q);
void vivod(Queue *Q);
void revers(Queue *Q);