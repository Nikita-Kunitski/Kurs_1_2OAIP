#include "iostream"
#define kol 30
#define ras 30

using namespace std;
int ch;
int lic=0;//�������� �������

struct avto
{
	char mark[kol];//����� ����
	char color[20];//����
	int data_v;//���� �������
	char kusov[20];//��� ������
	int nomer;//��������� �����
	int data_TO;//���� ��
	char vladelec[20];//��� ���������
};

struct avto A[ras];
struct avto pustota;

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

void TO()
{
	for(int i=0; i<lic; i++)
	{
		if((2016-A[i].data_v < 5))//��� ����� ������ 5 ���
		{
			if(2016-A[i].data_TO>=2)
				{
					cout<<endl;
					cout<<"��������, ����������, ������� ��"<<endl;
					cout<<"����� ���� ";
					cout<<A[i].mark<<endl;
					cout<<"���� ���� ";
					cout<<A[i].color<<endl;
					cout<<"���� ������� ���� ";
					cout<<A[i].data_v<<endl;
					cout<<"����� ���� ";
					cout<<A[i].kusov<<endl;
					cout<<"���� �� ���� ";
					cout<<A[i].data_TO<<endl;
					cout<<"��������� ����� ���� ";
					cout<<A[i].nomer<<endl;
					cout<<"�������� ���� ";
					cout<<A[i].vladelec<<endl;
				}
		}

		if((2016-A[i].data_v >= 5)&&(2016-A[i].data_v <= 10))//��� ����� ������ 10 ���, ������ 5
		{
			if(2016-A[i].data_TO>=1)
			{
				cout<<endl;
					cout<<"��������, ����������, ������� ��"<<endl;
					cout<<"����� ���� ";
					cout<<A[i].mark<<endl;
					cout<<"���� ���� ";
					cout<<A[i].color<<endl;
					cout<<"���� ������� ���� ";
					cout<<A[i].data_v<<endl;
					cout<<"����� ���� ";
					cout<<A[i].kusov<<endl;
					cout<<"���� �� ���� ";
					cout<<A[i].data_TO<<endl;
					cout<<"��������� ����� ���� ";
					cout<<A[i].nomer<<endl;
					cout<<"�������� ���� ";
					cout<<A[i].vladelec<<endl;
			}
		}
	}
		cout<<endl;
		cout<<"�������� �������� ";
		cin>>ch;

}

void vvod()
{
	cout<<"���� ����������"<<endl;
	if(lic<ras)
	{
		cout<<"������ �"<<lic+1<<endl;
		cout<<"������� ����� ���� ";
		cin >> A[lic].mark;
		cout<<"������� ���� ����";
		cin>> A[lic].color;
		cout<<"���� ������� ���� ";
		cin>> A[lic].data_v;
		cout<<"������� ��� ������ ���� ";
		cin>> A[lic].kusov;
		cout<<"������� ��������� ����� ���� ";
		cin>> A[lic].nomer;
		cout<<"������� ���� �� ���� ";
		cin>> A[lic].data_TO;
		cout<<"������� ��� ��������� ���� ";
		cin>> A[lic].vladelec;
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
	int a,b;
	cout<<"�������� ��������"<<endl;
	cout<<"1-����� ������������ ������"<<endl;
	cout<<"2-����� ���� ����������"<<endl;
	cin>>a;
	cout<<endl;
		if(a==1)
		{
		cout<<"����� ������ �������? ";
		cin>>b;
		cout<<"����� ���� ";
		cout<<A[b-1].mark<<endl;
		cout<<"���� ���� ";
		cout<<A[b-1].color<<endl;
		cout<<"���� ������� ���� ";
		cout<<A[b-1].data_v<<endl;
		cout<<"����� ���� ";
		cout<<A[b-1].kusov<<endl;
		cout<<"���� �� ���� ";
		cout<<A[b-1].data_TO<<endl;
		cout<<"��������� ����� ����";
		cout<<A[b-1].nomer<<endl;
		cout<<"�������� ���� ";
		cout<<A[b-1].vladelec<<endl;
		}
			if(a==2)
			{
				for(int i=0;i<lic;i++)
				{
					cout<<endl;
					cout<<endl;
					cout<<"����� ���� ";
					cout<<A[i].mark<<endl;
					cout<<"���� ���� ";
					cout<<A[i].color<<endl;
					cout<<"���� ������� ���� ";
					cout<<A[i].data_v<<endl;
					cout<<"����� ���� ";
					cout<<A[i].kusov<<endl;
					cout<<"���� �� ���� ";
					cout<<A[i].data_TO<<endl;
					cout<<"��������� ����� ���� ";
					cout<<A[i].nomer<<endl;
					cout<<"�������� ���� ";
					cout<<A[i].vladelec<<endl;
				}
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
	cout<<"1-����� �� ������ ����������"<<endl;
	cout<<"2-����� �� ��������� ���������� "<<endl;
	cin>>t;
	if (t==1)
	{
		cout<<endl;
		cout<<"������� ����� ���������� ";
		cin>>h;
		for(int i=0;i<lic;i++)
		{
			if(h==A[i].nomer)
			{
					cout<<"������ �"<<i+1<<endl;
					cout<<"����� ���� ";
					cout<<A[i].mark<<endl;
					cout<<"���� ���� ";
					cout<<A[i].color<<endl;
					cout<<"���� ������� ���� ";
					cout<<A[i].data_v<<endl;
					cout<<"����� ���� ";
					cout<<A[i].kusov<<endl;
					cout<<"���� �� ���� ";
					cout<<A[i].data_TO<<endl;
					cout<<"��������� ����� ���� ";
					cout<<A[i].nomer<<endl;
					cout<<"�������� ���� ";
					cout<<A[i].vladelec<<endl;
					o=o+1;
			}
		}
		if(o==0)
			cout<<"������������ �� �������"<<endl;
	}
	
	if(t==2)
	{
		cout<<"������� ��������� ���� ";
		gets(label);
		gets(label);
		for (int j=0; j<lic;j++)
		{
			if(strcmp(A[j].vladelec,label)==0)
			{
					cout<<"������ �"<<j+1<<endl;
					cout<<"����� ���� ";
					cout<<A[j].mark<<endl;
					cout<<"���� ���� ";
					cout<<A[j].color<<endl;
					cout<<"���� ������� ���� ";
					cout<<A[j].data_v<<endl;
					cout<<"����� ���� ";
					cout<<A[j].kusov<<endl;
					cout<<"���� �� ���� ";
					cout<<A[j].data_TO<<endl;
					cout<<"��������� ����� ���� ";
					cout<<A[j].nomer<<endl;
					cout<<"�������� ���� ";
					cout<<A[j].vladelec<<endl;
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
	cout<<"4- ��� ������ ������(��)"<<endl;
	cout<<"5- ��� ����������� �� ��"<<endl;
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
			case 5: TO();break;
		}
	}while(ch!=6);
}