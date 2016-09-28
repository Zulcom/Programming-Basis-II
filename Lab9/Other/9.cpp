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
	cout<<"Введите число:"<<endl;
	cin>>x;
	while(x==0)
	{
		cout<<"Число не должно быть нулевым, введите другое."<<endl;
		cin>>x;
	}
	cout<<"Введите степень, в которую хотите возвести число"<<endl;
	cin>>n;
    cout<<"Полученное число из рекурсивной функции:"<<rekurs(x, n)<<endl;
	cout<<"Число из нерекурсивнойx:"<<F(x, n)<<endl;;
	system("pause");
}