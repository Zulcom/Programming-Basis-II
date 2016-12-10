#include <iostream>
using namespace std;
double nereccursiv(double x,int n) {
	int a=x;
	double c;
	if(n > 0)
	{
		for(int i = 0; i < n-1; i++)
		{
			x = x*a;
		}
		return x;
	}

	if (n==0)
	return 1;

	if(n < 0)
	{
		for(int i = 0; i < abs(n)-1; i++)
		{
			x= x*a;
		}
		x = 1 / x;
		return x;
	}	
}

double reccursiv(double x, int n)
{
	if(n == 0)
		return 1;
	if(n > 0)
		return x*reccursiv(x, n - 1);
	if(n < 0)
		return 1/(x * reccursiv(x, abs(n) - 1));
}

void main() {
	int n;
	double x;
	cin >> x; cin >> n;
	cout <<"x^n nerecursiv="<< nereccursiv(x, n)<<endl;
	cout <<"x^n recursiv="<< reccursiv(x, n)<<endl;
	system("pause.exe");
}