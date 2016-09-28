#include <string>
#include <iostream>
#include <clocale>
#include <fstream>
using namespace std;

string insert_oo (string str)
{		
	for (int i = 0; i <= str.length(); i++)
		if(str[i]=='.')
		{
			str.insert(i, "...", 0, 2);
			i+=2;
		}
	return str;
}
int main ()
{
	setlocale (LC_ALL, "rus");
	ifstream file1("laba13.txt");
	ofstream file2("complete laba13.txt");
	string str;
	cout << "Текст в изначаальном файле:"<< endl;
	while (!file1.eof())
	{
		getline (file1, str);
		cout << str << endl;
		file2 << insert_oo (str) << endl;
	}
	cout << "________________________________" << endl << endl;
	ifstream file3("complete laba13.txt");
	cout << "Текст в конечном файле:" << endl;
    while (!file3.eof())
	{
		getline (file3, str);
		cout << str << endl;
    }
    system ("pause");
    return 0;
}
