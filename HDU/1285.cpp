#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAXN 1000
using namespace std;
int fa[MAXN],sub[MAXN];
int rank[MAXN];
int root;
void init(int n)
{
    for (int i = 0;i<n;++i)
    {
        fa[i] = i;
        sub[i] = i;
    }
}
int find(int x)
{
    if(x==fa[x])
        return x;
    else
        return fa[x];
}
void merge(int i,int j)
{
    fa[i] = fa[j];
    sub[fa[j]] = i;
    fa[j] = i;
    sub[i] = j;
}
int main()
{
    int n, m,p1,p2;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m;++i)
    {
        cin >>p1 >> p2;
        merge(p1, p2);
    }
    for (int i = 1; i <=n;++i)
    {
        if(fa[i]==i)
        {
            root = i;
            break;
        }
    }
    cout << root<<" ";
    while(sub[root]!=root)
    {
        cout << sub[root] << " ";
        root = sub[root];
    }
    return 0;
}
