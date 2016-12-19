#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <cstdlib>
#include <string.h>
using namespace std;
bool sravnenie(char *city1, char *city2)
{
	if (strlen(city1) == strlen(city2))
	{
		for (int i = 0; i < strlen(city1); i++)
		{
			if (city1[i] != city2[i]) return 0;
		}
		return 1;
	}
	else return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	struct node
	{
		char surname[15];
		int year;
		char city[15];
		char education[25];
		node *link;
	};
	node *verh, *yzel;
	ifstream txt("Ishod.txt");
	verh = NULL;
	while (!txt.eof())
	{
		yzel = new node;
		yzel->link = verh;
		txt >> yzel->surname;
		txt >> yzel->year;
		txt >> yzel->city;
		txt >> yzel->education;
		verh = yzel;
	}
	txt.close();
	cout << "Текстовый файл:" << endl;
	yzel = verh;
	cout << "Фамилия:" << "	" << "Возраст:" << "	" 
		<< "Город:" << "		" << "Образование:" << endl;
	while (yzel != NULL)
	{
		cout << yzel->surname << "	" << yzel->year << "		" 
			<< yzel->city << "	" << yzel->education << endl;
		yzel = yzel->link;
	}
	yzel = verh;
	char city[15];
	cout << "Введите название города: ";
	cin >> city;
	node *newnode;
	while (yzel != NULL)
	{
		if (!sravnenie(yzel->city, city))
		{
			if (yzel == verh)
			{ // Если совпавший - вершина
				verh = yzel->link;
				delete yzel;
				yzel = verh;
			}
			else
			{ // Ecли совпавший - не веpшина
				newnode->link = yzel->link;
				delete yzel;
				yzel = newnode->link;
			}
		}
		else
		{ // Eсли не совпавший
			newnode = yzel;
			yzel = yzel->link;
		}
	}
	newnode = verh;
	ofstream bin_write("End.txt", ios::binary);
	while (yzel != NULL)
	{
		bin_write << yzel->surname << ' ' << yzel->year 
			<< ' ' << yzel->city << ' ' << yzel->education;
		delete yzel;
		newnode = yzel->link;
	}
	bin_write.close();
	ifstream bin_read("End.txt", ios::binary);
	while (!bin_read.eof())
	{
		yzel = new node;
		yzel->link = verh;
		bin_read >> yzel->surname;
		bin_read >> yzel->year;
		bin_read >> yzel->city;
		bin_read >> yzel->education;
		verh = yzel;
	}
	bin_read.close();
	cout << "Двоичный файл:" << endl;
	cout << "Фамилия:" << "	" << "Возраст:" << "	"
		<< "Город:" << "		" << "Образование:" << endl;
	yzel = verh;
	while (yzel != NULL)
	{
		cout << yzel->surname << "	" << yzel->year << "		"
			<< yzel->city << "	" << yzel->education << endl;
		yzel = yzel->link;
	}
	_getch();
	return 0;
}
