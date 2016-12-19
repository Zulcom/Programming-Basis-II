#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
using namespace std;
struct students
{
	char surname[20];
	int year;
	int curs;
	char voenka[3];
} spisok[10];
char proverka(struct students *spisok)
{
	if ((spisok->year < 18) && (spisok->voenka[0] == 'Д'))
	{
		ofstream bin("End.txt", ios::binary | ios::app);
		bin << spisok->surname << "		" << spisok->year << "		"
			<< spisok->curs << "	" << spisok->voenka << endl;
		bin.close();
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	ifstream txt("Ishod.txt");
	while (!txt.eof())
	{
		txt >> spisok[n].surname;
		txt >> spisok[n].year;
		txt >> spisok[n].curs;
		txt >> spisok[n].voenka;
		n++;

	}
	txt.close();
	cout << "Текстовый файл:" << endl;
	cout << "Фамилия:" << "	" << "Возраст:" << "	" 
		<< "Курс:" << "	" << "Военка:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << spisok[i].surname << "		";
		cout << spisok[i].year << "		";
		cout << spisok[i].curs << "	";
		cout << spisok[i].voenka << "	";
		cout << endl;
	}
	for (int i = 0; i < n; i++) proverka(&spisok[i]);
	ifstream read("End.txt", ios::binary);
	char *mass = new char[256];
	cout << "Двоичный файл:" << endl;
	cout << "Фамилия:" << "	" << "Возраст:" << "	"
		<< "Курс:" << "	" << "Военка:" << endl;
	while (!read.eof())
	{
		read.getline(mass, 256);
		cout << mass << endl;
	}
	_getch();
	return 0;
}