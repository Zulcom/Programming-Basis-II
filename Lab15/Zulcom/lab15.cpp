#include <iostream>
#include <string>
using namespace std;

class Box
{
private:
	int visota;
	int shirina;
	int dlina;
public:
	Box(int visota, int shirina, int dlina) {
		this->visota = visota;
		this->shirina = shirina;
		this->dlina = dlina;
	}

	Box(): visota(0), shirina(0), dlina(0) {}

	float Volume() {
		return visota * shirina * dlina;
	}

	void show() {
		cout << visota <<":"<<	shirina<<":"<<dlina << endl;
	}
};

class Gift:public Box
{
private:
	string name;
	string type;
public:
	Gift(int visota, int shirina, int dlina, string name, string type): Box(visota, shirina, dlina) {

		this->name = name;
		this->type = type;
	}

	Gift(): Box(), name("Default name"), type(" Default type") {}

	void show() {
		cout << type <<" "	<<name<<" ";Box::show();
	}

	bool operator>(Gift& rhs) {
		return this->Volume() > rhs.Volume();
	}
};

int main() {
	setlocale(0, "Rus");
	Gift gifts[3] = {Gift(10, 20, 30, "Darya", "Book"),{200,300,790,"Katya","Car"},{140,30,30,"Vika","Guitar"}};
	Gift max = gifts[0];
	for (int i = 0; i < 3; i++)
	{
		gifts[i].show();
		if (gifts[i] > max) max = gifts[i];
	}
	cout
	<<
	"Самая большая коробка у подарка: ";
	max.show();
	return 0;
}

