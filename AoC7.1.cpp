#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void traverse_bags(unordered_map<string, vector<string>> &bags, unordered_map<string, bool> &traversed_bags, string &check_bag)
{
	if(bags[check_bag].size() == 0)
		return;
	
	for(int i = 0; i < bags[check_bag].size(); i++)
	{
		traversed_bags[bags[check_bag][i]];
		traverse_bags(bags, traversed_bags, bags[check_bag][i]);
	}
	return;
}

int get_answer()
{
	ifstream fin("input.txt");
	
	unordered_map<string, vector<string>> bags;
	
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
				bag_child.clear();
				fin >> bag_child;
				fin >> str;
				bag_child += str;
				bags[bag_child].push_back(bag_parent);
			}
		}
	}
	fin.close();
	
	unordered_map<string, bool> traversed_bags;
	string searching_for = "shinygold";
	traverse_bags(bags, traversed_bags, searching_for);
	return traversed_bags.size();
}

int main()
{
	cout << get_answer() << '\n';
}

