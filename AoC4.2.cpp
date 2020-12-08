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
string get_str_value(string &str, int found)
{
	string temp_string = "";
	for(int j = found + 4; str[j] != ' ' && str[j] != '\n' && j < str.length(); j++)
	{
		temp_string += str[j];
	}
	return temp_string;
}
int yr(string &str, int found, int from, int to)
{
	string temp_string = get_str_value(str, found);
	int year = stoi(temp_string);
	if(year >= from && year <= to)
	{
		return 1;
	}
	return 0;
}
int hgt(string &str, int found)
{
	string temp_string = get_str_value(str, found);
	string height_type = temp_string.substr(temp_string.length()-2, 2);
	if(height_type == "cm")
	{
		int height = stoi(temp_string.substr(0, temp_string.length()-2));
		if(height >= 150 && height <= 193)
		{
			return 1;
		}
	}
	if(height_type == "in")
	{
		int height = stoi(temp_string.substr(0, temp_string.length()-2));
		if(height >= 59 && height <= 76)
		{
			return 1;
		}
	}
	return 0;
}
int hcl(string &str, int found)
{
	string temp_string = get_str_value(str, found);
	if(temp_string[0] == '#' && temp_string.length() == 7)
	{
		for(int i = 1; i <= 6; i++)
		{
			if(!((temp_string[i] >= 48 && temp_string[i] <= 57) || (temp_string[i] >= 97 && temp_string[i] <= 102)))
				return 0;
		}
		return 1;
	}
	return 0;
}
int ecl(string &str, int found)
{
	string temp_string = get_str_value(str, found);
	vector<string> colours = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
	for(int i = 0; i < 7; i++)
	{
		if(colours[i] == temp_string)
			return 1;
	}
	return 0;
}
int pid(string &str, int found)
{
	string temp_string = get_str_value(str, found);
	if(temp_string.length() == 9)
	{
		for(int i = 0; i < 9; i++)
		{
			if(!(temp_string[i] >= 48 && temp_string[i] <= 57))
				return 0;
		}
		return 1;
	}
	return 0;
}
int get_answer()
{
	ifstream fin("input.txt");
	
	vector<string> fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
	
	int field_found[7] = {0};
	string str;
	
	bool valid = true;
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
			size_t found = str.find(fields[i]);
			if(found != string::npos)
			{
				switch(i)
				{
				case 0:
					field_found[i] = yr(str, found, 1920, 2002);
					break;
				case 1:
					field_found[i] = yr(str, found, 2010, 2020);
					break;
				case 2:
					field_found[i] = yr(str, found, 2020, 2030);
					break;
				case 3:
					field_found[i] = hgt(str, found);
					break;
				case 4:
					field_found[i] = hcl(str, found);
					break;
				case 5:
					field_found[i] = ecl(str, found);
					break;
				case 6:
					field_found[i] = pid(str, found);
					break;
				}
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
