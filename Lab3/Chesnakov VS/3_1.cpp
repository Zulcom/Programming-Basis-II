#define SEEK_SET 0
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<clocale>
#include<fstream>
using namespace std;
int func(int *al, int m)
{
	int i = 0, prz = 1;
	for (i = 0; i < m; i++)
	{
		if (al[i]%3==0)
		{
			prz = prz*al[i];
		}
	}
	return prz;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0, m = 0, s;
	FILE *in, *out;
	out = fopen("out.txt", "r");
	in = fopen("in.dat", "wb+");
	cout << "Введите s строку:";
	cin >> s;
	fscanf(out, "%d%d", &n, &m);
	fwrite(&n, sizeof(int), 1, in);
	fwrite(&m, sizeof(int), 1, in);
	int *a = new int[m], 
		*a1 = new int[m];
	cout << "\nМассив:";
	for (int i = 0; i < m*n; i++)
	{
		fscanf(out, "%d", &a[i]);
		fwrite(&a[i], sizeof(int), 1, in);
		cout << " " << a[i];
	}
	fseek(in, ((s - 1)*m + 2)*sizeof(int), SEEK_SET);
	fread(a1, sizeof(a1), m, in);
	cout << "\nСтрока:";
	for (int i = 0; i < m; i++)
		cout << a1[i] << " ";
	int p = func(a1, m);
	if (p == 1)
		cout << "Чисел кратных 3 нет";
	else
		cout << endl << "Произведение равно:" << p ;
	getchar();
	getchar();
	return 0;
}
