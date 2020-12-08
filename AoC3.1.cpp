#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int get_answer()
{
	ifstream fin("input.txt");
	
	vector<string> vec;
	string s;
	while(getline(fin, s))
	{
		vec.push_back(s);
	}
	
	int total_trees = 0;
	for(int i = 1; i < vec.size(); i++)
	{
		total_trees += (vec[i][3 * i % s.length()] == '#');
	}
	fin.close();
	return total_trees;
}

int main()
{
	cout << get_answer();
}
