#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int count_fields(int field_found[7])
{
	bool valid = true;
	for(int i = 0; i < 7; i++)
	{
		if(field_found[i] == 0)
		{
			valid = false;
		}
		field_found[i] = 0;
	}
	if(valid)
		return 1;
	return 0;
}
int get_answer()
{
	ifstream fin("input.txt");
	
	vector<string> fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
	
	int field_found[7] = {0};
	string str;
	
	int total_valid = 0;
	while(getline(fin, str))
	{
		if (str == "")
		{
			total_valid += count_fields(field_found);
			continue;
		}
		for(int i = 0; i < 7; i++)
		{
			if(str.find(fields[i]) != string::npos)
			{
				field_found[i] = 1;
			}
		}
	}
	total_valid += count_fields(field_found);
	fin.close();
	return total_valid;
}

int main()
{
	cout << get_answer();
}
