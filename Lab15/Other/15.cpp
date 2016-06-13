#include <iostream> 
#include <string> 
#include <clocale>

using namespace std;

class Money
{
private:
	long rub, kop;
public:
	Money(long Rub, long Kop)// ���������������� �����������
	{
		if (Rub < 0 || Kop < 0)
		{
			rub = 0, kop = 0, cerr << "�������� ������ � ������ �� ������ ���� �������������!" << endl;
		}
		else
		if (Kop <100)
			rub = Rub, kop = Kop;
		else
		if (Kop>100)
			rub = Rub + (Kop / 100), kop = Kop % 100;
	}
	 
	Money(){} // ����������� �� ���������
	void PrintEn() { cout << "\n" << rub << " ������ " << kop << " ������" << endl; }

	long GetRub() { return rub; }
	long GetKop() { return kop; }
	
	void SetRub(long _rub) { if (_rub >0) rub = _rub; else if(_rub< 0) rub=0, cerr << "�������� ����� �� ����� ���� �������������!" << endl; }
	void SetKop(long _kop) { if (_kop > 0) kop = _kop; else if(_kop <0) kop=0, cerr<< "�������� ������ �� ����� ���� ������������!" << endl; }
	
    //������� � �������� ����� 1 � 2 �������� 
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
	Goods(string Name, string Code, long Rub, long Kop) :Money(Rub, Kop) // ���������������� �����������
	{
		name = Name;
		code = Code;
	}
	
	Goods(){} // ����������� �� ���������
	void PrintEn_Goods()
	{
		cout << "\n" << name << ' ' << code;
		PrintEn();
	}

	string GetName() { return name; }
	string GetCode() { return code; }

	void SetName(string _name) { name = _name; }
	void SetCode(string _code) { code = _code; }


	//����� ������� �� ���� �������� ������ 
	Goods & Cheaper(Goods g) 
	{
		if (Kopeck(g) >= 0) return g; else
			return *this;
	}
};

int main()
{
	// �������, �������������� ������ ������ 
	setlocale(LC_ALL, "rus");
	long rub, kop;
	string name, code;  cout << "\n �������\n �����= ";
	cin >> rub;
	cout << " ������� = ";
	cin >> kop;
	cout << " ������������ ������ = ";
	cin >> name;
	cout << " ��� ������ = ";
	cin >> code;
	Goods g1(name, code, rub, kop);// ������������ ���������������� �����������
	cout << "\nGoods 1 ";
	g1.PrintEn_Goods();
	// �������, �������������� ������ ������ 
	Goods g2("����", "458575", 50, 50); // ������������ ���������������� �����������
	cout << "\nGoods 2 ";
	g2.PrintEn_Goods();
	// �������, �������������� ������ ������ 
	Goods g3; // ������������ ����������� �� ��������� 
	g3.SetRub(400);
	g3.SetKop(43);
	g3.SetName("��� ������");
	g3.SetCode("856924");
	cout << "\nGoods 3 ";
	g3.PrintEn_Goods();// ����������, ����� ������� �������� ������ 
	//Goods g4=g1.Cheaper(g2);
	//g4 = g4.Cheaper(g3);
	//cout << "\n ����� � ����� ������ ����������:\n";
	//g4.PrintEn_Goods();
	system("pause");
	return 0;
}

