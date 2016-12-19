#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <clocale>
using namespace std;
int dlina_rec(int i, double n)
{
	if (n < 1)
		return i;
	return dlina_rec(++i, n / 10);
}
int dlina_no_rec(double n)
{
	int i = 0;
	while (n > 1)
	{
		n = n / 10;
		++i;
	}
	return i;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double n;
	cout << "Введите строку цифр: ";
	cin >> n;
	cout << "Вычисленное количество цифр:" << endl << endl;
	cout << "С помощью рекурсивной функции: ";
	cout << dlina_rec(0, n) << endl;
	cout << "С помощью нерекурсивной функции: ";
	cout << dlina_no_rec(n);
	_getch();
	return 0;
}
