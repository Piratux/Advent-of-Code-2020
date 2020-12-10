#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int get_answer()
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
	int diff_one = 0, diff_three = 0;
	for(int i = 1; i < numbers.size(); i++)
	{
		if(numbers[i] - numbers[i-1] == 1)
			diff_one++;
		else
			diff_three++;
	}
	
	return diff_one * diff_three;
}
int main()
{
	cout << get_answer() << '\n';
}

