#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int get_answer()
{
	ifstream fin("input.txt");
	
	int row, column, ID, maxID = 0, binary;
	vector<int> IDs;
	string str;
	while(getline(fin, str))
	{
		row = 0;
		column = 0;
		binary = 1;
		for(int i = 6; i >= 0; i--)
		{
			column += (str[i] == 'B') ? binary : 0;
			binary *= 2;
		}
		binary = 1;
		for(int i = 9; i >= 7; i--)
		{
			row += (str[i] == 'R') ? binary : 0;
			binary *= 2;
		}
		
		ID = column * 8 + row;
		
		IDs.push_back(ID);
	}
	sort(IDs.begin(), IDs.end());
	for(int i = 1; i < IDs.size(); i++)
	{
		if(IDs[i] != IDs[i-1]+1)
			return IDs[i]-1;
	}

	return 0;
}

int main()
{
	cout << get_answer() << '\n';
}

