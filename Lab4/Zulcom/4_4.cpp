#include <fstream>
#include <iostream>
using namespace std;

int findFirstPositivePos(int* row, int m){
	for(int i = 0; i < m; i++)
		if(row[i] > 0) return i;
	return -1;
}
void printFromBin(int* dementions,char* name){
	ifstream in(name, ios::binary);
	if(!in.is_open()) cout << "sample.bin cant open for read.";
	in.read(reinterpret_cast<char*>(&dementions[0]), sizeof(dementions[0]));
	in.read(reinterpret_cast<char*>(&dementions[1]), sizeof(dementions[1]));
	cout << dementions[0] << " " << dementions[1] << endl;
	int* ioBuffer = new int[dementions[1]];
	for(int i = 0; i < dementions[0]; i++){
		in.read(reinterpret_cast<char*>(ioBuffer), sizeof(ioBuffer[0]) * dementions[1]);
		for(int j = 0; j < dementions[1]; j++)
			cout << ioBuffer[j] << " ";
		cout << endl;
	}
	delete[] ioBuffer;
	in.close();
}
int* getMatrixRow(int k, int n, int m){
	ifstream binIn("sample.bin", ios::binary);
	if(!binIn.is_open()) cout << "sample.bin cant open for read";
	binIn.seekg(sizeof(int) * 2, ios::beg);
	int* row = new int[m];
	binIn.seekg(sizeof(int) * (2 + (k - 1) * m), ios::beg);
	binIn.read(reinterpret_cast<char*>(row), sizeof(row[0]) * m);
	binIn.close();
	return row;
}
int main(){
	int dementions[2];
	dementions[0] = 0;dementions[1] = 0;
	printFromBin(dementions, "sample.bin");
	int k;
	cin >> k;
	int* kRow = getMatrixRow(k, dementions[0], dementions[1]);
	int* kplusplusRow = getMatrixRow(k + 1, dementions[0], dementions[1]);
	int kPos = findFirstPositivePos(kRow, dementions[1]);
	int kPlusPlusPos = findFirstPositivePos(kplusplusRow, dementions[1]);
	if(-1 == kPos || -1 == kPlusPlusPos){
		cout << "Cant swap.";
		return 0;
	}
	int temp = kRow[kPos];
	kRow[kPos] = kplusplusRow[kPlusPlusPos];
	kplusplusRow[kPlusPlusPos] = temp;
	ofstream binOut("sample1.bin", ios::binary);
	if(!binOut.is_open()) cout << "sample.bin cant open for write";
	binOut.write((char*) &dementions[0], sizeof dementions[0]);
	binOut.write((char*) &dementions[1], sizeof dementions[1]);
	for(int i = 0; i <dementions[1]; i++){
		if(i + 1 == k){
			binOut.write((char*) kRow, sizeof kRow[0] * dementions[1]);
			binOut.write((char*) kplusplusRow, sizeof kplusplusRow[0] * dementions[1]);
			i++;
		}
		else{
			int * thisRow = getMatrixRow(i + 1, dementions[0], dementions[1]);
			binOut.write((char*) thisRow, sizeof(thisRow[0])*dementions[0]);
		}
	}
	binOut.close();
	printFromBin(dementions, "sample1.bin");
	system("pause.exe");
	delete[] kRow;
	delete[] kplusplusRow;
	return 0;
}