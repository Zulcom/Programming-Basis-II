#include <windows.h>
#include <fstream> 
#include<clocale>
#include<iostream>
using namespace std;
struct student
{
       char surname[20];
       int year;
       int kurs;
       char VK[11];
};

int main()
{
setlocale(LC_ALL, "rus");
int n1=0;
FILE *f1,*f2;
student *A;
char fname[20];
char *str = new char [1024];
int n=0;
ifstream file("1.txt");
while (!file.eof())
    {
        file.getline(str, 1024, '\n');
        n++;
    }
file.close();
f1=fopen("1.txt","r");
A=new student[n];
for(int i=0;i<n;i++)
{
   fscanf(f1,"%s",&A[i].surname);
   fscanf(f1,"%d",&A[i].year);
   fscanf(f1,"%d",&A[i].kurs);
   fscanf(f1,"%s",&A[i].VK);
}
fclose(f1);
cout<<"Введите название файла: "<<endl;
cin>>fname;
f2=fopen(fname,"wb");
for(int i=0;i<n;i++)
{
	if(A[i].kurs==1)
	{
          fwrite(&A[i],sizeof(student),1,f2); 
          n1++;                              
    }
}
fclose(f2);
cout<<"1 файл:"<<endl;
cout<<"Фамилия        Возраст        Курс       Кафедра"<<endl;
for(int i=0;i<n;i++)
{
    cout.setf(ios::left);
	cout.width(15);
	cout<<A[i].surname;
	cout.width(15);
	cout<<A[i].year;
	cout.width(15);
	cout<<A[i].kurs;
	cout.width(15);
	cout<<A[i].VK<<endl;

}
f2=fopen(fname,"rb");
for(int i=0;i<n1;i++)
{
    fread(&A[i],sizeof(student),1,f2);         
}
fclose(f2);

cout<<"2 файл:"<<endl;
cout<<"Фамилия        Возраст        Курс        Кафедра"<<endl;;
for(int i=0;i<n1;i++)
{
	cout.setf(ios::left);
	cout.width(15);
	cout<<A[i].surname;
	cout.width(15);
	cout<<A[i].year;
	cout.width(15);
	cout<<A[i].kurs;
	cout.width(15);
	cout<<A[i].VK<<endl;

}
system("pause");
return 0;
}
