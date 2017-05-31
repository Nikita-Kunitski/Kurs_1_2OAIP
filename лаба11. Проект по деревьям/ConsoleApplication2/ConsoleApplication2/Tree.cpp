#include "stdafx.h"
#include "Tree.h"
using namespace std;
namespace btree  // бинарное дерево, не допускаетс€ дублирование ключей
{       
	Object Create(CMP (*f)(void*, void*))    
                    {
						return *(new Object(f)); 
                    }

	Node* Node::Min() 
	{ 
		Node* rc = this; if (rc->Left != NULL) 
        rc = rc->Left->Min(); 
        return rc;
	}

		Node* Node::Next()
		{       Node* rc = this, *x = this;
				if (rc->Right != NULL)    
					rc = rc->Right->Min();
				else   
				{   
					rc = this->Parent;
						 while (rc != NULL && x == rc->Right)
						  { 
							  x = rc;	
							  rc = rc->Parent;   
						  }  
				 }  
				return rc;
		}
			void Node::ScanDown(void (*f)(void* n))
			{       
				f(this->Data);   
				std::cout<<endl;
					 if (this->Left  != NULL)      
						 this->Left->ScanDown(f); 
					 if (this->Right != NULL)    
						 this->Right->ScanDown(f);
			}
	Node* Object::Search(void* d, Node* n)
	{      
		Node* rc = n; 
		   if (rc != NULL)   
		   {        if (isLess(d, n->Data))
		   rc = Search(d, n->Left);
					 else if (isGreat(d, n->Data)) 
						 rc = Search(d, n->Right);    
			} return rc;
	}

			bool Object::Insert(void* d)
			{       
				Node* x  = this->Root, *n = NULL;  
				bool rc = true;
			while (rc == true && x != NULL) 
			{        n = x;   
					if (isLess(d, x->Data))    
						x = x->Left;   //выбор куда идти - влево или вправо
					 else  if (isGreat(d, x->Data))     
						 x = x->Right;
							 else  rc = false;	
			 }
			if (rc == true && n == NULL)    
				this->Root = new  Node(NULL, NULL, NULL, d);
			else  if (rc == true  &&  isLess(d, n->Data))  
								n->Left  = new  Node(n, NULL, NULL, d);     
					else  if (rc == true  &&  isGreat(d, n->Data)) 
									   n->Right = new  Node(n, NULL, NULL, d);  
			return rc;
			};	
bool  Object::Delete(Node* n )
{   
		 bool rc = true;
         if (rc = (n !=  NULL))
         {         
			 if (n->Left == NULL  &&  n->Right == NULL) //если потомков нет
                    {        
						if (n->Parent == NULL)  
							this->Root = NULL;   //обнуление корн€
                             else if (n->Parent->Left == n)
								 n->Parent->Left = NULL;   
                                     else n->Parent->Right = NULL;  
                              delete n; 
                     }
                     else if (n->Left==NULL  &&  n->Right!=NULL) //только правый по-томок
                            {    
								if (n->Parent == NULL)   
									this->Root = n->Right;  
                                      else if (n->Parent->Left == n)  
										  n->Parent->Left  = n->Right; 
                                             else   n->Parent->Right = n->Right;
                                      n->Right->Parent = n->Parent;  
									  delete n;   
                             }
                            else if (n->Left!=NULL &&n->Right==NULL)//только левый по-томок
                                   {   
									   if (n->Parent == NULL)  
										   this->Root = n->Left; 
                                             else if (n->Parent->Right == n) 
												 n->Parent->Left  = n->Left;  
                                                     else  n->Parent->Right = n->Left;   
                                              n->Left->Parent = n->Parent;   
											  delete n;   
                                      }
         else if (n->Left != NULL  &&  n->Right != NULL) //если есть оба потомка
                {        
					Node* x = n->Next();
					n->Data = x->Data;  
					rc = Delete(x);
				}  
         } return  rc;  
}

void Node::ScanLevel(void (*f)(void* n), int i)  //¬ывести вершины уровн€
{	
	if (this->Left  != NULL)
		this->Left->ScanLevel(f, i); 
	if(this->GetLevel() ==  i)     
		f(this->Data); 
	if (this->Right != NULL)     
		this->Right->ScanLevel(f, i);
}

	int Node::GetLevel()
	{        
		Node *rc = this;	
		int q = 0;
	while(rc->Parent != NULL)
	{    
		rc = rc->Parent;
			q++;
	}
	return q;
	}
		void Node::ScanByLevel(void (*f)(void* n))
		{        
			for(int i = 0;  i < 10;  i++)
				 {
					 std::cout<<'\t';
					 this->ScanLevel(f,i);
					 std::cout<<'\n';	
				 } 
		}

		void Node::Vyvod (void (*f)(void* n), int l)  //¬ывод на экран
		{      int i;
				if  (this != NULL)            //*w - указатель на корень 
				{     this->Right->Vyvod (f, l + 1);
								 for  (i = 1;  i <= l;  i++)  cout<<"   ";
								 f(this->Data);
								 this->Left->Vyvod (f,  l  + 1); 
				 }
		}

		void Node::obxod_smesh(void (*f)(void* n))
		{
			if(this!=NULL)
		{
		this->Left->obxod_smesh(f);
		f(this->Data);
		this->Right->obxod_smesh(f);
		}
			
		}
		void Node::obxod_niz(void (*f)(void* n))
		{
				if(this!=NULL)
					{
						f(this->Data);
					this->Left->obxod_smesh(f);
					this->Right->obxod_smesh(f);
					}
		}
}

