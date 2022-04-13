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
int fa[200005],ranki[200005];
void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        fa[i] = i;
        ranki[i] = 1;
    }
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
void merge(int i,int j)
{
    int x = find(i);
    int y = find(j);
    if(x == y)
        return;
    if(ranki[x] > ranki[y])
        fa[x] = y;
    else
        fa[y] = x;
    if(ranki[x] == ranki[y] && x != y)
        ranki[y]++;
}
bool validPath(int n,vector<vector<int>>&edges,int start,int end)
{
    init(n);
    for(int i = 0; i < edges.size(); ++i)
        merge(edges[i][0],edges[i][1]);
    return find(start) == find(end);
}
int main()
{
    vector<vector<int>> e{{2,6},{4,7},{1,2},{3,5},{7,9},{6,4},{9,8},{0,1},{3,0}};
    cout << validPath(10,e,3,5);
	return 0;
}
