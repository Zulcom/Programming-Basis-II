#include <iostream> 
using namespace std;
void summaBolshe0(int * BBEDENIY,int PA3MEP)
{
	int sum = 0; 
	for(int i = 0; i < PA3MEP; i++) 
	{
		if(BBEDENIY[i] > 0) sum += BBEDENIY[i]; 
	}
	cout << "����� ������������� ���������: " << sum <<endl;
}
void max(int * BBEDENIY, int PA3MEP)
{
	int max = BBEDENIY[0]; 
	for(int i = 0; i < PA3MEP; i++) 
	{
		if(BBEDENIY[i] > max) max = BBEDENIY[i]; 
	}
	cout << "������������ �������: " << max <<endl;
}

void chaweBcero(int * BBEDENIY, int PA3MEP)
{
	for (int i = 0; i< PA3MEP; i++) 
	BBEDENIY[BBEDENIY[i]%PA3MEP] += PA3MEP;
    int max = BBEDENIY[0], result = 0;
    for (int i = 1; i < PA3MEP; i++)
    {
        if (BBEDENIY[i] > max)
        {
            max = BBEDENIY[i];
            result = i;
        }
    }
       for (int i = 0; i< PA3MEP; i++)
          BBEDENIY[i] = BBEDENIY[i]%PA3MEP; 
          cout << "����� ���������������� �������: " <<result <<endl;
             for (int i = 0; i< PA3MEP; i++) cout << BBEDENIY[i];
             cout <<endl;

}
void(*yka3ateli_na_func[3]) (int*,int) = {summaBolshe0, max, chaweBcero};
int main(){ 
	setlocale(LC_ALL, "Russian"); 
	int HOMEP_PUHKTA, PA3MEP; 
	cout << "������� ������ �������: "; cin >> PA3MEP; 
		int *  BBEDENIY = new int[PA3MEP]; 
		for(int i = 0; i < PA3MEP; i++) 
		{
			cout << endl << "mas[" << (i+1) << "]: "; 
			cin >> BBEDENIY[i];
		}
	cout 
		<< "1 - ����� ������������� ��������� " << endl
		<< "2 - �������� ������������� ��������" << endl
		<< "3 - �������� ��������,������� ���� ����� ����������� � ���� �������" << endl
		<< "4 - �����" <<endl;
	while(true) 
	{
		while(true) 
		{ 
			cout << "������� ����� ������ ����: ";
			cin >> HOMEP_PUHKTA;
			if(HOMEP_PUHKTA >= 1 && HOMEP_PUHKTA <= 4) break; 
			cout << "������ � ������ ������" <<endl;
		}
		if(HOMEP_PUHKTA == 4){
		delete[] BBEDENIY;
		exit(0);	
		}
		(*yka3ateli_na_func[HOMEP_PUHKTA - 1])(BBEDENIY,PA3MEP); 
		 
	}
	return 0; 
}
