// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Tree.h"
#include <fstream>
using namespace std;
struct NodeTree
      {
		  int  key;  
	  };
fstream file_in,file_out;

btree::CMP cmpfnc(void* x, void* y)    // ���������
{
		 btree::CMP rc =  btree::EQUAL;
         if   (((NodeTree*)x)->key  <  ((NodeTree*)y)->key)    
			 rc = btree::LESS;
         else   if (((NodeTree*)x)->key  > ((NodeTree*)y)->key)       
			 rc = btree::GREAT;
         return rc;
}

void Print(void* x)    // ����� ������
{
	cout <<((NodeTree*)x)->key <<endl;
}

void Print_s(void* x)    // ����� ��� ������
{
	cout <<((NodeTree*)x)->key<<" ";
}

bool BuildTree(char *FileName, btree::Object& tree)     //���������� ������ �� �����
{
	bool rc = true;     
	file_in.open("in.txt");
        if (file_in.fail())
		{
			cout<<"������ �������� �������� �����"<<endl;
			rc = false; 
		}
                  cout<<"    �������� ������"<< endl;     // ���������� ������ � �����  �������� ������
                  while (!file_in.eof())
                  {     
					  int num;   
					  file_in>>num;
					  NodeTree *a = new NodeTree();
					  a->key = num;  
					  tree.Insert(a);    
					  cout<<num<<endl;		
				  }
file_in.close();
return rc;
}

void SaveToFile(void *x)     // ������ ������ �������� � ����
{
	NodeTree *a = (NodeTree*)x;      
	int q = a->key; 
    file_out<<q<<" ";
}	
void SaveTree(btree::Object &tree, char *FileName)    //���������� ������ � ���� 
{      file_out.open("out.txt");
        if (file_out.fail())  
        {      cout<<"������ �������� ��������� �����"<<endl;  return;   }
        tree.Root->ScanDown(SaveToFile);
        file_out.close();
}
int _tmain(int argc, _TCHAR* argv[])
{        setlocale (LC_CTYPE, "Russian");
btree::Object t1 = btree::Create(cmpfnc);  int k, choise;   
NodeTree a1 = {1}, a2 = {2}, a3 = {3}, a4 = {4}, a5 = {5}, a6 = {6};    
bool rc = t1.Insert(&a4);   //true                 4  
rc  =  t1.Insert(&a1);         //true         1             
rc  =  t1.Insert(&a6);          //true                           6
rc  =  t1.Insert(&a2);           //true              2     
rc  =  t1.Insert(&a3);            //true                   3
rc  =  t1.Insert(&a5);            //true                        5	
for(;;)  
{         NodeTree *a = new NodeTree;           
cout<<"\t\t ����\n";
cout<<"\t1 - ����� ������ �� �����"<<endl;
cout<<"\t2 - ���������� ��������"<<endl;
cout<<"\t3 - �������� ��������"<<endl;
cout<<"\t4 - ��������� � ����"<<endl;
cout<<"\t5 - ��������� �� �����"<<endl;
cout<<"\t6 - �������� ������"<<endl;
cout<<"\t7 - ��������� �����(����� ���� ��������� �� �����������)--���� �10"<<endl;
cout<<"\t8 - ���������� �����"<<endl;
cout<<"\t0 - �����"<<endl;
cout<<"\tC������� ����� "; cin>>choise; 
switch(choise)
{         case 0:   exit(0);
case 1:   t1.Root->Vyvod(Print,0);
			 break;	 
case 2:   cout<<"������� ����"<<endl;   cin>>k; 
                   a->key = k;	t1.Insert(a);   break;	 
 case 3:   cout<<"������� ����"<<endl;  cin>>k;
	      a->key = k;  	t1.Delete(a);   break;
 case 4:    SaveTree(t1, "G.txt");	break;
 case 5:    BuildTree("G.txt",  t1);	break;
           case 6:    {      while (t1.Root)	  t1.Delete(t1.Root);     }   break;	
		   case 7: t1.Root->obxod_smesh(Print_s);
			   cout<<endl;
			   break;
		   case 8:t1.Root->obxod_niz(Print_s);
}
        }
        return 0;
       }
