#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <clocale>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;
// три подинтегральные функции
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
/*
* Функция численного интегрирования методом прямоугольников.
* Аргументы: подинтегральная функция f, пределы интегрирования niz,verh, точность вычислений TO4HOCTb
* Количество разбиений n и предыдущаЯ сумма prevsum
*/
double rectangle(double(*f)(double), double niz, double verh, double TO4HOCTb)
{
	double sum = 0, prevsum = 0;
	int n = 10;
	double h = (verh - niz) / n;
	double x = niz + h;
	for(int i = 0; i < n; ++i)
	{
		double b = f(x);
		sum += b;
		x += h;
	}
	sum *= h;
	while(abs((sum - prevsum) / 4) > TO4HOCTb)
	{
		n *= 2;
		prevsum = sum;
		sum = 0;
		h = (verh - niz) / n;
		x = niz + h;
		for(int i = 0; i < n; ++i)
		{
			double b = f(x);
			sum += b;
			x += h;
		}
		sum *= h;
	}
	return sum;
}

/*
* Функция численного интегрирования по правилу 3/8 Симпсона.
* Аргументы: подинтегральная функция f, пределы интегрирования niz,verh, точность вычислений TO4HOCTb
* Количество разбиений n и предыдущая сумма prevsum
*/
double threeEighths(double(*f)(double), double niz, double verh, double TO4HOCTb)
{

	int n = 10; // количество разбиений
	double h = (verh - niz) / n; // шаг
	double sum_2 = 0; // сумма для умножения на 2
	double sum_3 = 0; // сумма для умножения на 3
	for(int i = 1; i <= n - 1; i++)
	{
		sum_2 += f(niz + h*i);
	}
	for(int i = 0; i <= n - 1; i++)
	{
		sum_3 += f(niz + i*h + h / 3) + f(niz + i*h + (2 * h) / 3);
	}
	double sum = h / 8 * (f(verh) + f(niz) + 2 * sum_2 + 3 * sum_3); // итоговая сумма
	double prevsum = 0; // задаём как предыдущую сумму 0, чтобы программа работала
	while(abs((sum - prevsum) / 15) > TO4HOCTb) // проверяем точность по правилу Рунге
	{
		n *= 2;
		prevsum = sum;
		h = (verh - niz) / n;
		sum_2 = 0;
		sum_3 = 0;
		for(int i = 1; i <= n - 1; i++)
		{
			sum_2 += f(niz + h*i);
		}
		for(int i = 0; i <= n - 1; i++)
		{
			sum_3 += f(niz + i*h + h / 3) + f(niz + i*h + (2 * h) / 3);
		}
		sum = h / 8 * (f(verh) + f(niz) + 2 * sum_2 + 3 * sum_3);

	}
	return sum;
}
//тип возврата имя переменной аргументы = присвоение массива
double(*integral[3])(double) = {arctg, sinus, exponenta};

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b, c, d, TO4HOCTb = 0.1;
	cout << "Введите пределы интегрирования a, b (b>a) и c, d (d>c) и точность" << endl;

	cin >> a >> b >> c >> d >> TO4HOCTb;

	while(true)
	{
		if(a > b || c > d)
		{
			cout << "Значения введены неверно. Введите заново.";
			cin >> a >> b >> c >> d;
		}
		else break;
	}
	double rectangleSum = 0, threeEighthsSum = 0;

	rectangleSum += rectangle(integral[0], c, d, TO4HOCTb);
	rectangleSum += rectangle(integral[1], 0, M_PI, TO4HOCTb);
	rectangleSum += rectangle(integral[2], a, b, TO4HOCTb);

	threeEighthsSum += threeEighths(integral[0], c, d, TO4HOCTb);
	threeEighthsSum += threeEighths(integral[1], 0, M_PI, TO4HOCTb);
	threeEighthsSum += threeEighths(integral[2], a, b, TO4HOCTb);

	cout <<  setprecision(16);
	cout << "Сумма интегралов по правилу прямоугольника: " << rectangleSum << endl;
	cout << "Сумма интегралов по правилу 3/8: " << threeEighthsSum << endl;
	cout << "Разница в вычислениях:" << abs(rectangleSum - threeEighthsSum) << endl;

	system("pause");
	return 0;
}