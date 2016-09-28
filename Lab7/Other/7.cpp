﻿#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;
struct journal
{
  string name,
		 theme;
  int coast, kol;//Информационные поля
   journal *next;//Указатель для связи с другим узлом
};
int main ()
{
	setlocale(LC_ALL, "russian");
	ifstream ft ("input.txt");
	journal *top1, *top2, *k1, *k2;
    top1 = NULL;
	top2 = NULL;//стеки пусты
	string namen, themen;//Буферные переменные
	int coastn, koln;
	printf ("Данные в текстовом файле:\n");
	printf ("____________________________________________________________\n");
	while(ft >> namen >> coastn >> koln >> themen)
	{
		cout.setf(ios::left);//равнение по левой границе
		cout.width(15);//ширина поля 15 позиций
		cout << namen;
		cout.width(5);
		cout << coastn;
		cout.width(20);
		cout << koln;
		cout.width(20);
		cout << themen << endl;
	}

	    if (koln>0)
        {
             k1 = new journal; //выделение динамической памяти
             k1 -> next = top1;//связь с предыдущим узлом
             k1 -> name = namen; //заполняем информационное поле
             k1 -> coast = coastn; 
             k1 -> kol = koln; 
             k1 -> theme = themen; 
			 top1 = k1; //Вершину стека помещаем на вновь созданный узел
			 
        }
		else         
		{
             k2 = new journal; 
             k2 -> next = top2;
             k2 -> name = namen; 
             k2 -> coast = coastn; 
             k2 -> kol = koln; 
             k2 -> theme = themen; 
			 top2 = k2;
			  
        }
	
FILE *fbw1, *fbw2;
char namef1[11], namef2[11];
printf ("____________________________________________________________\n");
cout << "Введите имя файла для записи журналов тиражом менее 1000 экземпляров:" << endl;
cin >> namef1;
cout << "Введите имя файла для записи остальных журналов:" << endl;
cin >> namef2;
fbw1 = fopen(namef1, "wb");
fbw2 = fopen(namef2, "wb");
rewind(fbw1);
rewind(fbw2);
k1 = top1;//указатель на вершину стека
while (k1 != NULL)//пока не достигли конца стека
{
	fwrite (&k1 -> name, sizeof(string), 1, fbw1);
	fwrite (&k1 -> coast, sizeof(int), 1, fbw1);
	fwrite (&k1 -> kol, sizeof(int), 1, fbw1);
	fwrite (&k1 -> theme, sizeof(string), 1, fbw1);
	k1 = k1 -> next;//перемещение к следующему узлу
}
k2 = top2;
while (k2 != NULL)
{
	fwrite (&k2 -> name, sizeof(string), 1, fbw2);
	fwrite (&k2 -> coast, sizeof(int), 1, fbw2);
	fwrite (&k2 -> kol, sizeof(int), 1, fbw2);
	fwrite (&k2 -> theme, sizeof(string), 1, fbw2);
	k2 = k2 -> next;
}
fclose(fbw1);
fclose(fbw2);
fbw1 = fopen(namef1, "rb");
fbw2 = fopen(namef2, "rb");
rewind(fbw1);
rewind(fbw2);
cout <<endl << "Журналы с тиражом менее 1000:" << endl;
k1 = new journal;
printf ("____________________________________________________________\n");
while (fread (&k1 ->name, sizeof(string), 1, fbw1) && fread (&k1 ->coast, sizeof(int), 1, fbw1) && fread (&k1 ->kol, sizeof(int), 1, fbw1) && fread (&k1 ->theme, sizeof(string), 1, fbw1))
{
	    k1 -> next = top1;
	    cout.setf(ios::left);
		cout.width(15);
		cout << k1 -> name << ' ';
		cout.width(5);
		cout << k1 -> coast;
		cout.width(20);
		cout << k1 -> kol;
		cout.width(20);
		cout << k1 -> theme << endl;
}
printf ("____________________________________________________________\n");
cout << endl << "Другие журналы:" << endl;
printf ("____________________________________________________________\n");
k2 = new journal;
while (fread (&k2 ->name, sizeof(string), 1, fbw2) && fread (&k2 ->coast, sizeof(int), 1, fbw2) && fread (&k2 ->kol, sizeof(int), 1, fbw2) && fread (&k2 ->theme, sizeof(string), 1, fbw2))
{
		k2 -> next = top2;
	    cout.setf(ios::left);
		cout.width(15);
		cout << k2 -> name;
		cout.width(5);
		cout << k2 -> coast;
		cout.width(20);
		cout << k2 -> kol;
		cout.width(20);
		cout << k2 -> theme << endl;
}
printf ("____________________________________________________________\n");
system ("pause");
return 0;
}
