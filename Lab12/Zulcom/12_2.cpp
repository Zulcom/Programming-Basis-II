#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <clocale>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;
// ��� ��������������� �������
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
* ������� ���������� �������������� ������� ���������������.
* ���������: ��������������� ������� f, ������� �������������� niz,verh, �������� ���������� TO4HOCTb
* ���������� ��������� n � ���������� ����� prevsum
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
* ������� ���������� �������������� �� ������� 3/8 ��������.
* ���������: ��������������� ������� f, ������� �������������� niz,verh, �������� ���������� TO4HOCTb
* ���������� ��������� n � ���������� ����� prevsum
*/
double threeEighths(double(*f)(double), double niz, double verh, double TO4HOCTb)
{

	int n = 10; // ���������� ���������
	double h = (verh - niz) / n; // ���
	double sum_2 = 0; // ����� ��� ��������� �� 2
	double sum_3 = 0; // ����� ��� ��������� �� 3
	for(int i = 1; i <= n - 1; i++)
	{
		sum_2 += f(niz + h*i);
	}
	for(int i = 0; i <= n - 1; i++)
	{
		sum_3 += f(niz + i*h + h / 3) + f(niz + i*h + (2 * h) / 3);
	}
	double sum = h / 8 * (f(verh) + f(niz) + 2 * sum_2 + 3 * sum_3); // �������� �����
	double prevsum = 0; // ����� ��� ���������� ����� 0, ����� ��������� ��������
	while(abs((sum - prevsum) / 15) > TO4HOCTb) // ��������� �������� �� ������� �����
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
//��� �������� ��� ���������� ��������� = ���������� �������
double(*integral[3])(double) = {arctg, sinus, exponenta};

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b, c, d, TO4HOCTb = 0.1;
	cout << "������� ������� �������������� a, b (b>a) � c, d (d>c) � ��������" << endl;

	cin >> a >> b >> c >> d >> TO4HOCTb;

	while(true)
	{
		if(a > b || c > d)
		{
			cout << "�������� ������� �������. ������� ������.";
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
	cout << "����� ���������� �� ������� ��������������: " << rectangleSum << endl;
	cout << "����� ���������� �� ������� 3/8: " << threeEighthsSum << endl;
	cout << "������� � �����������:" << abs(rectangleSum - threeEighthsSum) << endl;

	system("pause");
	return 0;
}