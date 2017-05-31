#include <iostream>
#include <iomanip>
int fact(int i);
int binom(int n, int m);

void main()
{
	int j;
	int m,n;
	setlocale(LC_CTYPE,"Rus");
	std::cout<<"¬ведите множество чисел n ";
	std::cin>>n;
	std::cout<<"¬ведите выборку m ";
	std::cin>>m;
	std::cout<<"Ѕиноминальный коэффициент равен "<<binom(n,m)<< "\n";
	std::cout<<"\n";
}

int fact(int i)
{
  if((i==0)||(i==1)) return 1;
  return i*fact(i-1);
}

int binom(int n, int m)
{
	if (m==0 || m==n) return 1;
	if (0<m && m<n) return (fact(n-1)/(fact(m)*fact((n-1)-m)) + fact(n-1)/(fact(m-1)*fact((n-1)-(m-1))));
}