#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string replaceAll(string input, string old_val, string new_val)
{
	string output;
	int pos = 0;
	int match_pos = 0;
	while ((match_pos = input.find(old_val, pos)) != string::npos)
	{
		output += input.substr(pos, match_pos - pos);
		output += new_val;
		pos = match_pos + old_val.size();
	}
	output += input.substr(pos, string::npos);
	return output;
}
int main()
{
	string str;
	ifstream input("in.txt");
	ofstream output("out.txt");
	if (!input.is_open() || !output.is_open()) {
		cout << "файл не открыт";
		return 0;
	}
	while (getline(input, str))
	{
		str = replaceAll(str, "NO", "NOб");
		str = replaceAll(str, "YES", "NO");
		str = replaceAll(str, "NOб", "YES");
		output << str << endl;
	}
	cout << "Выполнено";
	return 0;
}