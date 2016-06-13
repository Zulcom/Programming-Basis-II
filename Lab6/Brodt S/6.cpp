#include <stdio.h>
#include <conio.h>

struct node
{
	int g;
	node *rlink, *llink;
};
void llist(node *left)
{
	node *k = left;
	while (k != NULL)
	{
		printf("%d\n", k->g);
		k = k->rlink;
	}
}
void rlist (node *rigth)
{
	node *k = rigth;
	while (k != NULL)
	{
		printf("%d\n", k->g);
		k = k->llink;
	}
}
void main ()
{
	node *k,*q,*left,*rigth;
	int w;
	printf("vvedite chislo");
	scanf("%d",&w);
	k = new node;
	k->g = w;
	k->rlink = NULL;
	k->llink = NULL;
	rigth = k;
	q = k;
	printf("vvedite chisla");
	scanf("%d",&w);
	while (!feof(stdin))
	{
		k = new node;
		k->g = w;
		k->rlink = q;
		q->llink = k;
		q = k;
		printf("vvedite chislo");
		scanf("%d", &w);
	}
	q->llink = NULL;
	left = q;
	puts("sleva napravo");
	llist(left);
	puts("sprava nalevo");
	rlist(rigth);
	node *i;
	int x;
	printf("vvedite x\n");
	scanf("%d", &x);
	i = k = left;
	while (k!=NULL)
	{
		if(k->g == x)
		{
			if(k == left)
			{
				q = k;
				left = k->rlink;
				left->llink = NULL;
				i = k = left;
				delete q;
			}
			else if (k == rigth)
			{
				q = k;
				rigth = k->llink;
				rigth->rlink = NULL;
				k = NULL;
				delete q;
			}
			else
			{
				q = k;
				i->rlink = k->rlink;
				k->rlink->llink = i;
				delete q;
				k = i->rlink;
			}
		}
		else
		{
			i = k;
			k = k->rlink;
		}
	}
	puts("conclusion after removing x ");
	puts("sleva napravo");
	llist(left);
	puts("sprava nalevo");
	rlist(rigth);
	getch();
}
