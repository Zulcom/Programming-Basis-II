#include <iostream> 
#include <string> 
#include <clocale>

using namespace std;

class Money
{
private:
	long rub, kop;
public:
	Money(long Rub, long Kop)// инициализирующий конструктор
	{
		if (Rub < 0 || Kop < 0)
		{
			rub = 0, kop = 0, cerr << "Значения рублей и копеек не должно быть отрицательным!" << endl;
		}
		else
		if (Kop <100)
			rub = Rub, kop = Kop;
		else
		if (Kop>100)
			rub = Rub + (Kop / 100), kop = Kop % 100;
	}
	 
	Money(){} // конструктор по умолчанию
	void PrintEn() { cout << "\n" << rub << " рублей " << kop << " копеек" << endl; }

	long GetRub() { return rub; }
	long GetKop() { return kop; }
	
	void SetRub(long _rub) { if (_rub >0) rub = _rub; else if(_rub< 0) rub=0, cerr << "Значение рубля не может быть отрицательным!" << endl; }
	void SetKop(long _kop) { if (_kop > 0) kop = _kop; else if(_kop <0) kop=0, cerr<< "Значение копеек не может быть отрицательны!" << endl; }
	
    //Разница в копейках между 1 и 2 объектом 
	long Kopeck(Money t)
	{
		return (t.GetRub() - rub) *100 + (t.GetKop()-kop);
	}
};


class Goods : public Money
{
private:
	string name, code;
public:
	Goods(string Name, string Code, long Rub, long Kop) :Money(Rub, Kop) // инициализирующий конструктор
	{
		name = Name;
		code = Code;
	}
	
	Goods(){} // конструктор по умолчанию
	void PrintEn_Goods()
	{
		cout << "\n" << name << ' ' << code;
		PrintEn();
	}

	string GetName() { return name; }
	string GetCode() { return code; }

	void SetName(string _name) { name = _name; }
	void SetCode(string _code) { code = _code; }


	//какое занятие из двух начнется раньше 
	Goods & Cheaper(Goods g) 
	{
		if (Kopeck(g) >= 0) return g; else
			return *this;
	}
};

int main()
{
	// Создаем, инициализируем первый объект 
	setlocale(LC_ALL, "rus");
	long rub, kop;
	string name, code;  cout << "\n Введите\n Рубли= ";
	cin >> rub;
	cout << " Копейки = ";
	cin >> kop;
	cout << " Наименование товара = ";
	cin >> name;
	cout << " Код товара = ";
	cin >> code;
	Goods g1(name, code, rub, kop);// используется инициализирующий конструктор
	cout << "\nGoods 1 ";
	g1.PrintEn_Goods();
	// Создаем, инициализируем второй объект 
	Goods g2("Хлеб", "458575", 50, 50); // используется инициализирующий конструктор
	cout << "\nGoods 2 ";
	g2.PrintEn_Goods();
	// Создаем, инициализируем третий объект 
	Goods g3; // используется конструктор по умолчанию 
	g3.SetRub(400);
	g3.SetKop(43);
	g3.SetName("Сыр Брынза");
	g3.SetCode("856924");
	cout << "\nGoods 3 ";
	g3.PrintEn_Goods();// Определяем, какое занятие начнется раньше 
	//Goods g4=g1.Cheaper(g2);
	//g4 = g4.Cheaper(g3);
	//cout << "\n Товар с самой низкой стоимостью:\n";
	//g4.PrintEn_Goods();
	system("pause");
	return 0;
}

