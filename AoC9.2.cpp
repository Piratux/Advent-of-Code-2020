#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int preamble = 25;

int get_answer()
{
	ifstream fin("input.txt");

	vector<long long> numbers;
	
	long long num;
	for(int i = 0; i < preamble; i++)
	{
		fin >> num;
		numbers.push_back(num);
	}
	
	int place_to_insert = 0;
	bool found_pair;
	while(fin >> num)
	{
		found_pair = false;
		for(int i = numbers.size()-preamble; i < numbers.size()-1; i++)
		{
			for(int j = i+1; j < numbers.size(); j++)
			{
				if(numbers[i] + numbers[j] == num)
				{
					found_pair = true;
					break;
				}
			}
			if(found_pair == true)
			{
				break;
			}
		}
		if(found_pair == false)
		{
			break;
		}
		numbers.push_back(num);
	}
	
	bool found_set;
	long long sum, min_num = 0x7fffffffffffffff, max_num = 0;
	for(int i = 0; i < numbers.size(); i++)
	{
		found_set = false;
		sum = numbers[i];
		for(int j = i+1; j < numbers.size(); j++)
		{
			sum += numbers[j];
			if(sum == num)
			{
				for(int k = i; k <= j; k++)
				{
					if(numbers[k] < min_num)
						min_num = numbers[k];
					if(numbers[k] > max_num)
						max_num = numbers[k];
				}
				found_set = true;
				break;
			}
			if(sum > num)
			{
				break;
			}
		}
		if(found_set)
		{
			break;
		}
	}
	fin.close();
	return min_num + max_num;
}

int main()
{
	cout << get_answer() << '\n';
}

