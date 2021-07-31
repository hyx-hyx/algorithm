#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 100005
using namespace std;
vector<int> e(maxn);
int deg[maxn], A[maxn];
vector<int> edges[maxn];
int toposort(int n)
{
    int cnt = 0;
    queue<int> q;
    for (int i = 0; i <n; ++i)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        A[cnt++] = t;
        for (int i=0;i<edges[t].size();++i)
        {
            int to = edges[t][i];
            deg[to]--;
            if (deg[to] == 0) 
                q.push(to);
        }
    }
    return cnt;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &e[i]);
    for (int i = 0; i < m; ++i)
    {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        edges[t2].push_back(t1);
        deg[t1]++;
    }
    toposort(n);
    int flag = 0;
    int count=0;
    for (int i = 0; i < n; ++i)
    {
        if (e[A[i]])
        {
            if (!flag)
            {
                count++;
                flag = 1;
            }
        }
        else
            flag = 0;
    }
    printf("%d", count);
	return 0;
}