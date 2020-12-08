#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int get_answer()
{
	ifstream fin("input.txt");
	
	int row, column, ID, maxID = 0, binary;
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
		if(ID > maxID)
			maxID = ID;
	}
	return maxID;
}

int main()
{
	cout << get_answer() << '\n';
}

