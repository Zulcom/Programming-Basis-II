#include <cmath>
#include <clocale>
#include <iostream>
#include <ctime>
using namespace std;
struct node { 
	int info; // info строка в структуре, хранит данные
	node *link; // ссылка на след.элемент
};
void print(node * l) {
	node * k = l;
	while (k != NULL) {
		cout << k->info << " ";
		k = k->link;
	}
	cout << endl;
}
int main() {
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int inputData, N; 
	node *thisNode, *left, *right;

	cout << "Введите количество элементов: ";
	cin >> N;
	cout << "Bведите число: ";
	cin >> inputData;
	// Первый элемент
	thisNode = new node;
	thisNode->link = NULL;
	thisNode->info = inputData;
	left = right = thisNode;
	// Заполнение остальных элементов 
	for (int i = 0; i < N - 1; ++i) {
		cout << "Bведите число: ";
		cin >> inputData;
		thisNode = new node;
		thisNode->link = NULL;
		thisNode->info = inputData;
		right->link = thisNode; // Добавление узла справа
		right = thisNode;
	}
	cout << "Cписок до преобразования: ";
	print(left);
	/*Добавление узлов */
	thisNode = left;
	while (thisNode->link != NULL) {
		if (thisNode->link->info <0) {
			for (int i = 0; i < 3; i++) {
				node * newnode = new node;
				newnode->link = thisNode->link;
				newnode->info = rand() % (thisNode->info) + 1;
				thisNode->link = newnode;
				thisNode = thisNode->link;
			}
		}
		thisNode = thisNode->link;
	}

	cout << "После добавления узлов: ";
	print(left);
	node *tmp;
	/*clear quenue */
	while (left->link != NULL)
	{
		tmp = left;
		left = left->link;
		delete[] tmp;
	}
	system("pause.exe");
	return 0;
}