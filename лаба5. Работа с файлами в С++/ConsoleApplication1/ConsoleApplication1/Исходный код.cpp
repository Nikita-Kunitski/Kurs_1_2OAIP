#include<iostream>
#include<fstream>
#define kol 30
#define ras 30
using namespace std;
int ch;//номер команды
int lic=0;//основной счетчик
fstream file;
struct student
	{
		char namef[kol];	//фамилия
		char name[20];	//имя
		char otch[20];	//отчество
		unsigned den:5;	//день поступления
		unsigned mes:4;	//месяц 
		unsigned god:11;//год
		char spec[20];	//специальность
		int gruppa;		//группа
		char fakultet[20];//факультет
		int sr_b;		//средний балл
	};

struct student a[ras];
struct student pustota;

void vvod()
{
	int den, mes, god, num;
	cout<<"Ввод информации"<<endl;
	if (lic<ras)
	{
		cout<<"1 - Ввод с клавиатуры "<<endl;
		cout<<"2 - Ввод в файл "<<endl;
		cout<<"3 - Ввод из файла"<<endl;
		cin>> num;
		if(num==1)
		{
		cout<<"Строка №"<<lic+1<<endl;
		cout<<"Введите фамилию студента ";
		cin>>a[lic].namef;
		cout<<"Введите имя студента ";
		cin>>a[lic].name;
		cout<<"Введите отчество студента ";
		cin>>a[lic].otch;
		cout<<"Введите дату поступления студента "<<endl;
		cout<<"Число ";
		cin>>den;
		cout<<"Месяц ";
		cin>>mes;
		cout<<"Год ";
		cin>>god;
		a[lic].den=den;
		a[lic].mes=mes;
		a[lic].god=god;
		cout<<"Введите факультет ";
		cin>>a[lic].fakultet;
		cout<<"Введите специальность студента ";
		cin>>a[lic].spec;
		cout<<"Введите № учебной группы ";
		cin>>a[lic].gruppa;
		cout<<"Введите средний балл студента ";
		cin>>a[lic].sr_b;
		lic++;
		}
		if(num==2)
		{
			
			cout<<"Строка №"<<lic+1<<endl;
			cout<<"Введите фамилию студента ";
			cin>>a[lic].namef;
			cout<<"Введите имя студента ";
			cin>>a[lic].name;
			cout<<"Введите отчество студента ";
			cin>>a[lic].otch;
			cout<<"Введите дату поступления студента "<<endl;
			cout<<"Число ";
			cin>>den;
			cout<<"Месяц ";
			cin>>mes;
			cout<<"Год ";
			cin>>god;
			a[lic].den=den;
			a[lic].mes=mes;
			a[lic].god=god;
			cout<<"Введите факультет ";
			cin>>a[lic].fakultet;
			cout<<"Введите специальность студента ";
			cin>>a[lic].spec;
			cout<<"Введите № учебной группы ";
			cin>>a[lic].gruppa;
			cout<<"Введите средний балл студента ";
			cin>>a[lic].sr_b;

			file.open("b.txt");
			
			file<<a[lic].namef<<" ";
			file<<a[lic].name<<" ";
			file<<a[lic].otch<<" ";
			file<<den<<" ";
			file<<mes<<" ";
			file<<god<<" ";
			a[lic].den=den;
			a[lic].mes=mes;
			a[lic].god=god;
			file<<a[lic].fakultet<<" ";
			file<<a[lic].spec<<" ";
			file<<a[lic].gruppa<<" ";
			file<<a[lic].sr_b<<"\n";
			file.close();
			
			lic++;
		}
	if(num==3)
		{
			int den,mes,god;
			file.open("a.txt");
			file>>a[lic].namef;
			file>>a[lic].name;
			file>>a[lic].otch;
			file>>den;
			file>>mes;
			file>>god;
			a[lic].den=den;
			a[lic].mes=mes;
			a[lic].god=god;
			file>>a[lic].fakultet;
			file>>a[lic].spec;
			file>>a[lic].gruppa;
			file>>a[lic].sr_b;		
		file.close();
		lic++;
	}
	}
	else
		{
			cout<<"Введено максимально количество информации";
		}
	cout<<endl;
	cout<<"\tВыберите действие ";
	cin>>ch;
}

