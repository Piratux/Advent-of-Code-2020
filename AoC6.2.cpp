#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int count_equal_answers(string &answers, int groups)
{
	int total, occurence[26] = {0};
	for(int i = 0; i < answers.length(); i++)
	{
		occurence[answers[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++)
	{
		if(occurence[i] == groups)
			total++;
	}
	return total;
}

int get_answer()
{
	ifstream fin("input.txt");
	
	string str, answers = "";
	int total = 0, groups = 0;
	while(getline(fin, str))
	{
		if(str == "")
		{
			total += count_equal_answers(answers, groups);
			answers = "";
			groups = 0;
			continue;
		}
		groups++;
		answers += str;
	}
	total += count_equal_answers(answers, groups);
	return total;
}

int main()
{
	cout << get_answer() << '\n';
}

