#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 10000
int fa[MAXN];
int value[10000];
void init(int n)
{
    for (int i = 0; i < n;++i)
    {
        fa[i] = i;
        value[i] = 0;
    }
}
int find(int x)
{
    if(x!=fa[x])
    {
        int t = value[x];
        fa[x] = find(fa[x]);
        value[x] += value[t];
    }
    return fa[x];
}
void merge(int i,int j,int s)
{
    if(find(i)!=find(j))
    {
        fa[find(i)] = find(j);
        value[find(i)] = -value[i] + value[j] +s;
    }
}
int main()
{
    int n,m,low,up,answer,ans=0;
    cin >> n >> m;
    for (int i = 0; i < m;++i)
    {
        cin >> low >> up >> answer;
        if(find(low)==find(up))
        {
            if(value[low]-value[up]!=answer)
                ans ++;
        }
        else
            merge(low, up, answer);
    }
    cout << ans << endl;
    return 0;