#include <iostream>
#include<string>
#define kol 30
#define ras 30

using namespace std;
int ch;
int lic=0;//основной счетчик
enum eform
{
	Abs_monarx = 1, Ogran_monarx, SP_monarx, Konst_monarx, Parl_monarx
} form;

struct gos
{
	char gosname[kol];//название гос-ва
	char stolica[20];//столица
	int chis_nas;//численность населения
	int pl;//площадь
	char pres[20];//фамилия президента
	string forma;//форма правления
	int data_inag;
	unsigned den:5;//день
	unsigned mes:4;//месяц
	unsigned god:11;//год
};

struct gos A[ras];
struct gos pustota;

void del()
{
	int d;
	cout<<"Введите строку которую нужно удалить"<<endl;
	cout<<"99-Удалить всю базу"<<endl;
	cin>>d;
	if(d!=99)
		{
			for(int e=(d-1);e<lic;e++)
			{
			A[e]=A[e+1];
			lic=lic-1;
			}
		}

	if(d==99)
	{
		for(int i=0;i<lic;i++)
		{
		A[i]=pustota;
		}
	}

	cout<<"Выберите действие ";
	cin>>ch;
}

void vvod()
{
	int f;//forma pravl
	int den, mes,god;
	cout<<"Ввод информации"<<endl;
	if(lic<ras)
	{
		cout<<"Строка №"<<lic+1<<endl;
		cout<<"Введите название гос-ва ";
		cin >> A[lic].gosname;
		cout<<"Введите столицу ";
		cin>> A[lic].stolica;
		cout<<"Введите численность населения ";
		cin>> A[lic].chis_nas;
		cout<<"Введите площадь гос-ва ";
		cin>> A[lic].pl;
		cout<<"Введите имя президента ";
		cin>> A[lic].pres;
		cout<<"Дата инагурация "<<endl;
		cout<<"День";
		cin>>den;
		cout<<"Месяц";
		cin>>mes;
		cout<<"Год";
		cin>>god;
		A[lic].den=den;
		A[lic].mes=mes;
		A[lic].god=god;
		cout<<"Введите номер монархии (1-5) "<<endl; 
		cin>>f;
		switch(f)
		{
			case(Abs_monarx):
				{A[lic].forma= "Abs_monarx"; break;}
			case(Ogran_monarx):
				{A[lic].forma= "Ogran_monarx"; break;}
			case(SP_monarx):
				{A[lic].forma= "SP_monarx"; break;}
			case(Konst_monarx):
				{A[lic].forma= "Konst_monarx"; break;}
			case(Parl_monarx):
				{A[lic].forma= "Parl_monarx"; break;}
		}
		lic++;
	}
	else
	 {
		cout<<"Введено максимальное количество строк"<<endl;
	 }
	cout<<endl;
	cout<<"Выберите действие ";
	cin>>ch;
}

void vivod()
{
	int position(1);
	cout<<"Дата инагурации "<<endl;
	for(int i=0; i<lic;i++)
	{
		cout<<A[i].den<<"."<<A[i].mes<<"."<<A[i].god;
		position ++;
	}
			cout<<endl;
			cout<<"Выберите действие ";
			cin>>ch;
}

void search()
{
	int t,h,o=0,s=0;
	char label[20],label_2[20];
	cout<<endl;
	cout<<"1-Поиск по площади гос-ва"<<endl;
	cout<<"2-Поиск по наименованию гос-ва "<<endl;
	cout<<"3-Поиск по монархии гос-ва "<<endl;
	cin>>t;
	if (t==1)
	{
		cout<<endl;
		cout<<"Введите площадь гос-ва. (Выведется гос-ва больше заданной площади) ";
		cin>>h;
		for(int i=0;i<lic;i++)
		{
			if(h<=A[i].pl)
			{
					cout<<"Строка №"<<i+1<<endl;
					cout<<"Наименование гос-ва ";
					cout<<A[i].gosname<<endl;
					cout<<"Столица ";
					cout<<A[i].stolica<<endl;
					cout<<"Численность населения ";
					cout<<A[i].chis_nas<<endl;
					cout<<"Площадь гос-ва ";
					cout<<A[i].pl<<endl;
					cout<<"Имя президента ";
					cout<<A[i].pres<<endl;
					o=o+1;
			}
		}
		if(o==0)
			cout<<"Соответствий не найдено"<<endl;
	}
	
	if(t==2)
	{
		cout<<"Введите название гос-ва ";
		gets_s(label);
		gets_s(label);
		for (int j=0; j<lic;j++)
		{
			if(strcmp(A[j].gosname,label)==0)
			{
					cout<<"\nСтрока №"<<j+1<<endl;
					cout<<"Наименование гос-ва ";
					cout<<A[j].gosname<<endl;
					cout<<"Столица ";
					cout<<A[j].stolica<<endl;
					cout<<"Численность населения ";
					cout<<A[j].chis_nas<<endl;
					cout<<"Площадь гос-ва ";
					cout<<A[j].pl<<endl;
					cout<<"Имя президента ";
					cout<<A[j].pres<<endl;
			}
		}
	}	
	if(t==3)
	{
		int m=0;
		char cost[30];
		cout<<"Введите монархию (Abs_monarx, Ogran_monarx, SP_monarx, Konst_monarx, Parl_monarx): ";
		cin>>cost;
		cout<<endl;
				for(int i=0;i<=lic;i++)
				{
					if(A[i].forma == cost)
					{	
					cout<<"Наименование гос-ва ";
					cout<<A[i].gosname<<endl;
					cout<<"Столица ";
					cout<<A[i].stolica<<endl;
					cout<<"Численность населения ";
					cout<<A[i].chis_nas<<endl;
					cout<<"Площадь гос-ва ";
					cout<<A[i].pl<<endl;
					cout<<"Имя президента ";
					cout<<A[i].pres<<endl;
					m++;
					}
					else
					{
						if(m==0)
							cout<<"Соответствий не найдено "<<endl;
					}
				}
	}
			cout<<endl;
			cout<<"Выберите действие ";
			cin>>ch;
}

int main()
{
	setlocale(LC_CTYPE,"Rus");
	cout<<"Данных нет"<< endl;
	cout<<"Введите"<<endl;
	cout<<"1- Для удаления записей"<<endl;
	cout<<"2- Для ввода новой записи"<<endl;
	cout<<"3- Для поиска записей"<<endl;
	cout<<"4- Для вывода даты инагурации"<<endl;
	cout<<"5- Поиск по монархии"<<endl;
	cout<<"6- Для выхода"<<endl;
	cin>>ch;
	do
	{
		switch(ch)
		{
			case 1: del(); break;
			case 2: vvod(); break;
			case 3: search();break;
			case 4: vivod(); break;
		
		}
	}while(ch!=5);
}