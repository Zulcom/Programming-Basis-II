#include <iostream> 
using namespace std;
void summaBolshe0(int * BBEDENIY,int PA3MEP)
{
	int sum = 0; 
	for(int i = 0; i < PA3MEP; i++) 
	{
		if(BBEDENIY[i] > 0) sum += BBEDENIY[i]; 
	}
	cout << "Сумма положительных элементов: " << sum <<endl;
}
void max(int * BBEDENIY, int PA3MEP)
{
	int max = BBEDENIY[0]; 
	for(int i = 0; i < PA3MEP; i++) 
	{
		if(BBEDENIY[i] > max) max = BBEDENIY[i]; 
	}
	cout << "Максимальный элемент: " << max <<endl;
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
          cout << "Самый частовстречаемый элемент: " <<result <<endl;
             for (int i = 0; i< PA3MEP; i++) cout << BBEDENIY[i];
             cout <<endl;

}
void(*yka3ateli_na_func[3]) (int*,int) = {summaBolshe0, max, chaweBcero};
int main(){ 
	setlocale(LC_ALL, "Russian"); 
	int HOMEP_PUHKTA, PA3MEP; 
	cout << "Введите размер массива: "; cin >> PA3MEP; 
		int *  BBEDENIY = new int[PA3MEP]; 
		for(int i = 0; i < PA3MEP; i++) 
		{
			cout << endl << "mas[" << (i+1) << "]: "; 
			cin >> BBEDENIY[i];
		}
	cout 
		<< "1 - Сумма положительных элементов " << endl
		<< "2 - Значение максимального элемента" << endl
		<< "3 - Значение элемента,который чаще всего встречается в этом массиве" << endl
		<< "4 - Выход" <<endl;
	while(true) 
	{
		while(true) 
		{ 
			cout << "Введите номер пункта меню: ";
			cin >> HOMEP_PUHKTA;
			if(HOMEP_PUHKTA >= 1 && HOMEP_PUHKTA <= 4) break; 
			cout << "Ошибка в номере пункта" <<endl;
		}
		if(HOMEP_PUHKTA == 4){
		delete[] BBEDENIY;
		exit(0);	
		}
		(*yka3ateli_na_func[HOMEP_PUHKTA - 1])(BBEDENIY,PA3MEP); 
		 
	}
	return 0; 
}
