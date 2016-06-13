#include <stdio.h>
#include <conio.h>
#include <cstring> 
using namespace std;

struct Report 
{
	char lastname[20]; 
	int mathematics, phisics, programming, history; 

	int avg()
	{ 
		return (mathematics + phisics + programming + history) / 4;
	}

}

void sort(Report *source, int N)
{ 
	Report temp;
	bool fl = false;
	do
	{
		fl = false;
		for( int i = 0; i < N - 1; i++ )
		{
			if( strcmp(source[i].lastname, source[i + 1].lastname) > 0 )
			{ 
				temp = source[i];
				source[i] = source[i + 1];
				source[i + 1] = temp;
				fl = true;
			}


		}
	}while( fl );
}

int main()
{
	int N; 
	Report *students; 
	scanf("%d", &N);
	students = new Report[N];
	for( int i = 0; i < N; i++ )
	{ 
		scanf("%s %d %d %d %d", &students[i].lastname, &students[i].mathematics, &students[i].phisics,&students[i].programming, &students[i].history);
	}
	int
		sort(students, N); 
	printf("%20s math phisics prog history average\n", ("Name")); 
	for( int i = 0; i < N; i++ )
	{ 
		printf("%20s %5d %5d %5d %5d %5d\n", students[i].lastname, students[i].mathematics, students[i].phisics, students[i].programming, students[i].history, students[i].avg());
	}
	getch();
	return 0;
}
