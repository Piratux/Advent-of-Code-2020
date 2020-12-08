#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

long long traverse_bags(unordered_map<string, pair<vector<int>, vector<string>>> &bags, string &check_bag)
{
	if(bags[check_bag].second.size() == 0)
		return 0;
	
	long long total = 0;
	for(int i = 0; i < bags[check_bag].second.size(); i++)
	{
		total += bags[check_bag].first[i] * traverse_bags(bags, bags[check_bag].second[i]) + bags[check_bag].first[i];
	}
	return total;
}

long long get_answer()
{
	ifstream fin("input.txt");
	
	unordered_map<string, pair<vector<int>, vector<string>>> bags;
	
	string str, bag_parent, bag_child;
	while(!fin.eof())
	{
		bag_parent.clear();
		fin >> bag_parent;
		fin >> str;
		bag_parent += str;
		while(fin >> str)
		{
			if(str.back() == '.')
				break;
			else if(str.length() == 1)
			{
				bags[bag_parent].first.push_back(stoi(str));
				bag_child.clear();
				fin >> bag_child;
				fin >> str;
				bag_child += str;
				bags[bag_parent].second.push_back(bag_child);
			}
		}
	}
	fin.close();
	
	string searching_for = "shinygold";
	
	return traverse_bags(bags, searching_for);
}

int main()
{
	cout << get_answer() << '\n';
}

