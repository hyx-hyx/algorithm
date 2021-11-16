#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<unordered_map>
#define For(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define Fore(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
typedef long long ll;
using namespace std;
struct node
{
	int x,y,h;
	double n;
}roof[2505];
int vis[500][500] = {0};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool cmp(node a,node b)
{
	return a.h < b.h;
}
queue<node> q;
int n,m;
int check(int x,int y)
{
	if(x >= 1 && x <= n && y >= 0 && y <= n && !vis[x][y])
		return 1;
	else
		return 0;
}
void bfs()
{
	while(!q.empty())
	{
		node cur = q.front();
		q.pop();
		int cnt = 0;
		For(i,0,4)
		{
			int x = cur.x,y = cur.y;
			x += dir[i][0],y += dir[i][1];
			if(check(x,y))
				if(cur.h > roof[x * n + y].h)
				{
					cnt++,q.push(roof[x * n + y]);
					vis[x][y]=1;
				}
		}
		For(i,0,4)
		{
			int x = cur.x,y = cur.y;
			x += dir[i][0],y += dir[i][1];
			if(check(x,y))
				if(cur.h > roof[x * n + y].h)
					roof[x * n + y].n += cur.n / cnt;
		}
	}
}
int main()
{
	cin >> n >> m;
	int cnt = 0;
	Fore(i,1,n)
	{
		Fore(j,1,n)
		{
			cin >> roof[cnt].h;
			roof[cnt].x = i,roof[cnt].y = j,roof[cnt].n = m;
		}
	}
	sort(roof,roof + cnt,cmp);
	q.push(roof[0]);
	bfs();
	return 0;
}
