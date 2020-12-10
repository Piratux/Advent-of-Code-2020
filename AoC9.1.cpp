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
		for(int i = 0; i < preamble-1; i++)
		{
			for(int j = i+1; j < preamble; j++)
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
			return num;
		}
		numbers[place_to_insert++ % preamble] = num;
	}
}

int main()
{
	cout << get_answer() << '\n';
}

