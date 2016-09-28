#include <stdio.h>
#include <iostream>
#include <math.h>
#include <conio.h>

struct ved
{
	char FIO [20];
	int math , intfiz, intprog, intist, floatsrd;
};

int kol()
{
	if stream in("in.txt");
	int n=1;
	while(!feof(stdin))
	{
		if(in.get()=='\n')
			n++;
	}
	in.close();
	return n;
}

void convert( int n)
{
	FILE *bin;
	ved *sp = new ved[n];
	if stream f("in.txt");
	fopen_s(&bin,"inbin.dat","w+b");
	for (int i=0; i<n; i++)
	{

		f>>sp[i].FIO >>sp[i].fiz>>sp[i].ist>>sp[i].math>>sp[i].prog;
		sp[i].srd = (float(sp[i].fiz + sp[i].ist + sp[i].math +sp[i].prog))/4;
		fwrite(&sp[i],sizeof(sp[i]),1,bin);
	}
	f.close();
	fclose(bin);
	delete []sp;

}
void main()
{
	if stream in("in.txt");
	
	int n;

	n = kol();
	
	ved *sp = new ved[n];
	convert(n);
	
	FILE *fbin;
	
	if stream fin("in.txt");
	fopen_s(&fbin,"inbin.dat","r+b");
		for(int i = 0; i< n; i++)
		{
			fread(&sp[i], n*sizeof(sp[i]),1,fbin);
		}
			fclose(fbin);
		
	
	ved str;
	
	for(int i=n-1; i> 0; i--)
	for(int j=0; j <i ; j++)
	if(strcmp( sp[j].FIO, sp[j+1].FIO ) > 0)
		{ 
		str = sp[j];
		sp[j] = sp[j+1];
		sp[j+1] = str;
		}

	if stream fot("out.txt");

	fot<<"\n Ведомость\t\n"; 
	fot<<"________________________________________________________________________________ \n";
	fot<<" N |Фамилия|Физика|История|Математика|Программирование|Средняя оценка| \n"; 
	fot<<"--------------------------------------------------------------------------------\n";
			
		for (int i = 0; i< n; i++)
		{
			fot<< i+1 <<setw(10) <<sp[i].FIO <<setw(7) <<sp[i].fiz<<setw(8) <<sp[i].ist<<setw(11) <<sp[i].math <<setw(17) <<sp[i].prog<<setw(10) <<sp[i].srd<<'\n'; 
		} 
	fot<<"________________________________________________________________________________ \n";
	
	fot.close();

	delete []sp;
}
