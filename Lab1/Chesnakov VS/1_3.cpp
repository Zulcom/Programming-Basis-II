#include <conio.h>
#include <clocale>
#include <iostream>
#include <fstream>
using namespace std;
void main()
{
		 ofstream file("out.txt");
	setlocale(LC_ALL, "russian");
	const int N1 = 100, M1 = 100; 
int a [N1][M1], i=0, j=0, n, m;
cout<<"Введите число стpок и столбцов массива:";
cin>>n>>m;
	for (i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
	a[i][j]=i*j;
file << a[i][j] << " ";
}
			      
file << endl; }
	 file.close();
	 ifstream rez("out.txt");
cout<<" Полученный массив \n"<<endl;
	 for (int i=0; i<n; i++) {
		 for (int j=0; j<m; j++) {
			 rez >> a[i][j];
			 cout << a[i][j] << " ";}
		 cout << endl; }
	 rez.close();
	 getch();

}
