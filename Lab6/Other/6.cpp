#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include<clocale>
struct node
{
    int info;//�������������� ����
    struct node *link;//���� ��� ����� � ������� ������

}*top;
 
 
 
 
 
void add(int num) {//������� ���������� ��������� � ����� ������
   
    node* k = new node;//��������� ������
    k->info = num;
    k->link = NULL;//������ ����
	node *f=top;//
    if(!f) { //���� ������ ����
        top = k;//����� ����� ������ ���� ������� ������
        
    } else { 
        node* last = f;
        while(last->link) last=last->link;// ���� � ����� �� ������ �� ��������� ������ � ������
        last->link = k;//� ��������� ����� ������ � ����� ������
    }
}

 
 
 
 
 
void  display()//������� ������ �� �����
{
    node *r=top;
    if(r==NULL)
    {
    return;
    }
    while(r!=NULL)//����, ���� �� ������ �� ����� ������
    {
    printf("%d ",r->info);//������� ������� ������ �� �����
    r=r->link;//����� ��������� ���� ������
    }
    printf("\n");
}
 
 int proizv()
 {
	 int proiz=1;
	 bool b=false;
	 node *r=top;//� ����� 1 �������� ������
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
	 printf("������� ���������� ��������� ������: ");
	 scanf("%i",&kol);
	 for(int i=0;i<kol;i++)
	 {
		 printf("������� ������� ������: "); 
		 scanf("%d",&num);
		 add(num);//������� ����� � ������
	 }
	 printf("����� ������: ");
	 display();
	 int proiz=proizv();
	 printf("������������ ��������� ���������: %i",proiz);
     add(proiz);//��������� ������������ � ����� ������
	 printf("\n����� ������: ");
	 display();
     getch(); 
}