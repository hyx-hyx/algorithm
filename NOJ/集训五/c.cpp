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
#define maxn 1000005
#define lowbit(x) ((x)&(-x))
using namespace std;
int tree[maxn];
inline void update(int i,int x)
{
	for(int pos = i; pos < maxn; pos += lowbit(pos))
		tree[pos] += x;
}
inline int query(int n)
{
	int ans = 0;
	for(int pos = n; pos; pos -= lowbit(pos))
		ans += tree[pos];
	return ans;
}
inline int query(int a,int b)
{
	return query(b) - query(a - 1);
}
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	int A[maxn];
	For(i,0,n)
	{
		int x;
		cin >> x;
		A[i] = x;
	}
	int C[maxn],L[maxn];
	memcpy(C,A,sizeof(A)); // 复制
	sort(C,C + n); // 排序
	for(int i = 0; i < n; ++i)
		L[i] = lower_bound(C,C + n,A[i]) - C + 1; // 查找
	for(int i=0;i<n;++i)
	{
		update(L[i],1);
		ans += (query(n)-query(1,L[i]));
	}
	cout << ans << endl;
	return 0;
}

