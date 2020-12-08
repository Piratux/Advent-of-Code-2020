#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int get_answer()
{
	vector<int> nums;
	ifstream fin("input.txt");
	
	int num = 0;
	while(fin >> num)
	{
		nums.push_back(num);
	}
	for(int i = 0; i < nums.size()-2; i++)
	{
		for(int j = i+1; j < nums.size()-1; j++)
		{
			for(int k = j+1; k < nums.size(); k++)
			{
				if(nums[i] + nums[j] + nums[k] == 2020)
				{
					fin.close();
					return nums[i] * nums[j] * nums[k];
				}
			}
		}
	}
}

int main()
{
	cout << get_answer() << '\n';
}
