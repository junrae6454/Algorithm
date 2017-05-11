#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
#include <array>
#include <map>
using namespace std;

int main()
{
	map<string, int> check;
	string maps;
	maps.assign(10, ' ');
	string goal = " 123456780";
	int blank = 0;
	for (int i = 1; i <= 9; i++)
	{
		cin >> maps[i];
		if (maps[i] == '0')
			blank = i;
	}
	deque<string> puzzle;
	puzzle.push_back(maps);
	check[maps] = 1;
	int count = 1;
	int result = 0;
	deque<string> npuzzle;
	while (!puzzle.empty())
	{
		string temp = puzzle.front();
		puzzle.pop_front();
		if (temp == goal)
		{
			result = count-1;
			count = -1;
			cout << result << endl;
			return 0;
		}
		else if (temp == " 213456780" || temp == " 132456780" || temp == " 124356780" || temp == " 123546780" || 
			temp == " 123465780" || temp == " 123457680" || temp == " 123456870" )
		{
			break;
		}
		int zero = 0;
		for (int i = 0; i < 10; i++)
		{
			if (temp[i] == '0')
			{
				zero = i;
				break;
			}
		}
		if (zero == 1)
		{
			string ntemp = temp;
			ntemp[1] = temp[2];
			ntemp[2] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[1] = temp[4];
			ntemp[4] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 2)
		{
			string ntemp = temp;
			ntemp[2] = temp[1];
			ntemp[1] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[2] = temp[3];
			ntemp[3] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[2] = temp[5];
			ntemp[5] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 3)
		{
			string ntemp = temp;
			ntemp[3] = temp[2];
			ntemp[2] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[3] = temp[6];
			ntemp[6] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 4)
		{
			string ntemp = temp;
			ntemp[4] = temp[1];
			ntemp[4] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[4] = temp[5];
			ntemp[5] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[4] = temp[7];
			ntemp[7] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 5)
		{
			string ntemp = temp;
			ntemp[5] = temp[2];
			ntemp[2] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[5] = temp[4];
			ntemp[4] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[5] = temp[6];
			ntemp[6] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[5] = temp[8];
			ntemp[8] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 6)
		{
			string ntemp = temp;
			ntemp[6] = temp[3];
			ntemp[3] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[6] = temp[5];
			ntemp[5] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[6] = temp[9];
			ntemp[9] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 7)
		{
			string ntemp = temp;
			ntemp[7] = temp[8];
			ntemp[8] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[1] = temp[4];
			ntemp[4] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 8)
		{
			string ntemp = temp;
			ntemp[8] = temp[5];
			ntemp[5] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[8] = temp[7];
			ntemp[7] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[8] = temp[9];
			ntemp[9] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		else if (zero == 9)
		{
			string ntemp = temp;
			ntemp[9] = temp[6];
			ntemp[6] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
			ntemp = temp;
			ntemp[9] = temp[8];
			ntemp[8] = '0';
			if (check[ntemp] == 0)
			{
				check[ntemp] = count;
				npuzzle.push_back(ntemp);
			}
		}
		if (puzzle.empty())
		{
			puzzle = npuzzle;
			npuzzle.clear();
			count++;
		}
	}
	cout << -1 << endl;
	return 0;
}