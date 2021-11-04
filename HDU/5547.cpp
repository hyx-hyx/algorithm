#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
typedef pair<int,int> P;
int main()
{
	int T,t;
	cin >> T;
	t = T;
	while(t--)
	{
		vector<P> pro;
		vector<int> col[4],row[4],area[4];
		char a[4][4];
		For(i,0,4)
		{
			For(j,0,4)
			{
				cin >> a[i][j];
				if(a[i][j] == '*')
					pro.push_back(P(i,j));
				if(a[i][j] != '*')
				{
					col[j].push_back(a[i][j] - '0');
					row[i].push_back(a[i][j] - '0');
					int pos;
					if(i / 2 == j / 2)
						if(i / 2)
							pos = 3;
						else
							pos = 0;
					else
						if(i / 2)
							pos = 2;
						else
							pos = 1;
					area[pos].push_back(a[i][j] - '0');
				}
			}
		}
		For(i,0,pro.size())
		{
			int vis[5] = {0,0,0,0,0};
			P cur = pro[i];
			For(i,0,col[cur.second].size())
				vis[col[cur.second][i]]=1;
			For(i,0,row[cur.first].size())
				vis[row[cur.first][i]] = 1;
			int pos;
			if(cur.first / 2 == cur.second / 2)
				pos = cur.first / 2 + cur.second / 2;
			else
				if(cur.first / 2)
					pos = 2;
				else
					pos = 1;
			For(i,0,area[pos].size())
				vis[area[pos][i]] = 1;
			Fore(i,1,4)
				if(!vis[i])
					a[cur.first][cur.second] = i+ '0';
		}
		cout << "Case #" << T - t << ":" << endl;
		For(i,0,4)
		{
			For(j,0,4)
				cout << a[i][j] - '0';
			cout << endl;
		}
	}
	return 0;
}
