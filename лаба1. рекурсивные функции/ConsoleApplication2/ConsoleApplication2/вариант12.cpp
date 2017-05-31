#include <iostream>
#include <iomanip>
int plus(int a, int b);
int rasn (int a, int b);
int multi(int a, int b);
int power(int a, int b);

int plus(int a, int b)
{
	if(b==0)
		return a;
	else
	{
		return plus(a+1,b-1);	
	}
}

int rasn (int a, int b)
{
	if(b==0)
		return a;
	else
	{
		return rasn(a-1,b-1);
	}
		if(b>a)
			{
				if(a==0)
					return b;
				else
				{
				 return rasn(a-1,b-1);
				}
			}	
}

int multi(int a, int b)
	{
		if(b>1)
			return(plus(multi(a,b-1),a));
		if(b==1)
			return a;
		if(b==0)
			return 0;
	}

int power(int a, int b)
	{
		if(b)
			return multi(a,power(a,b-1));
		else
		{
		return 1;
		}

	}

int main()
{
	int a,b;
	setlocale(LC_CTYPE,"Rus");
	std::cout<<"Введите число а ";
	std::cin>>a;
	std::cout<<"Введите число b ";
	std::cin>>b;
	std::cout<<"Сумма чисел "<<plus(a,b)<<"\n";
	std::cout<<"Разность чисел "<<rasn(a,b)<<"\n";
	std::cout<<"Произведение чисел "<<multi(a,b)<<"\n";
	std::cout<<"Возведение числа а в b "<<power(a,b)<<"\n";
	return 0;
}
