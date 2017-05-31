#include <iostream>
#include<string>
#define kol 30
#define ras 30

using namespace std;
int ch;
int lic=0;//�������� �������
enum eform
{
	Abs_monarx = 1, Ogran_monarx, SP_monarx, Konst_monarx, Parl_monarx
} form;

struct gos
{
	char gosname[kol];//�������� ���-��
	char stolica[20];//�������
	int chis_nas;//����������� ���������
	int pl;//�������
	char pres[20];//������� ����������
	string forma;//����� ���������
	int data_inag;
	unsigned den:5;//����
	unsigned mes:4;//�����
	unsigned god:11;//���
};

struct gos A[ras];
struct gos pustota;

void del()
{
	int d;
	cout<<"������� ������ ������� ����� �������"<<endl;
	cout<<"99-������� ��� ����"<<endl;
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

	cout<<"�������� �������� ";
	cin>>ch;
}

void vvod()
{
	int f;//forma pravl
	int den, mes,god;
	cout<<"���� ����������"<<endl;
	if(lic<ras)
	{
		cout<<"������ �"<<lic+1<<endl;
		cout<<"������� �������� ���-�� ";
		cin >> A[lic].gosname;
		cout<<"������� ������� ";
		cin>> A[lic].stolica;
		cout<<"������� ����������� ��������� ";
		cin>> A[lic].chis_nas;
		cout<<"������� ������� ���-�� ";
		cin>> A[lic].pl;
		cout<<"������� ��� ���������� ";
		cin>> A[lic].pres;
		cout<<"���� ���������� "<<endl;
		cout<<"����";
		cin>>den;
		cout<<"�����";
		cin>>mes;
		cout<<"���";
		cin>>god;
		A[lic].den=den;
		A[lic].mes=mes;
		A[lic].god=god;
		cout<<"������� ����� �������� (1-5) "<<endl; 
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
		cout<<"������� ������������ ���������� �����"<<endl;
	 }
	cout<<endl;
	cout<<"�������� �������� ";
	cin>>ch;
}

void vivod()
{
	int position(1);
	cout<<"���� ���������� "<<endl;
	for(int i=0; i<lic;i++)
	{
		cout<<A[i].den<<"."<<A[i].mes<<"."<<A[i].god;
		position ++;
	}
			cout<<endl;
			cout<<"�������� �������� ";
			cin>>ch;
}

void search()
{
	int t,h,o=0,s=0;
	char label[20],label_2[20];
	cout<<endl;
	cout<<"1-����� �� ������� ���-��"<<endl;
	cout<<"2-����� �� ������������ ���-�� "<<endl;
	cout<<"3-����� �� �������� ���-�� "<<endl;
	cin>>t;
	if (t==1)
	{
		cout<<endl;
		cout<<"������� ������� ���-��. (��������� ���-�� ������ �������� �������) ";
		cin>>h;
		for(int i=0;i<lic;i++)
		{
			if(h<=A[i].pl)
			{
					cout<<"������ �"<<i+1<<endl;
					cout<<"������������ ���-�� ";
					cout<<A[i].gosname<<endl;
					cout<<"������� ";
					cout<<A[i].stolica<<endl;
					cout<<"����������� ��������� ";
					cout<<A[i].chis_nas<<endl;
					cout<<"������� ���-�� ";
					cout<<A[i].pl<<endl;
					cout<<"��� ���������� ";
					cout<<A[i].pres<<endl;
					o=o+1;
			}
		}
		if(o==0)
			cout<<"������������ �� �������"<<endl;
	}
	
	if(t==2)
	{
		cout<<"������� �������� ���-�� ";
		gets_s(label);
		gets_s(label);
		for (int j=0; j<lic;j++)
		{
			if(strcmp(A[j].gosname,label)==0)
			{
					cout<<"\n������ �"<<j+1<<endl;
					cout<<"������������ ���-�� ";
					cout<<A[j].gosname<<endl;
					cout<<"������� ";
					cout<<A[j].stolica<<endl;
					cout<<"����������� ��������� ";
					cout<<A[j].chis_nas<<endl;
					cout<<"������� ���-�� ";
					cout<<A[j].pl<<endl;
					cout<<"��� ���������� ";
					cout<<A[j].pres<<endl;
			}
		}
	}	
	if(t==3)
	{
		int m=0;
		char cost[30];
		cout<<"������� �������� (Abs_monarx, Ogran_monarx, SP_monarx, Konst_monarx, Parl_monarx): ";
		cin>>cost;
		cout<<endl;
				for(int i=0;i<=lic;i++)
				{
					if(A[i].forma == cost)
					{	
					cout<<"������������ ���-�� ";
					cout<<A[i].gosname<<endl;
					cout<<"������� ";
					cout<<A[i].stolica<<endl;
					cout<<"����������� ��������� ";
					cout<<A[i].chis_nas<<endl;
					cout<<"������� ���-�� ";
					cout<<A[i].pl<<endl;
					cout<<"��� ���������� ";
					cout<<A[i].pres<<endl;
					m++;
					}
					else
					{
						if(m==0)
							cout<<"������������ �� ������� "<<endl;
					}
				}
	}
			cout<<endl;
			cout<<"�������� �������� ";
			cin>>ch;
}

int main()
{
	setlocale(LC_CTYPE,"Rus");
	cout<<"������ ���"<< endl;
	cout<<"�������"<<endl;
	cout<<"1- ��� �������� �������"<<endl;
	cout<<"2- ��� ����� ����� ������"<<endl;
	cout<<"3- ��� ������ �������"<<endl;
	cout<<"4- ��� ������ ���� ����������"<<endl;
	cout<<"5- ����� �� ��������"<<endl;
	cout<<"6- ��� ������"<<endl;
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