#include <stdio.h>
#include <iostream>
#include <math.h>
#include <conio.h>

#define AMOUNT 10

using namespace std;

void sort(int* s_arr, int first, int last)
{
	int i = first, j = last, x = s_arr[(first + last) / 2];

	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;

		if(i <= j) 
		{
			if (i < j) swap(s_arr[i], s_arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		sort(s_arr, i, last);
	if (first < j)
		sort(s_arr, first,j);
}

int main()
{
	int arr[AMOUNT] = {1,6,3,2,6,5,9,0,1,2};
	sort(arr, 0, AMOUNT-1);
	for( int i=0; i < AMOUNT; i++ )
	{
		cout << arr[i] << " ";
	}
	getch();
}