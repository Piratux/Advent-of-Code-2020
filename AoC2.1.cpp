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
		fin.ignore(1);
		getline(fin, pass);
		int found = 0;
		for(int i = 0; i < pass.size(); i++)
		{
			if(pass[i] == letter)
				found++;
		}
		if(found >= min && found <= max)
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