void vivod()
{
	int c,b;
	cout<<endl;
	cout<<"Выберите действие"<<endl;
	cout<<"1 - Вывод опредиленной строки"<<endl;
	cout<<"2 - Вывод всей информации"<<endl;
	cin>> c;
	cout<<endl;
		if(c==1)
		{
			cout<<"Какую строку вывести? ";
			cin>>b;
			cout<<"Ф.И.О. "<<a[b-1].namef<<" "<<a[b-1].name<<" "<<a[b-1].otch<<endl;
			cout<<"Факультет ";
			cout<<a[b-1].fakultet<<endl;
			cout<<"Специальность факультета ";
			cout<<a[b-1].spec<<endl;
			cout<<"Группа";
			cout<<a[b-1].gruppa<<endl;
			cout<<"Средний балл ";
			cout<<a[b-1].sr_b<<endl;
			cout<<"Дата поступения "<<a[b-1].den<<"."<<a[b-1].mes<<"."<<a[b-1].god;
		}
		if(c==2)
		{
			for(int i=0;i<lic;i++)
	{
			cout<<"------------------------------------"<<endl;
			cout<<"Ф.И.О. "<<a[i].namef<<" "<<a[i].name<<" "<<a[i].otch<<endl;
			cout<<"Факультет ";
			cout<<a[i].fakultet<<endl;
			cout<<"Специальность факультета ";
			cout<<a[i].spec<<endl;
			cout<<"Группа";
			cout<<a[i].gruppa<<endl;
			cout<<"Средний балл ";
			cout<<a[i].sr_b<<endl;
			cout<<"Дата поступения "<<a[i].den<<"."<<a[i].mes<<"."<<a[i].god<<endl;	
			cout<<"------------------------------------"<<endl;
	}		
		}
		cout<<endl;
		cout<<"\tВыберите действие ";
		cin>>ch;
}

void serch()
{
	int b;
	cout<<"Поиск происходит по среднему баллу "<<endl;
	cout<<"Введите балл (выведутся студенты с большим баллом) ";
	cin>>b;
	for(int i=0;i<lic;i++)
	{
		if(b<=a[i].sr_b)
		{
			cout<<"Ф.И.О. "<<a[i].namef<<" "<<a[i].name<<" "<<a[i].otch<<endl;
			cout<<"Факультет ";
			cout<<a[i].fakultet<<endl;
			cout<<"Специальность факультета ";
			cout<<a[i].spec<<endl;
			cout<<"Группа";
			cout<<a[i].gruppa<<endl;
			cout<<"Средний балл ";
			cout<<a[i].sr_b<<endl;
			cout<<"Дата поступения "<<a[i].den<<"."<<a[i].mes<<"."<<a[i].god;	
		}
	}
	cout<<endl;
		cout<<"\tВыберите действие ";
		cin>>ch;
}

void del()
{
	int d;
	cout<<"- Введите № строки которую нужно удалить"<<endl;
	cout<<"- 99-Удалить всю базу"<<endl;
	cin>>d;
	if(d!=99)
		{
			for(int i=(d-1);i<lic;i++)
			{
			a[i]=a[i+1];
			lic=lic-1;
			}
		}

	if(d==99)
	{
		for(int i=0;i<lic;i++)
		{
		a[i]=pustota;
		}
	}
	cout<<endl;
		cout<<"\tВыберите действие ";
		cin>>ch;
}

int main()
{
	setlocale(LC_CTYPE,"Rus");

	cout<<"Данных нет"<<endl;
	cout<<"Введите"<<endl;
	cout<<"1 - Для ввода записей"<<endl;
	cout<<"2 - Для вывода записей"<<endl;
	cout<<"3 - Для поиска записей"<<endl;
	cout<<"4 - Для удаления записей"<<endl;
	cin>>ch;
	do
	{
		switch (ch)
		{
		case 1:vvod();break;
		case 2:vivod();break;
		case 3:serch();break;
		case 4:del();break;
		}
	}while(ch!=5);
	return 0;
}