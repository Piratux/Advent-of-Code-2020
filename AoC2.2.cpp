#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int get_answer()
{
	ifstream fin("input.txt");
	
	int min, max, good = 0;
	char letter;
	string pass;
	
	while(!fin.eof())
	{
		fin >> min;
		fin.ignore(1);
		fin >> max;
		fin.ignore(1);
		fin >> letter;
		fin.ignore(2);
		getline(fin, pass);
		if(pass[min-1] == letter xor pass[max-1] == letter)
		{
			good++;
		}
	}
	fin.close();
	return good;
}

int main()
{
	cout << get_answer() << '\n';
}
