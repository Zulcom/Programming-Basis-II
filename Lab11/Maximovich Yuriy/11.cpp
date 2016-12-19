#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <string>
using namespace std;
string cifra(string str, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (str[i] == '1' && (i + 1) % 2 == 0)
			str[i] = '2';
		if (str[i] == '1' && (i + 1) % 2 == 1)
			str[i] = '3';
	}
	return str;
}
string znak(string str, int size)
{
	if (str[0] != ' ')
		str[0] = '#';
	for (int i = 1; i < size; ++i)
		if (str[i - 1] == ' ')
			str[i] = '#';
	return str;
}
string sort(string str, int size)
{
	for (int i = 0; i < size / 2; ++i)
		swap(str[i], str[size - i]);
	return str;
}
string(*function[3])(string, int) = { cifra, znak, sort };
int main()
{
	setlocale(LC_ALL, "Russian");
	int nomer, size;
	string str, file;
	cout << "Введите название обрабатываемого файла: ";
	cin >> file;
	ifstream txt(file + ".txt");
	ofstream out("New " + file + ".txt");
	if (!txt.is_open())
	{
		cout << "Невозможно открыть текстовый файл. " << endl;
		_getch();
		return 0;
	}
	cout
		<< "1 - Замена единиц. " << endl
		<< "2 - Замена первых букв слов." << endl
		<< "3 - Зеркальная замена по вертикали." << endl
		<< "4 - Выход из программы." << endl << endl
		<< "Введите номер пункта меню: ";
	cin >> nomer;
	while (nomer < 1 || nomer > 4)
	{
		cout << "Такого пункта нет! Введите еще раз: ";
		cin >> nomer;
	}
	if (nomer == 4)
		exit(0);
	while (getline(txt, str))
	{
		size = str.size();
		str = (*function[nomer - 1])(str, size);
		out << str << endl;
	}
	txt.close();
	out.close();
	cout << endl << "Файл успешно обработан!";
	_getch();
	return 0;
}
