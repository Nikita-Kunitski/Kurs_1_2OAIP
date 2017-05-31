struct stack
{	     int v;                         //информационный элемент
	     stack *head, *next; //вершина стека и указатель на следующий элемент
};
void push(int x, stack *MyStk);
int pop(stack *MyStk);
void show(stack *MyStk);
void clear(stack* MyStk);
void v_file(stack* MyStk);
void prov(stack* MyStk);