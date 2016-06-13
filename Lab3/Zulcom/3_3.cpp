/*
Проверить, расположены ли элементы k-ой строки матрицы в порядке убывания. 
Если нет, определить, встречается ли значение  k в этой строке, используя алгоритм линейного поиска. Значение  k (k ? N) вводится с клавиатуры.
*/
#include <fstream>
#include <iostream>
using namespace std;

bool inDecreasingOrder(int* array, int size){
	for(int i = 0; i < size - 1; i++)
		if(array[i] < array[i + 1] || array[i] == array[i + 1]) return 0;
	return 1;
}
bool isInLine(int* array, int size, int k){
	for(int i = 0; i < size; i++)
		if(array[i] == k) return 1;
	return 0;
}
void printFromBin()
{
	ifstream in("sample.bin", ios::binary);
	if(!in.is_open()) cout << "sample.bin cant open for read.";
	int n, m;
	in.read(reinterpret_cast<char*>(&n), sizeof(n));
	in.read(reinterpret_cast<char*>(&m), sizeof(m));
	cout << n << " " << m <<endl;
	int* ioBuffer = new int[m];
	for(int i = 0; i < n; i++){
		in.read(reinterpret_cast<char*>(ioBuffer), sizeof (ioBuffer[0])*m);
		for(int j = 0; j < m; j++)
			cout << ioBuffer[j] << " ";
		cout << endl;
	}
	delete[] ioBuffer;
	in.close();
}
void copyToBin(int* dementions){
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
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			in >> ioBuffer[j];
		binOut.write(reinterpret_cast<char*>(ioBuffer), sizeof(ioBuffer[0])*M);
	}
	delete[] ioBuffer;
	in.close();
	binOut.close();
}
int* getMatrixRow(int k, int n, int m){
	ifstream binIn("sample.bin", ios::binary);
	if(!binIn.is_open()) cout << "sample.bin cant open for read";
	binIn.seekg(sizeof(int) * 2, ios::beg);
	int* row = new int[m];
	binIn.seekg(sizeof(int)*(2 + (k - 1) * m), ios::beg);
	binIn.read(reinterpret_cast<char*>(row), sizeof(row[0])*m);
	binIn.close();
	return row;
}
int main(){
	int dementions[2];
	copyToBin(dementions);
	printFromBin();
	int k; cin >> k;
	int* kRow = getMatrixRow(k, dementions[0], dementions[1]);
	if(inDecreasingOrder(kRow, dementions[1])) cout << "K-row in decreasing order";
	else if(isInLine(kRow, dementions[1], k)) cout << "K-row contains K";
	else cout << "K-row not contains K";
	cout << endl;
	system("pause.exe");
	delete[] kRow;
	return 0;
}