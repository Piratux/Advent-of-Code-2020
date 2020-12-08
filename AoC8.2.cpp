#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

int terminated(vector<pair<char, int>> &instructions)
{
	vector<int> iterated(instructions.size());
	int accumulate = 0, curr = 0;
	while(iterated[curr]++ == 0)
	{
		if(instructions[curr].first == 'a')
		{
			accumulate += instructions[curr].second;
		}
		if(instructions[curr].first == 'j')
		{
			curr += instructions[curr].second;
			if(curr == instructions.size())
			{
				return accumulate;
			}
			continue;
		}
		curr++;
		if(curr == instructions.size())
		{
			return accumulate;
		}
	}
	return 0;
}

int get_answer()
{
	ifstream fin("input.txt");

	vector<pair<char, int>> instructions;
	
	string str;
	int value;
	while(fin >> str >> value)
	{
		instructions.push_back({str[0], value});
	}
	
	int accumulate = 0;
	for(int i = 0; i < instructions.size(); i++)
	{
		if(instructions[i].first == 'j')
		{
			instructions[i].first = 'n';
			
			accumulate = terminated(instructions);
			if(accumulate != 0)
			{
				return accumulate;
			}
			
			instructions[i].first = 'j';
		}
		if(instructions[i].first == 'n')
		{
			instructions[i].first = 'j';
			
			accumulate = terminated(instructions);
			if(accumulate != 0)
			{
				return accumulate;
			}
			
			instructions[i].first = 'n';
		}
	}
	return 0;
}

int main()
{
	cout << get_answer() << '\n';
}

