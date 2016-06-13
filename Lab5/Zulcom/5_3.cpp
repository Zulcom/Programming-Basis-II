#include <string> 
#include <iostream> 
#include <clocale> 
#include <fstream>
using namespace std;

struct user
{
	char surname[100];
	char nick[100];
	char password[100];
	bool isActive;
};

/*
* Функция рассчёта количества строк в файле 
*/
void countLines(int* lines)
{
	ifstream in("in.txt");
	if (!in) cout << "file cant open for read";
	string temp;
	while (in >> temp) ++*lines;
	*lines = *lines / 4;
	in.close();
}

user* readData(int* lines)
{
	ifstream in("in.txt");
	if (!in) cout << "file cant open for read";
	user* db = new user[*lines];
	char* status = new char[13];
	for (int i = 0; i < *lines; ++i)
	{
		in >> db[i].surname
			>> db[i].nick
			>> db[i].password
			>> status;
		db[i].isActive = ('а' == status[0]);
	}
	in.close();
	delete[] status;
	return db;
}


int main()
{
	// init

	char filename[30];
	int lines = 0;
	int writenCounter = 0;
	char* buffer = new char[256];

	//setup

	setlocale(LC_ALL, "Russian");
	countLines(&lines);

	//print in.txt file
	ifstream readFile("in.txt"); 
	if (!readFile) cout << filename << " cant open for read"; 
	while (readFile.getline(buffer, 256))
		cout << buffer << endl; 
	readFile.close(); 
	
	//create database for users and fill it
	user* db = readData(&lines);

	// sort by alph
	for (int i = 0; i < lines; ++i)
		for (int j = 0; j < lines; ++j)
			if (db[i].surname[0] < db[j].surname[0])
			{
				user temp = db[j];
				db[j] = db[i];
				db[i] = temp;
			}

	// write filtered and sorted data to bin file
	cout << "Введите имя файла: "; cin >> filename;
	fstream bin(strcat(filename, ".bin"), ios::binary | ios::out);
	if (!bin.is_open()) cout << "Бинарник не открыт"; // check if not open
	for (int i = 0; i < lines; i++)
		if (db[i].isActive)
		{
			bin.write((char*) &db[i], sizeof(user));
			writenCounter++;
		}
	bin.seekg(0, ios::beg);

	//print data from bin
	for (int i = 0; i < writenCounter; i++)
	{
		bin.read((char*) &db[i], sizeof(user));
		cout << db[i].surname << " " << db[i].nick << " " << db[i].password << " " << "Активен" << "\n";
	}
	bin.close();

	system("pause.exe");
	//clean RAM
	delete[] buffer;
	delete[] db;
	return 0;
}