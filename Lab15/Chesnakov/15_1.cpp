#include<iostream>
#include<clocale>
using namespace std;
class Money
{
private:
unsigned int r, k;
public:
// ���������������������������
Money(unsigned int R, unsigned int K)
    {
        if(K < 100&&R>0&&K>0)
            r = R, k = K;
        else
            r = k = 0, cerr << "incorrect money format" << endl;
}
// ����������� �� ���������
Money(){}
void PrintEn()
    {
        cout << "\n" << r << "������" << k << "������"<<endl;
    }
unsigned int GetRub()  { return r; }
unsigned int GetKop()  { return k; }
void SetRub(unsigned int _r) { if(_r > 0) r =_r; else r = k = 0, cerr << "incorrect rubles" << endl; }
void SetKop (unsigned int _k) { if(_k < 100 && _k>0) k =_k; else k = r = 0, cerr << "incorrect kopeiki" << endl; }
//������� � �������� � �������� ��������
int Difference (Money m) { return (m.GetRub()- r)*100 + (m.GetKop() -k);}
};
int main()
{
  //�������, �������������� � ������� ������ ������
	setlocale(LC_ALL, "russian");
unsigned int r, k;
      cout << "\n Enter:\n r= ";
      cin >> r;
      cout << " k= ";
      cin >> k;
      Money m1 (r, k);// ������������ ���������������� �����������
      cout << "\nMoney 1 ";
      m1.PrintEn ();
//�������, �������������� � ������� ������ ������
      Money m2 (10, 15); // ������������ ���������������� �����������
      cout << "\nMoney 2 ";
      m2.PrintEn();
  //�������, �������������� � ������� ������ ������
      Money m3; // ������������ ����������� �� ���������
    m3.SetRub (14) ;
    m3.SetKop (15) ;
cout << "\nMoney 3";
      m3.PrintEn ();
  // ���������� ������� � �������� ����� ������ � ������ ��������
int kk = m1.Difference(m2);
      cout << "\n������� ����� 1 � 2 (���) = " << kk << endl;
	  system("pause");
}
