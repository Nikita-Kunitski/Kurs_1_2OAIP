#include "stdafx.h"    //������ �������
const int N = 4; 
struct Queue
{ 	int data[N];//������ ������
	int last;           //��������� �� ������
};

void Creation(Queue *Q);
bool Full(Queue *Q);
void Add(Queue *Q);
void Delete(Queue *Q) ;
int Top(Queue *Q);
int Size(Queue *Q);
void vivod(Queue *Q);
void revers(Queue *Q);