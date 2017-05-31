#include "iostream"
#define kol 30
#define ras 30

using namespace std;
int ch;
int lic=0;//основной счетчик

struct avto
{
	char mark[kol];//марка авто
	char color[20];//цвет
	int data_v;//дата выпуска
	char kusov[20];//тип кузова
	int nomer;//заводской номер
	int data_TO;//дата ТО
	char vladelec[20];//имя владельца
};

struct avto A[ras];
struct avto pustota;

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

void TO()
{
	for(int i=0; i<lic; i++)
	{
		if((2016-A[i].data_v < 5))//для машин моложе 5 лет
		{
			if(2016-A[i].data_TO>=2)
				{
					cout<<endl;
					cout<<"Посетите, пожалуйста, станцию ТО"<<endl;
					cout<<"Марка авто ";
					cout<<A[i].mark<<endl;
					cout<<"Цвет авто ";
					cout<<A[i].color<<endl;
					cout<<"Дата выпуска авто ";
					cout<<A[i].data_v<<endl;
					cout<<"Кузов авто ";
					cout<<A[i].kusov<<endl;
					cout<<"Дата ТО авто ";
					cout<<A[i].data_TO<<endl;
					cout<<"Заводской номер авто ";
					cout<<A[i].nomer<<endl;
					cout<<"Владелец авто ";
					cout<<A[i].vladelec<<endl;
				}
		}

		if((2016-A[i].data_v >= 5)&&(2016-A[i].data_v <= 10))//для машин моложе 10 лет, старше 5
		{
			if(2016-A[i].data_TO>=1)
			{
				cout<<endl;
					cout<<"Посетите, пожалуйста, станцию ТО"<<endl;
					cout<<"Марка авто ";
					cout<<A[i].mark<<endl;
					cout<<"Цвет авто ";
					cout<<A[i].color<<endl;
					cout<<"Дата выпуска авто ";
					cout<<A[i].data_v<<endl;
					cout<<"Кузов авто ";
					cout<<A[i].kusov<<endl;
					cout<<"Дата ТО авто ";
					cout<<A[i].data_TO<<endl;
					cout<<"Заводской номер авто ";
					cout<<A[i].nomer<<endl;
					cout<<"Владелец авто ";
					cout<<A[i].vladelec<<endl;
			}
		}
	}
		cout<<endl;
		cout<<"Выберите действие ";
		cin>>ch;

}

void vvod()
{
	cout<<"Ввод информации"<<endl;
	if(lic<ras)
	{
		cout<<"Строка №"<<lic+1<<endl;
		cout<<"Введите марку авто ";
		cin >> A[lic].mark;
		cout<<"Введите цвет авто";
		cin>> A[lic].color;
		cout<<"Дата выпуска авто ";
		cin>> A[lic].data_v;
		cout<<"Введите тип кузова авто ";
		cin>> A[lic].kusov;
		cout<<"Введите заводской номер авто ";
		cin>> A[lic].nomer;
		cout<<"Введите дату ТО авто ";
		cin>> A[lic].data_TO;
		cout<<"Введите имя владельца авто ";
		cin>> A[lic].vladelec;
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
	int a,b;
	cout<<"Выберите действие"<<endl;
	cout<<"1-Вывод определенной строки"<<endl;
	cout<<"2-Вывод всей информации"<<endl;
	cin>>a;
	cout<<endl;
		if(a==1)
		{
		cout<<"Какую строку вывести? ";
		cin>>b;
		cout<<"Марка авто ";
		cout<<A[b-1].mark<<endl;
		cout<<"Цвет авто ";
		cout<<A[b-1].color<<endl;
		cout<<"Дата выпуска авто ";
		cout<<A[b-1].data_v<<endl;
		cout<<"Кузов авто ";
		cout<<A[b-1].kusov<<endl;
		cout<<"Дата ТО авто ";
		cout<<A[b-1].data_TO<<endl;
		cout<<"Заводской номер авто";
		cout<<A[b-1].nomer<<endl;
		cout<<"Владелец авто ";
		cout<<A[b-1].vladelec<<endl;
		}
			if(a==2)
			{
				for(int i=0;i<lic;i++)
				{
					cout<<endl;
					cout<<endl;
					cout<<"Марка авто ";
					cout<<A[i].mark<<endl;
					cout<<"Цвет авто ";
					cout<<A[i].color<<endl;
					cout<<"Дата выпуска авто ";
					cout<<A[i].data_v<<endl;
					cout<<"Кузов авто ";
					cout<<A[i].kusov<<endl;
					cout<<"Дата ТО авто ";
					cout<<A[i].data_TO<<endl;
					cout<<"Заводской номер авто ";
					cout<<A[i].nomer<<endl;
					cout<<"Владелец авто ";
					cout<<A[i].vladelec<<endl;
				}
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
	cout<<"1-Поиск по номеру автомобиля"<<endl;
	cout<<"2-Поиск по владельцу автомобиля "<<endl;
	cin>>t;
	if (t==1)
	{
		cout<<endl;
		cout<<"Введите Номер автомобиля ";
		cin>>h;
		for(int i=0;i<lic;i++)
		{
			if(h==A[i].nomer)
			{
					cout<<"Строка №"<<i+1<<endl;
					cout<<"Марка авто ";
					cout<<A[i].mark<<endl;
					cout<<"Цвет авто ";
					cout<<A[i].color<<endl;
					cout<<"Дата выпуска авто ";
					cout<<A[i].data_v<<endl;
					cout<<"Кузов авто ";
					cout<<A[i].kusov<<endl;
					cout<<"Дата ТО авто ";
					cout<<A[i].data_TO<<endl;
					cout<<"Заводской номер авто ";
					cout<<A[i].nomer<<endl;
					cout<<"Владелец авто ";
					cout<<A[i].vladelec<<endl;
					o=o+1;
			}
		}
		if(o==0)
			cout<<"Соответствий не найдено"<<endl;
	}
	
	if(t==2)
	{
		cout<<"Введите владельца авто ";
		gets(label);
		gets(label);
		for (int j=0; j<lic;j++)
		{
			if(strcmp(A[j].vladelec,label)==0)
			{
					cout<<"Строка №"<<j+1<<endl;
					cout<<"Марка авто ";
					cout<<A[j].mark<<endl;
					cout<<"Цвет авто ";
					cout<<A[j].color<<endl;
					cout<<"Дата выпуска авто ";
					cout<<A[j].data_v<<endl;
					cout<<"Кузов авто ";
					cout<<A[j].kusov<<endl;
					cout<<"Дата ТО авто ";
					cout<<A[j].data_TO<<endl;
					cout<<"Заводской номер авто ";
					cout<<A[j].nomer<<endl;
					cout<<"Владелец авто ";
					cout<<A[j].vladelec<<endl;
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
	cout<<"4- Для вывода записи(ей)"<<endl;
	cout<<"5- Для приглашения на ТО"<<endl;
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
			case 5: TO();break;
		}
	}while(ch!=6);
}