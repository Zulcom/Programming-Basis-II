#include <iostream>
#include <list>
using namespace std;

int main() {
	setlocale(LC_ALL,"Russian");
	setlocale(LC_ALL,"rus");
	list<int> a, b;
	list<int>::iterator iterA, iterB;
	int t, temp;
	puts("������� ���������� ���������");
	cin>>t;
	a.resize(t);
	b.resize(t);
	puts("������� ��������");
	for(iterA = a.begin(), iterB = b.begin(); iterA != a.end(); iterA++, iterB++){
		cin>>*iterA;
		if(iterB == b.begin()){
			*iterB = *iterA;
		}else{
			iterA--;
			*iterB += *iterA;
			iterA++;
			*iterB += *iterA;
		}
	}
	iterA = a.begin();
	iterA++;
	iterA++;..
	iterB = b.begin();
	iterB++;
	iterB++;
	a.erase(iterA);
	b.erase(iterB);
	puts("������ A");
	for(iterA = a.begin(); iterA != a.end(); iterA++){
		cout<<*iterA<<' ';
	}
	cout<<'\n';
	puts("������ B");
	for(iterB = b.begin(); iterB != b.end();  iterB++){
		cout<<*iterB<<' ';
	}
	
	system("pause");
	return 0;
}