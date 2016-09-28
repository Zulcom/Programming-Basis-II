#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
using namespace std;
bool compare(int a, int b){return b>a;}
bool negative(int a){return a<0;}
void printSeq(list<int> data){
	std::list<int>::iterator p; // list такое множество в которое можно записывать данные любого типа
	for (p = data.begin(); p != data.end(); ++p) cout << *p << " "; 
}
int main()
{
	list<int> data;
	list<int>::iterator p;
	ifstream in;
	in.open("input.txt", ios::in);
	if (!in.is_open()) cout << "File was not founded!"; 
	int DigFromFile;
	while (!in.eof()){
		in >> DigFromFile;
		data.push_back(DigFromFile);
	}
	cout << "Sequence: " <<endl;
	printSeq(data); cout << endl;
	cout << endl <<"Sequence without negative digits: " <<endl;
	p = remove_if(data.begin(), data.end(), negative);		
	data.erase(p, data.end());	 
	printSeq(data);
	data.sort(compare);
	cout << endl <<"Sorted sequence in increase:" <<endl;
	printSeq(data);
	system("pause.exe");
}