#include <iostream>
#include<cstdlib>
using namespace std;
int n=8;
int fibonacci(int n){
    if(n<=0)  return 0;
    else if(1 == n || 2 == n) return 1;
    else
        return (fibonacci(n-1)+fibonacci(n-2));
}
int fib(int n){
    int f2=0,f1=1,num=0;
    int i;
    if (n==0 || n==1) return n;
    for(i=2;i<=n;i++){
        num=f1+f2;
        f2=f1;
        f1=num;
    }
    return num;
}

int main(){
	int n=2;
	cout << fibonacci(n) <<endl;
	cout << fib(::n);
	return 0;
}