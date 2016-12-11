
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

void podshet(int*A, int M)
{
	for(int i = 0; i < M; i++)
	{
		if(A[i]%7==0)
			A[i]*=2;
	}
}
void printFromBin(string s)
{
	ifstream in(s, ios::binary);
	if(!in.is_open()) cout << "sample.bin cant open for read.";
	int n, m;
	in.read(reinterpret_cast<char*>(&n), sizeof(n));
	in.read(reinterpret_cast<char*>(&m), sizeof(m));
	cout << n << " " << m << endl;
	int* ioBuffer = new int[m];
	for(int i = 0; i < n; i++)
	{
		in.read(reinterpret_cast<char*>(ioBuffer), sizeof(ioBuffer[0])*m);
		for(int j = 0; j < m; j++)
			cout << ioBuffer[j] << " ";
		cout << endl;
	}
	delete[] ioBuffer;
	in.close();
}
void copyToBin(int* dementions)
{
	ifstream in("in.txt");
	if(!in.is_open()) cout << "In.txt cant open";
	int N, M;
	in >> N >> M;
	dementions[0] = N;
	dementions[1] = M;
	ofstream binOut("sample.bin", ios::binary);
	if(!binOut.is_open()) cout << "sample.bin cant open for write";
	binOut.write(reinterpret_cast<char*>(&N), sizeof(N));
	binOut.write(reinterpret_cast<char*>(&M), sizeof(M));
	int* ioBuffer = new int[M];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			in >> ioBuffer[j];
		binOut.write(reinterpret_cast<char*>(ioBuffer), sizeof(ioBuffer[0])*M);
	}
	delete[] ioBuffer;
	in.close();
	binOut.close();
}
int* getMatrixRow(int k, int n, int m)
{
	ifstream binIn("sample.bin", ios::binary);
	if(!binIn.is_open()) cout << "sample.bin cant open for read";
	binIn.seekg(sizeof(int) * 2, ios::beg);
	int* row = new int[m];
	binIn.seekg(sizeof(int)*(2 + (k - 1) * m), ios::beg);
	binIn.read(reinterpret_cast<char*>(row), sizeof(row[0])*m);
	binIn.close();
	return row;
}

void insertRowBin(int*A, int k)
{
	ifstream in("sample.bin", ios::binary);
	ofstream out("UpBin.bin", ios::binary);
	if(!in.is_open() || !out.is_open()) cout << "sample.bin cant open for read.";
	int n, m;
	in.read(reinterpret_cast<char*>(&n), sizeof(n));
	in.read(reinterpret_cast<char*>(&m), sizeof(m));
	out.write(reinterpret_cast<char*>(&N), sizeof(N));
	out.write(reinterpret_cast<char*>(&M), sizeof(M));
	int* ioBuffer = new int[m];
	for(int i = 0; i < n; i++)
	{
		if(k == i) ioBuffer = A;
		else
		in.read(reinterpret_cast<char*>(ioBuffer), sizeof(ioBuffer[0])*m);
		out.write(reinterpret_cast<char*>(ioBuffer), sizeof(ioBuffer[0])*m);
	}
	delete[] ioBuffer;
	in.close();
	out.close();
}

int main()
{
	int dementions[2];
	copyToBin(dementions);
	printFromBin("sample.bin");
	int k; cin >> k;
	int* kRow = getMatrixRow(k, dementions[0], dementions[1]);
	podshet(kRow,dementions[1]);
	insertRowBin(kRow, k-1);
	printFromBin("UpBin.bin");
	system("pause.exe");
	delete[] kRow;
	return 0;
}