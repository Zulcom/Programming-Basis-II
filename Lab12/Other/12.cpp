#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;
float e = 2.71;

float InFunction1(float x)
{
	return pow(arctg(x), 2);
}
float InFunction3(float x)
{
	return sin(pow(e, x));
}
float InFunction3(float x) 
{
	return pow(e,(-(x*x))); 
}

float CalcIntegral(float a, float b, int n)
{
  int i;
  float result1, result2, result3 h;

  float result = 0;

  float h = (b - a) / n; //Ўаг сетки
  float h2 = (d - c)/n;
  float h3 = (3.14 - 0)/n;

  for(i = 0; i < n; i++)
  {
    result1 += InFunction1((a + h * (i + 0.5));
	result2 += InFunction2((c + h)* (i + 0.5));
	result3 += InFunction3((0 + h)* (i + 0.5));

  }

  result1 *= h;
  result2 *=h;
  result3 *=h;
  result = result1+result2+result3;

  return result;
}
 
int main(void)
{
  float integral;
  float a, b;
  int n;
  cout<<"vz";
  cin>>a>>b>>n;
  integral = CalcIntegral(a, b, n);
  printf("The value of the integral is: %lf \n", integral);
  system("pause");
  return 0;
}