#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 50000
#define lowbit(x) (x)&(-x)
int tree[MAXN + 1];
void update(int index,int val)
{
    for (int i = index; i <= MAXN;i+=lowbit(i))
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
    int n,ans=0;
    vector<int> nums(100);
    cin >> n;
    for (int i = 1;i<=n;++i)
    {
        cin >> nums[i];
        update(nums[i], 1);
        ans+=query(nums[i]*2+1,MAXN);
    }
    cout << ans << endl;
    return 0;
}