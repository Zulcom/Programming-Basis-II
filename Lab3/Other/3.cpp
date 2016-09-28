#include <windows.h>
#include <fstream>
#include<iostream>
#include<clocale>

using namespace std;
int kol(int*arr, int m)
{
	int k = 0;
	for(int i=0; i<m; i++)
	{
		if(arr[i]<100)
		k=k+1;
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "russian");
	int n, m, k;
	FILE *f1, *f2, *f3;
	f1 = fopen("1.txt", "r");
	f2 = fopen("2.txt", "w");
	fscanf(f1, "%i", &n);
	fscanf(f1, "%i", &m);
	int *A = new int[m];
	cout<<"Ваш массив:"<<endl;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			int znach;
			fscanf(f1, "%i", &znach);
			A[j]=znach;
			cout<<znach<<" ";
		}
		fwrite(A, sizeof(A), m, f2);
		cout<<endl;
	}
	fclose(f1);
	fclose(f2);
	cout<<"Введите номер строки:"<<endl;
	cin>>k;
	k--;
	if(k>=n)
	{
		cout<<"Ошибка"<<endl;
		system("pause");
		return 0;
	}
f3 = fopen("2.txt", "r");
int t = k*m*sizeof(int);
fseek(f3, t, SEEK_SET);
fread(A, sizeof(A), m, f3);
int kl = kol(A, m);
cout<<"Количество чисел меньше 100:"<<kl;
system("pause");
return 0;
}