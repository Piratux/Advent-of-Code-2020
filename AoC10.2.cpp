#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

long long calculate_possibilities(vector<int> nums, map<vector<int>, int> &exist)
{
	for(int i = 1; i < nums.size(); i++)
	{
		if(nums[i] - nums[i-1] > 3)
			return 0;
	}
	
	if(exist[nums]++ == 1)
		return 0;
		
	long long total = 1;
	for(int i = 1; i < nums.size()-1; i++)
	{
		int erased = nums[i];
		nums.erase(nums.begin() + i);
		total += calculate_possibilities(nums, exist);
		nums.insert(nums.begin() + i, erased);
	}
	return total;
}

long long get_answer()
{
	ifstream fin("input.txt");

	vector<int> numbers;
	int num;
	numbers.push_back(0);
	while(fin >> num)
	{
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	numbers.push_back(numbers.back()+3);
	
	vector<int> arr;
	map<int, int> possibilities;
	long long total = 1;
	for(int i = 1; i < numbers.size(); i++)
	{
		if(numbers[i] - numbers[i-1] == 3)
		{
			if(arr.size() == 0)
				continue;
			
			map<vector<int>, int> exist;
			arr.push_back(i);
			if(possibilities[arr.size()] == 0)
			{
				possibilities[arr.size()] = calculate_possibilities(arr, exist);
			}
			total *= possibilities[arr.size()];
			arr.clear();
			continue;
		}
		arr.push_back(i);
	}
	return total;
}
int main()
{
	cout << get_answer() << '\n';
}

