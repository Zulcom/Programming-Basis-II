#include<iostream>
using namespace std;

void main()
{
	int w;
	int i=0;
	FILE *in;
	int mass[100];
	in = fopen("inp.txt", "r");
	while(!feof(in))
	{
	   mass[i] = fscanf(in, "%d", &w);
	   i++;
	}
	for(int j =0; i<i; j++)
		cout<<mass[j];
	system("pause");
}
