#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#define MAXN 50005
#define lowbit(x) (x)&(-x)
int tree[MAXN];
int n;
using namespace std;
void update(int index, int val)
{
    for (int i = index; i <= n; i += lowbit(i))
    {
        tree[i] += val;
    }
}
int query(int n)
{
    int ans = 0;
    for (int i = n; i; i -= lowbit(i))
    {
        ans += tree[i];
    }
    return ans;
}

int query(int a, int b)
{
    return query(b) - query(a - 1);
}
int main()
{
    int t,temp;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        memset(tree, 0, sizeof(tree));
        cin >> n;
        for (int j = 1; j <= n; ++j)
        {
            cin >> temp;
            update(j, temp);
        }
        cout << "Case " << i + 1 << ":" << endl;
        while (cin >> s)
        {
            int a, b;
            if (s == "Query")
            {
                cin >> a >> b;
                cout << query(a, b) << endl;
            }
            if (s == "Add")
            {
                cin >> a >> b;
                update(a, b);
            }
            if (s == "Sub")
            {
                cin >> a >> b;
                update(a, -b);
            }
            if (s == "End")
                break;
        }
    }
    return 0;
}