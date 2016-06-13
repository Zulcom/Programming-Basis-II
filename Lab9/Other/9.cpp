#include<iostream>
#include <clocale>
#include<cmath>

using namespace std;

float rekurs(float a, int b)
{
	if (b<0)
 {
  return 1.0/rekurs(a, -b);
 }
 if (b==0)
 {
  return 1.0;
 }
 return a*rekurs(a, b-1);
}
float F(float a, int b)
{
	float a1;
	a1=a;
	if(b==0)
		return 1;
	if(b<0)
	{
		while(-b!=1)
		{
			a=a*a1;
			b--;
		}
		a=1/a;
		return a;
	}
	if(b>0)
	{
	while(b!=1)
	{
		a=a*a1;
		b--;
	}
    return a;
	}
}

void main()
{
	setlocale(LC_ALL, "russian");
	int n;
	float x, x1;
	cout<<"������� �����:"<<endl;
	cin>>x;
	while(x==0)
	{
		cout<<"����� �� ������ ���� �������, ������� ������."<<endl;
		cin>>x;
	}
	cout<<"������� �������, � ������� ������ �������� �����"<<endl;
	cin>>n;
    cout<<"���������� ����� �� ����������� �������:"<<rekurs(x, n)<<endl;
	cout<<"����� �� �������������x:"<<F(x, n)<<endl;;
	system("pause");
}