#include <iostream>
using namespace std;
int main() {
	char tempChar; int rookChar,rookDigit;
	cout <<"Enter position of Rook:";     
	cin >> tempChar >> rookDigit;
	rookChar = tempChar - 96;--rookChar;--rookDigit;
	char a[8][8];
	for (int digit = 0; digit < 8; ++digit)
		for (int character = 0; character < 8; ++character)	
				a[digit][character] = character == rookChar && rookDigit == digit ?
				'L' : character == rookChar || rookDigit == digit ?
					'*' : '.';	
	ofstream out("output.txt");
	if(out.is_open()){
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j <8; ++j) cout << a[i][j];
		out << endl;
	}
	} else {cout << "File does not opened"; return 0;}
	out.close();
	ifstream in;
    in.open("output.txt");
    while (!in.eof()) in >> a[i][j];
    in.close();
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j <8; ++j) cout << a[i][j];
		cout << endl;
	}
	system("pause.exe");
	return 0;
}