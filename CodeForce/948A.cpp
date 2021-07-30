#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
typedef pair<int, int> Pair;
int main()
{
	int r, c;
	char sheeps[505][505];
	vector<Pair> direction(4);
	direction[0] = Pair(0, 1);
	direction[1] = Pair(0, -1);
	direction[2] = Pair(1, 0);
	direction[3] = Pair(-1, 0);
	queue<Pair> Q;
	cin >> r>>c;
	for (int i = 0; i < r; ++i)
	{
		getchar();
		for (int j = 0; j < c; ++j)
		{
			scanf("%c",&sheeps[i][j]);
			if(sheeps[i][j]=='S')
				Q.push(make_pair(i, j));
		}
		sheeps[i][c] = '\0';
	}
	while (!Q.empty())
	{
		Pair p = Q.front();
		Q.pop();
		int sheep_row = p.first;
		int sheep_col = p.second;
		for (int i = 0; i < 4; ++i)
		{
			int dir_row = direction[i].first;
			int dir_col = direction[i].second;
			if ((sheep_row + dir_row) >= 0 && (sheep_row + dir_row) < r && (sheep_col + dir_col) >= 0 && (sheep_col + dir_col) < c)
			{
				if (sheeps[sheep_row + dir_row][sheep_col + dir_col] == 'W')
				{
					cout << "No" << endl;
					return 0;
				}
				if (sheeps[sheep_row + dir_row][sheep_col + dir_col] == '.')
					sheeps[sheep_row + dir_row][sheep_col + dir_col] = 'D';
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			printf("%c", sheeps[i][j]);
		}
		printf("\n");
	}
	return 0;
}