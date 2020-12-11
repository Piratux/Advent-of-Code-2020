#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <string.h>

using namespace std;

int count_neighbours(vector<string> &seats, int i, int j, int rows, int columns)
{
	int neighbours = 0;
	
	int check_right = columns - 1 - j;
	int check_left = j;
	int check_bottom = rows - 1 - i;
	int check_top = i;
	
	int temp_check[2] = {0};
	while(temp_check[0]++ < check_right)
	{
		// RIGHT
		if(seats[i][j + temp_check[0]] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i][j + temp_check[0]] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 4);
	while(temp_check[0]++ < check_right && temp_check[1]++ < check_top)
	{
		// TOP RIGHT
		if(seats[i-temp_check[1]][j+temp_check[0]] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i-temp_check[1]][j+temp_check[0]] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 8);
	while(temp_check[0]++ < check_right && temp_check[1]++ < check_bottom)
	{
		// BOTTOM RIGHT
		if(seats[i+temp_check[1]][j+temp_check[0]] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i+temp_check[1]][j+temp_check[0]] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 4);
	while(temp_check[0]++ < check_left)
	{
		// LEFT
		if(seats[i][j - temp_check[0]] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i][j - temp_check[0]] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 8);
	while(temp_check[0]++ < check_left && temp_check[1]++ < check_top)
	{
		// TOP LEFT
		if(seats[i-temp_check[1]][j-temp_check[0]] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i-temp_check[1]][j-temp_check[0]] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 8);
	while(temp_check[0]++ < check_left && temp_check[1]++ < check_bottom)
	{
		// BOTTOM LEFT
		if(seats[i+temp_check[1]][j-temp_check[0]] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i+temp_check[1]][j-temp_check[0]] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 4);
	while(temp_check[0]++ < check_top)
	{
		// TOP
		if(seats[i - temp_check[0]][j] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i - temp_check[0]][j] == 'L')
		{
			break;
		}
	}
	memset(temp_check, 0, 4);
	while(temp_check[0]++ < check_bottom)
	{
		// BOTTOM
		if(seats[i + temp_check[0]][j] == '#')
		{
			neighbours++;
			break;
		}
		else if(seats[i + temp_check[0]][j] == 'L')
		{
			break;
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
				else if(neighbours >= 5)
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

