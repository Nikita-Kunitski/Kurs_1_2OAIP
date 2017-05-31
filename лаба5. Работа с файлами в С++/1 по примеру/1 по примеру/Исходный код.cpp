#include <stdio.h>  
#include <fstream>
#include <iostream>
using namespace std; 
int main ()
{    int k=0,i=0,j=0,c=0,s;
		char str1[255],str2[255];
      ifstream fout2("F1.txt");
      ofstream fout1 ("F2.txt");  
     
	  if(!fout2.is_open())
	  {
		  cout<<"File error"<<endl;
	  }
	  			fout2.getline(str1,256,'\n');
			s=strlen(str1);
			for(j=1;j<10;j++)
			{
				fout2.getline(str2,256,'\n');
				if(strcmp(str1,str2)!=0)
				{
					fout1<<str2<<"\n";
					cout<<str2<<endl;
				}	
			}

fout2.close();
fout1.close ();      
return 0;     
}
