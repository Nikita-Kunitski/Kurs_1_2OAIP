#include<iostream>
#define kol 30
#define ras 30
using namespace std;
int ch;//����� �������
int lic=0;//�������� �������
FILE *file;
struct student
	{
		char namef[kol];	//�������
		char name[20];	//���
		char otch[20];	//��������
		unsigned den:5;	//���� �����������
		unsigned mes:4;	//����� 
		unsigned god:11;//���
		char spec[20];	//�������������
		int gruppa;		//������
		char fakultet[20];//���������
		int sr_b;		//������� ����
	};

struct student a[ras];
struct student pustota;

void vvod()
{
	int den, mes, god, num;
	cout<<"���� ����������"<<endl;
	if (lic<ras)
	{
		cout<<"1 - ���� � ���������� "<<endl;
		cout<<"2 - ���� � ���� "<<endl;
		cout<<"3 - ���� �� �����"<<endl;
		cin>> num;
		if(num==1)
		{
		cout<<"������ �"<<lic+1<<endl;
		cout<<"������� ������� �������� ";
		cin>>a[lic].namef;
		cout<<"������� ��� �������� ";
		cin>>a[lic].name;
		cout<<"������� �������� �������� ";
		cin>>a[lic].otch;
		cout<<"������� ���� ����������� �������� "<<endl;
		cout<<"����� ";
		cin>>den;
		cout<<"����� ";
		cin>>mes;
		cout<<"��� ";
		cin>>god;
		a[lic].den=den;
		a[lic].mes=mes;
		a[lic].god=god;
		cout<<"������� ��������� ";
		cin>>a[lic].fakultet;
		cout<<"������� ������������� �������� ";
		cin>>a[lic].spec;
		cout<<"������� � ������� ������ ";
		cin>>a[lic].gruppa;
		cout<<"������� ������� ���� �������� ";
		cin>>a[lic].sr_b;
		lic++;
		}
		if(num==2)
		{
			
			cout<<"������ �"<<lic+1<<endl;
			cout<<"������� ������� �������� ";
			cin>>a[lic].namef;
			cout<<"������� ��� �������� ";
			cin>>a[lic].name;
			cout<<"������� �������� �������� ";
			cin>>a[lic].otch;
			cout<<"������� ���� ����������� �������� "<<endl;
			cout<<"����� ";
			cin>>den;
			cout<<"����� ";
			cin>>mes;
			cout<<"��� ";
			cin>>god;
			a[lic].den=den;
			a[lic].mes=mes;
			a[lic].god=god;
			cout<<"������� ��������� ";
			cin>>a[lic].fakultet;
			cout<<"������� ������������� �������� ";
			cin>>a[lic].spec;
			cout<<"������� � ������� ������ ";
			cin>>a[lic].gruppa;
			cout<<"������� ������� ���� �������� ";
			cin>>a[lic].sr_b;

			file=fopen("b.txt","w");
			
			fprintf(file,"%s %s %s %d %d %d %s %s %d %d",&a[lic].namef, &a[lic].name, &a[lic].otch, a[lic].den, a[lic].mes, a[lic].god, &a[lic].fakultet, &a[lic].spec, a[lic].gruppa, a[lic].sr_b);
			fclose(file);
			lic++;
		}
		if(num==3)
		{
			file=fopen("a.txt","r");
	
		{
			fscanf(file,"%s %s %s %d %d %d %s %s %d %d\n",&a[lic].namef, &a[lic].name, &a[lic].otch, &den, &mes, &god, &a[lic].fakultet, &a[lic].spec, &a[lic].gruppa, &a[lic].sr_b);
			a[lic].den=den;
		a[lic].mes=mes;
		a[lic].god=god;
		lic++;
		}
		fclose(file);
		}
	}
	else
		{
			cout<<"������� ����������� ���������� ����������";
		}
	cout<<endl;
	cout<<"\t�������� �������� ";
	cin>>ch;
}

