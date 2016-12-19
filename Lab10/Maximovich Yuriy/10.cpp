#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <clocale>
using namespace std;
struct node
{
	int info;
	int c;
	node *llink, *rlink;
};
node *tree(node *p, int buf)
{
	if (p == NULL)
	{
		p = new node;
		p->info = buf;
		p->llink = NULL;
		p->rlink = NULL;
		p->c = 1;
	}
	else
		if (buf == p->info)
			p->c = p->c + 1;
		else
			if (buf < p->info)
				p->llink = tree(p->llink, buf);
			else
				p->rlink = tree(p->rlink, buf);
	return p;
}
void obhod(node *p)
{
	if (p != NULL)
	{
		cout << p->c << " " << p->info << endl;
		obhod(p->llink);
		obhod(p->rlink);
	}
}
int tree_sum_node_level(node *p, int n)
{
	if (p == NULL) return 0;
	if (n == 1) return p->info;
	return tree_sum_node_level(p->rlink, n - 1) + tree_sum_node_level(p->llink, n - 1);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	node *p;
	int buf, n, k;
	p = NULL;
	cout << "Введите количество цифр: ";
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cout << "Введите число: ";
		cin >> buf;
		p = tree(p, buf);
	}
	cout << endl << "Построенное дерево:" << endl;
	obhod(p);
	cout << "Введите уровень дерева: ";
	cin >> n;
	cout << tree_sum_node_level(p, n);
	_getch();
	return 0;
}
