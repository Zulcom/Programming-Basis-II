#include <stdio.h>
#include <conio.h>

struct node
{
	char info;
	node *link;
};

void main ()
{
	node *top, *k;
	char w;
	top = NULL;
	puts("vvedite chislo");
	scanf("%c", &w);
	while (!feof(stdin))
	{
		k = new node;
		k->link = top;
		k->info = w;
		top = k;
		scanf("%c", &w);
	}
	k = top;
	while (k != NULL)
	{
		printf("%c", k->info);
		k = k->link;
	}
	char x;
	printf("\n");
	scanf("%c", &x);
	k = top;
	node *l = top;
	while (k !=NULL)
	{
		if (k->info == x)
		{
			if (k == top)
			{
				top = k->link;
				delete k;
				k = top;
			}
			else
			{
				l->link = k->link;
				delete k;
				k = l->link;
			}
		}
		else
		{
			l = k;
			k = l->link;
		}

	}
	puts("stek posle delete x");
	k = top;
	while (k !=NULL)
	{
		printf("%c", k->info);
		k = k->link;
	}
	getch();
}