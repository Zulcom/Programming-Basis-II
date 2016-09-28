#include<conio.h>
#include<windows.h>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

void function(char *s)

{
	char p =0;
	for(int i = 0; i<strlen(s)-1; i++)
	{
		if(s[i]==p)
			continue;
		p = s[i];
		s[i]=s[i+1];
		s[i+1]=p;
	}
}

int main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	char str[100];
	char *s = new char[200];
	ifstream in ("inp.txt");
	ofstream ou ("out.txt");
	ifstream ou1 ("out.txt");
	if(in!=NULL)
	{
	puts("Входные данные из файла:");
	while(!in.eof())
	{
		in.getline(s, 200);
		puts(s);
		function(s);
		ou<<s<<endl;
	}
	puts("Выходные данные из файла:");
	while(!ou1.eof())
	{
		ou1.getline(str, 100);
		puts(str);
	}
	ou1.close();
	ou.close();
	in.close();
	}
	else
		puts("Фаил не найден"); 
	system("pause");
	return 0;
}




