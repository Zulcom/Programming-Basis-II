#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <cstdlib>
using namespace std;
bool pol(int buf)
{
	if (buf > 0) return 1;
	else return 0;
}
int rand(int pol)
{
	return rand() % pol + 1;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	struct node
	{
		int info;
		node *link;
	};
	node *verh, *yzel;
	int buf;
	verh = NULL;
	cout << "Введите число: ";
	cin >> buf;
	while (!feof(stdin))
	{
		yzel = new node;
		yzel->link = verh;
		yzel->info = buf;
		verh = yzel;
		cout << "Bведите число: ";
		cin >> buf;
	}
	cout << "Список: ";
	yzel = verh;
	while (yzel != NULL)
	{
		cout << yzel->info << ' ';
		yzel = yzel->link;
	}
	yzel = verh;
	node *newnode;
	while (yzel != NULL)
	{
		if (pol(yzel->info))
		{
			int pol = yzel->info;
			for (int i = 0; i < 3; i++)
			{
				newnode = new node;
				newnode->link = yzel->link;
				yzel->link = newnode;
				newnode->info = rand(pol);
				yzel = yzel->link;
			}
		}
		yzel = yzel->link;
	}
	cout << endl << "После добавления узлов: ";
	yzel = verh;
	while (yzel != NULL)
	{
		cout << yzel->info << ' ';
		yzel = yzel->link;
	}
	_getch();
	return 0;
}
