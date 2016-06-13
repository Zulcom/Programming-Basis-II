int main()
{

int n;
int *a;
int k=0;

cout<<"Vediterazmernostmassiva n = ";
cin>> n;

cout<<"Veditemassiv. Razmernost = "<< n <<"\n";
a = newint [n];
for (inti = 0; i< n; i++)
{
	cout<<"a["<< i+1 <<"] = ";
	cin>> a[i];
	cout<<"\n";
}

for (inti = 0; i< n; i++)
{
	if (a[i]<0) 
		{
			k++;
		}
}

if (k==0) cout<<"Otricatelnihelementov net!\n";	
	elsecout<<"Kolotricatelnihelementov = "<< k <<"\n";


return 0;
}

