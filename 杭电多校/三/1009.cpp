//link:https://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1009&cid=986/
/*分析：设 f i,j,k 表示从 (1,1) 走到 (i,j)，一路上收集了 k 个钻石时，钻石的单价最高能涨到多少，
则 ans = max(k × f n,n,k )。
对于固定的 (i,j) 来说，考虑两个状态 f i,j,x 和 f i,j,y ，其中 x < y，如果 f i,j,x ≤ f i,j,y ，则
状态 f i,j,x 一定不可能发展为最优解，可以剔除。对于每个 (i,j)，用列表按照 k 升序保存所有
状态，并剔除不可能成为最优解的状态即可。
随机数据下当 n = 100 时，单个 (i,j) 的有效状态的峰值 k 大约为几千。时间复杂度
O(n 2 k)。*/
#define _CRT_secondCURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<P> V;

int n;
ll a[105][105], b[105][105];
vector<P> p[105][105];

void solve(const V& x, const V& y, V& z)
{
	int sx = x.size();
	int sy = y.size();
	int i = 0, j = 0;
	while ((i < sx || j < sy) && z.size() < 100)
	{
		if (i < sx && j < sy) z.push_back(x[i].first * x[i].second > y[j].first * y[j].second ? x[i++] : y[j++]);
		else if (i < sx) z.push_back(x[i++]);
		else if (j < sy) z.push_back(y[j++]);
	}
}

bool cmp(P x, P y)
{
	return x.first * x.second > y.first * y.second;
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%lld", &a[i][j]), p[i][j].clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%lld", &b[i][j]);
		p[1][1].push_back(make_pair(a[1][1], b[1][1]));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == 1 && j == 1) continue;  //当前在(1,1),直接跳过
				if (i == 1) p[i][j].push_back(p[i][j - 1][0]);  //当前在第一行，则直接初始化为左边一列
				else if (j == 1) p[i][j].push_back(p[i - 1][j][0]); //当前在第一列，用上一行初始化
				else solve(p[i - 1][j], p[i][j - 1], p[i][j]);  //其他情况对坐标(i-1,j)和(i,j-1)选取最大值，将比较结果存入p[i][j];
				for (int k = 0; k < p[i][j].size(); k++) p[i][j][k].first += a[i][j], p[i][j][k].second += b[i][j];    //对当前每一个位置下的每一种状态加上当前单元格的收益
				sort(p[i][j].begin(), p[i][j].end(), cmp);   //对每一个位置的每一种状态的收益进行排序
			}
		ll ans = 0;
		for (int i = 0; i < p[n][n].size(); i++)
		{
			ans = max(ans, p[n][n][i].first * p[n][n][i].second);  //对(n,n)位置的每一种可能状态进行比较，取最大。
		}
		printf("%lld\n", ans);
	}
	return 0;
}