#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

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
	
	vector<int> iterated(instructions.size());
	int accumulate = 0;
	int curr = 0;
	while(iterated[curr]++ == 0)
	{
		if(instructions[curr].first == 'a')
		{
			accumulate += instructions[curr].second;
		}
		if(instructions[curr].first == 'j')
		{
			curr += instructions[curr].second;
			continue;
		}
		curr++;
	}
	return accumulate;
}

int main()
{
	cout << get_answer() << '\n';
}

