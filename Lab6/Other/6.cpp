#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include<clocale>
struct node
{
    int info;//информационное поле
    struct node *link;//поле для связи с дургими узлами

}*top;
 
 
 
 
 
void add(int num) {//функция добавления структуры в конец списка
   
    node* k = new node;//выделение памяти
    k->info = num;
    k->link = NULL;//пустой стек
	node *f=top;//
    if(!f) { //если список пуст
        top = k;//тогда новая запись стаёт головой списка
        
    } else { 
        node* last = f;
        while(last->link) last=last->link;// идем в цикле от начала до последней записи в списке
        last->link = k;//и вставляем новую запись в конец списка
    }
}

 
 
 
 
 
void  display()//функция вывода на экран
{
    node *r=top;
    if(r==NULL)
    {
    return;
    }
    while(r!=NULL)//цикл, пока не дойдем до конца списка
    {
    printf("%d ",r->info);//выводим текущую запись на экран
    r=r->link;//берем следующий узел списка
    }
    printf("\n");
}
 
 int proizv()
 {
	 int proiz=1;
	 bool b=false;
	 node *r=top;//р равен 1 элементу списка
	 if(r==NULL)
     {
		return 0;
     }
     while(r!=NULL)
     {
		 if(r->info!=0)
		 {
			 proiz*=r->info;
			 b=true;
		 }
      r=r->link;
     }
	 if(b==false)
		 return 0;
	 else
		 return proiz;
 }
int main()
{setlocale(LC_ALL, "rus");
     top=NULL;
	 int num;
	 int kol;
	 printf("Введите количество элементов списка: ");
	 scanf("%i",&kol);
	 for(int i=0;i<kol;i++)
	 {
		 printf("Введите элемент списка: "); 
		 scanf("%d",&num);
		 add(num);//заносим число в список
	 }
	 printf("Вывод списка: ");
	 display();
	 int proiz=proizv();
	 printf("Произведение ненулевых элементов: %i",proiz);
     add(proiz);//добавляем произведение в конец списка
	 printf("\nВывод списка: ");
	 display();
     getch(); 
}