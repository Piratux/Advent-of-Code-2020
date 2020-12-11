#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

int count_neighbours(vector<string> &seats, int i, int j, int rows, int columns)
{
	int neighbours = 0;
	char check_right = 1, check_left = 1, check_top = 1, check_bottom = 1;
	if(j+1 == columns)
	{
		check_right--;
	}
	if(j == 0)
	{
		check_left--;
	}
	if(i == 0)
	{
		check_top--;
	}
	if(i+1 == rows)
	{
		check_bottom--;
	}
	if(check_right)
	{
		// RIGHT
		if(seats[i][j+1] == '#')
		{
			neighbours++;
		}
		// TOP RIGHT
		if(check_top)
		{
			if(seats[i-1][j+1] == '#')
			{
				neighbours++;
			}
		}
		// BOTTOM RIGHT
		if(check_bottom)
		{
			if(seats[i+1][j+1] == '#')
			{
				neighbours++;
			}
		}
	}
	if(check_left)
	{
		// LEFT
		if(seats[i][j-1] == '#')
		{
			neighbours++;
		}
		// TOP LEFT
		if(check_top)
		{
			if(seats[i-1][j-1] == '#')
			{
				neighbours++;
			}
		}
		// TOP LEFT
		if(check_bottom)
		{
			if(seats[i+1][j-1] == '#')
			{
				neighbours++;
			}
		}
	}
	// TOP
	if(check_top)
	{
		if(seats[i-1][j] == '#')
		{
			neighbours++;
		}
	}
	// BOTTOM
	if(check_bottom)
	{
		if(seats[i+1][j] == '#')
		{
			neighbours++;
		}
	}
	return neighbours;
}

int get_answer()
{
	ifstream fin("input.txt");

	vector<string> seats[2];
	string str;
	while(getline(fin, str))
	{
		seats[0].push_back(str);
		seats[1].push_back(str);
	}
	fin.close();
	int rows = seats[0].size();
	int columns = seats[0][0].length();
	int previous = -1, now = 1;
	char idx[2] = {0};
	while(previous != now)
	{
		idx[0] = idx[1];
		idx[1] = 1 - idx[0];
		previous = now;
		now = 0;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				if(seats[idx[0]][i][j] == '.')
				{
					continue;
				}
				
				int neighbours = count_neighbours(seats[idx[0]], i, j, rows, columns);
				
				if(neighbours == 0)
				{
					seats[idx[1]][i][j] = '#';
				}
				else if(neighbours >= 4)
				{
					seats[idx[1]][i][j] = 'L';
				}
				else
				{
					seats[idx[1]][i][j] = seats[idx[0]][i][j];
				}
				if(seats[idx[1]][i][j] == '#')
				{
					now++;
				}
			}
		}
	}
	return now;
}
int main()
{
	cout << get_answer() << '\n';
}

