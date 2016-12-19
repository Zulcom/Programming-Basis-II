#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <clocale>
#include <iomanip>
#include <conio.h>
#define M_PI 3.14159265358979323846
using namespace std;
double arctg(double x)
{
	return atan(x)*atan(x);
}
double sinus(double x)
{
	return sin(exp(x));
}
double exponenta(double x)
{
	return exp(-1 * x * x);
}
double(*integral[3])(double) = { arctg, sinus, exponenta };
double rectangle(double(*f)(double), double niz, double verh, double E)
{
	double sum = 0, predsum = 0;
	int n = 10;
	double h = (verh - niz) / n;
	double x = niz + h;
	for (int i = 1; i <= n; ++i)
	{
		double b = f(x);
		sum += b;
		x += h;
	}
	sum *= h;
	while (abs((sum - predsum) / 4) > E)
	{
		n *= 2;
		predsum = sum;
		sum = 0;
		h = (verh - niz) / n;
		x = niz + h;
		for (int i = 1; i <= n; ++i)
		{
			double b = f(x);
			sum += b;
			x += h;
		}
		sum *= h;
	}
	return sum;
}
int main()
{
	setlocale(LC_ALL, "russian");
	double a, b, c, d, E;
	cout << "Введите пределы интегрирования:" << endl;
	cout << "a и b , где b > a: ";
	cin >> a >> b;
	cout << "c и d, где d > c: ";
	cin >> c >> d;
	cout << "Введите точность вычисления: ";
	cin >> E;
	while (true)
	{
		if (a > b || c > d)
		{
			cout << "Значения введены неверно. Введите заново!" << endl << endl;
			cout << "Введите пределы интегрирования:" << endl;
			cout << "a и b , где b > a: ";
			cin >> a >> b;
			cout << "c и d, где d > c: ";
			cin >> c >> d;
			cout << "Введите точность вычисления: ";
			cin >> E;
		}
		else break;
	}
	double summa = 0;
	summa += rectangle(integral[0], c, d, E);
	summa += rectangle(integral[1], 0, M_PI, E);
	summa += rectangle(integral[2], a, b, E);
	cout << "Сумма интегралов по правилу правых прямоугольников равна: " << summa;
	_getch();
	return 0;
}
