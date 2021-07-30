#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#define MAXN 1000
#define lowbit(x) (x)&(-x)
int tree[MAXN];
int n;
int a[MAXN];
using namespace std;
void update(int index,int val)
{
    for (int i = index; i <=n;i+=lowbit(i))
        tree[i] += val;
}
int query(int n)
{
    int ans = 0;
    for (int i = n; i;i-=lowbit(i))
        ans += tree[i];
    return ans;
}
int query(int a,int b)
{
    return query(b) - query(a - 1);
}
int main()
{
    while(cin >> n&&n!=0)
    {
        int ans = 0;
        memset(tree, 0, sizeof(tree));
        //memset(a, 0, sizeof(a));
        for (int i = 1; i <=n;++i)
        {
            int temp;
            cin >> temp;
            update(temp,1);
            ans += (i - query(temp));
        }
        cout << ans<< endl;
    }
    return 0;
}