void vivod()
{
	int c,b;
	cout<<endl;
	cout<<"�������� ��������"<<endl;
	cout<<"1 - ����� ������������ ������"<<endl;
	cout<<"2 - ����� ���� ����������"<<endl;
	cin>> c;
	cout<<endl;
		if(c==1)
		{
			cout<<"����� ������ �������? ";
			cin>>b;
			cout<<"�.�.�. "<<a[b-1].namef<<" "<<a[b-1].name<<" "<<a[b-1].otch<<endl;
			/*cout<<"������� �������� ";
			cout<<a[b-1].namef<<endl;
			cout<<"��� �������� ";
			cout<<a[b-1].name<<endl;
			cout<<"�������� ";
			cout<<a[b-1].otch<<endl;*/
			cout<<"��������� ";
			cout<<a[b-1].fakultet<<endl;
			cout<<"������������� ���������� ";
			cout<<a[b-1].spec<<endl;
			cout<<"������";
			cout<<a[b-1].gruppa<<endl;
			cout<<"������� ���� ";
			cout<<a[b-1].sr_b<<endl;
			cout<<"���� ���������� "<<a[b-1].den<<"."<<a[b-1].mes<<"."<<a[b-1].god;
		}
		if(c==2)
		{
			for(int i=0;i<lic;i++)
	{
			cout<<"------------------------------------"<<endl;
			cout<<"�.�.�. "<<a[i].namef<<" "<<a[i].name<<" "<<a[i].otch<<endl;
			/*cout<<"������� �������� ";
			cout<<a[i].namef<<endl;
			cout<<"��� �������� ";
			cout<<a[i].name<<endl;
			cout<<"�������� ";
			cout<<a[i].otch<<endl;*/
			cout<<"��������� ";
			cout<<a[i].fakultet<<endl;
			cout<<"������������� ���������� ";
			cout<<a[i].spec<<endl;
			cout<<"������";
			cout<<a[i].gruppa<<endl;
			cout<<"������� ���� ";
			cout<<a[i].sr_b<<endl;
			cout<<"���� ���������� "<<a[i].den<<"."<<a[i].mes<<"."<<a[i].god<<endl;	
			cout<<"------------------------------------"<<endl;
	}		
		}
		cout<<endl;
		cout<<"\t�������� �������� ";
		cin>>ch;
}

void serch()
{
	int b;
	cout<<"����� ���������� �� �������� ����� "<<endl;
	cout<<"������� ���� (��������� �������� � ������� ������) ";
	cin>>b;
	for(int i=0;i<lic;i++)
	{
		if(b<=a[i].sr_b)
		{
			cout<<"�.�.�. "<<a[i].namef<<" "<<a[i].name<<" "<<a[i].otch<<endl;
			/*cout<<"������� �������� ";
			cout<<a[i].namef<<endl;
			cout<<"��� �������� ";
			cout<<a[i].name<<endl;
			cout<<"�������� ";
			cout<<a[i].otch<<endl;*/
			cout<<"��������� ";
			cout<<a[i].fakultet<<endl;
			cout<<"������������� ���������� ";
			cout<<a[i].spec<<endl;
			cout<<"������";
			cout<<a[i].gruppa<<endl;
			cout<<"������� ���� ";
			cout<<a[i].sr_b<<endl;
			cout<<"���� ���������� "<<a[i].den<<"."<<a[i].mes<<"."<<a[i].god;	
		}
	}
	cout<<endl;
		cout<<"\t�������� �������� ";
		cin>>ch;
}

void del()
{
	int d;
	cout<<"- ������� � ������ ������� ����� �������"<<endl;
	cout<<"- 99-������� ��� ����"<<endl;
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
		cout<<"\t�������� �������� ";
		cin>>ch;
}

int main()
{
	setlocale(LC_CTYPE,"Rus");

	cout<<"������ ���"<<endl;
	cout<<"�������"<<endl;
	cout<<"1 - ��� ����� �������"<<endl;
	cout<<"2 - ��� ������ �������"<<endl;
	cout<<"3 - ��� ������ �������"<<endl;
	cout<<"4 - ��� �������� �������"<<endl;
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