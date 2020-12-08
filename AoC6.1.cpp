#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int count_different_answers(string &answers)
{
	int total, occurence[26] = {0};
	for(int i = 0; i < answers.length(); i++)
	{
		occurence[answers[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++)
	{
		if(occurence[i] > 0)
			total++;
	}
	return total;
}

int get_answer()
{
	ifstream fin("input.txt");
	
	string str, answers = "";
	int total = 0;
	while(getline(fin, str))
	{
		if(str == "")
		{
			total += count_different_answers(answers);
			answers = "";
			continue;
		}
		answers += str;
	}
	total += count_different_answers(answers);
	return total;
}

int main()
{
	cout << get_answer() << '\n';
}

