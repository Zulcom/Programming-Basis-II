#include <iostream>
#include <list>
using namespace std;

int main() {
	setlocale(LC_ALL,"Russian");
	setlocale(LC_ALL,"rus");
	list<int> a, b;
	list<int>::iterator iterA, iterB;
	int t, temp;
	puts("Введите количество элементов");
	cin>>t;
	a.resize(t);
	b.resize(t);
	puts("Введите элементы");
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
	puts("Массив A");
	for(iterA = a.begin(); iterA != a.end(); iterA++){
		cout<<*iterA<<' ';
	}
	cout<<'\n';
	puts("Массив B");
	for(iterB = b.begin(); iterB != b.end();  iterB++){
		cout<<*iterB<<' ';
	}
	
	system("pause");
	return 0;
}