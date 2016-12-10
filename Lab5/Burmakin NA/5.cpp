#include <iostream>
#include <fstream>

using namespace std;

struct Students
{
	char Familia[100];
	int Vozrast;
	int Kurs;
	char VoenKafedra[100];
};

int main() {
	Students* students = new Students[10];
	ifstream in("in.txt");
	int counter=0;
	setlocale(LC_ALL, "Russian");
	if(!in.is_open()) cout << "File cant be open";
	for (int i=0; i<10; i++)
		in >> students[i].Familia >>students[i].Vozrast >> students[i].Kurs >> students[i].VoenKafedra;
	in.close();
	ofstream out("out.bin", ios::binary);
	if(!out.is_open()) cout << "File cant be open";
	for(int i = 0; i < 10; i++)
		if(students[i].Kurs == 1)
		{
			out.write((char*) &students[i], sizeof(students));
			counter++;
		}
	out.close();
	ifstream input("in.txt");
	ifstream inputBin("out.bin", ios::binary);
	if(!input.is_open() || !inputBin.is_open()) cout << "File cant be open";
	for(int i = 0; i < 10; i++)
	{
		input >> students[i].Familia >> students[i].Vozrast >> students[i].Kurs >> students[i].VoenKafedra;
		cout  << students[i].Familia << " " << students[i].Vozrast << " " << students[i].Kurs << " " << students[i].VoenKafedra <<endl;
		inputBin.read((char*) &students[i], sizeof(students));
		
	}
	cout << endl << endl;
	for(int i = 0; i < counter; i++)
	{
		inputBin.read((char*) &students[i], sizeof(students));
		cout << students[i].Familia << " " << students[i].Vozrast << " " << 1 << " " << students[i].VoenKafedra << endl;
	}
	input.close();
	inputBin.close();
	delete[] students;
	system("pause.exe");
	return 0;
}