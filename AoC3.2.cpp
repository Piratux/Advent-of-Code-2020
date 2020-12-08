#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

long long get_answer(int right, int down)
{
	ifstream fin("input.txt");
	
	vector<string> vec;
	string s;
	while(getline(fin, s))
	{
		vec.push_back(s);
	}
	
	long long total_trees = 0;
	for(int i = 1; i < floor(vec.size() / down); i++)
	{
		total_trees += (vec[i * down][right * i % s.length()] == '#');
	}
	fin.close();
	return total_trees;
}

int main()
{
	long long a[5];
	a[0] = get_answer(1, 1);
	a[1] = get_answer(3, 1);
	a[2] = get_answer(5, 1);
	a[3] = get_answer(7, 1);
	a[4] = get_answer(1, 2);
	cout << a[0] * a[1] * a[2] * a[3] * a[4] << '\n';
}
