/*
题意：给定一张n*m的方格，起点在左上角，只能向下或向右走，地图中有k个地雷，人不能走到地雷上，问可能到达的点有多少。
分析：
我们考虑行的转移，在这一行上初始不可达点是输入中的点，对于这样的点，它会阻挡人从左方走过来，对于他右侧的点，只有从上方可达转移下来的点才能到，如果这个点右侧的某个点x上方也是不可达的，那么这个点x一定也不可达。
也就是说初始不可达点可以向右“染色”，就是找到右方最远的pos，使得pos上方为1也就是不可达。之后将这一段全部染为1.
染色操作和找操作应当都可以使用数据结构优化成log，至于答案就是每一行1的个数，区间查询就行。
空间受限肯定不可能开O（n)棵树，显然当前这一行答案只与上一行答案有关，所以我们开两颗树，类似01背包的空间优化那样滚动着用应该就可以了。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define ls (x<<1)
#define rs (x<<1|1)
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
vector<int>e[N];
//lz为懒标记，tr[2][N<<4]:线段树一般size为节点个数的4倍，tr[2]是因为这里用了两棵线段树进行类似滚动数组处理。
int tr[2][N << 2], lz[2][N << 2]; 

void push_down(int f, int x, int l, int r, int mid) 
{
	if (lz[f][x] == -1)return;
	tr[f][ls] = lz[f][x] * (mid - l + 1);
	tr[f][rs] = lz[f][x] * (r - mid);
	lz[f][ls] = lz[f][rs] = lz[f][x];
	lz[f][x] = -1;
}
/*
f:哪棵树，tr数组的下标，即tr[f]
x:根节点
l、r:x表示的节点的区间
L、R：需要修改的区间
v:修改的值
*/
void update(int f, int x, int l, int r, int L, int R, int v) 
{
	if (L <= l && R >= r)
	{
		tr[f][x] = (r - l + 1) * v;
		lz[f][x] = v;
		return;
	}
	int mid = (l + r) >> 1;
	push_down(f, x, l, r, mid);
	if (R <= mid)update(f, ls, l, mid, L, R, v);
	else if (L > mid)update(f, rs, mid + 1, r, L, R, v);
	else 
	{
		update(f, ls, l, mid, L, mid, v);
		update(f, rs, mid + 1, r, mid + 1, R, v);
	}
	tr[f][x] = tr[f][ls] + tr[f][rs];
}
/*
f:哪棵树，tr数组的下标，即tr[f]
x:根节点
l、r:x表示的节点的区间
L、R：需要查询的区间
返回值：左端点位置
*/
int query(int f, int x, int l, int r, int L, int R) 
{  
	if (!tr[f][x])return inf;
	if (l == r)return l;
	int mid = l + r >> 1;
	push_down(f, x, l, r, mid);
	if (L <= l && R >= r) 
	{
		if (tr[f][ls] > 0) return query(f, ls, l, mid, l, mid);
		else return query(f, rs, mid + 1, r, mid + 1, r);
	}
	else
	{
		if (R <= mid)return query(f, ls, l, mid, L, R);
		else if (L > mid)return query(f, rs, mid + 1, r, L, R);
		else return min(query(f, ls, l, mid, L, mid), query(f, rs, mid + 1, r, mid + 1, R));
	}
}
int main() 
{
	int T;
	scanf("%d", &T);
	while (T--) 
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; ++i)e[i].clear();
		for (int i = 1; i <= (m << 2); ++i) 
		{
			tr[0][i] = tr[1][i] = 0;
			lz[0][i] = lz[1][i] = -1;
		}
		for (int i = 0; i < k; ++i) 
		{
			int x, y;
			scanf("%d %d", &x, &y);
			e[x].push_back(y);
		}
		long long ans = 0;
		update(0, 1, 1, m, 1, 1, 1);
		for (int x = 1; x <= n; ++x) 
		{
			int l = 0;
			sort(e[x].begin(), e[x].end());
			for (auto& y : e[x])
			{
				if (y - 1 >= l + 1) 
				{
					//因为x取值1-n，tr数组下标只有0,1，所以x&1只取0,1。因为a^1=~a,所以(x&1)^1==~(x&1)
					//tr[(x&1)^1]为保存上一行状态的线段树，tr[(x&1)]为保存当前行状态的线段树，
					//以下两行代码含义为：查询上一行从1到y-1是否无地雷区间的最左端点pos，并在另一棵树中将[pos,y-1]的区间更新为1。
					int pos = query((x & 1) ^ 1, 1, 1, m, l + 1, y - 1); 
					if (pos != inf)update(x & 1, 1, 1, m, pos, y - 1, 1);
				}
				//l值更新为上一个地雷的位置
				l = y;
			}
			//对最右边的地雷到最右边一列区间的查询和更新
			if (l + 1 <= m) 
			{
				int pos = query((x & 1) ^ 1, 1, 1, m, l + 1, m);
				if (pos != inf)
					update(x & 1, 1, 1, m, pos, m, 1);
			}
			//从保存当前行的线段树的根节点读取可到达的点，保存答案
			ans += tr[x & 1][1];
			//将另一个树置0，为下一次循环做准备
			update((x & 1) ^ 1, 1, 1, m, 1, m, 0);
		}
		printf("%lld\n", ans);
	}
	return 0;
}