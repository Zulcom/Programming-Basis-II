#include <iostream>
#include <fstream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    int k,n,m;
    int l=sizeof(int);
    FILE *output;
    output=fopen("2.txt", "rb+");
	fseek(output, l, SEEK_SET);
    fread(&n, l,1,output);
    fread(&m, l,1,output);
	cout<<"Введите k: ";
    cin>>k;
	k=k--;
	if(k>n)
	{
		cout<<"Превышено значение k"<<endl;
		system("pause");
	}
    int *a= new int [m];
    fseek(output, m*l*k, SEEK_SET);
    fread(a, l, m, output);
    for(int i=0; i<m; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
    for (int i = 0; i < m; ++i)
    {
        if(a[i]%7==0) 
			a[i]=a[i]*2;
	}
fclose(output);
output=fopen("2.txt","r+");
fseek (output,m*l*k,SEEK_SET);
fwrite(a,sizeof(int),m,output);
fclose(output);
output=fopen("2.txt","rb");
fseek (output,m*l*k,SEEK_SET);
cout<<"Файл после обновления:"<<endl;
for(int i=0;i<n;i++)
{
   fread(a,sizeof(int),m,output);
   for(int j=0;j<m;j++)
   {
           printf("%i ",a[j]);
   }
   printf("\n");
}
	system("pause");
	return 0;
}