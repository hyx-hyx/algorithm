/*
考虑范围为 k 的狙击手，可以攻击的范围是一个正方体。那我们不妨重新陈述一下题面，称狙击手从 (x,y,z) 可以攻击的范围是所有满足 x ≤ x ′ ≤ x + 2k,y ≤ y ′ ≤ y + 2k,z ≤ z ′ ≤ z + 2k 的 (x ′ ,y ′ ,z ′ )。
那么我们就会发现：如果我们的狙击手的某一维度的坐标小于剩余点的那一维度的最小坐标，我们就应该把狙击手移动的那一维度的最小坐标，因为这样只会让我们能狙击的目标增多。
在我们三个维度都是那一维度的最小坐标时，狙击手就必须将三个维度中某一维度最小坐标的所有敌军都消灭，才能继续移动。这时我们可以贪心的选取所需 k 最小的敌军消灭。
复杂度 O(nlogn)。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int> P;
#define maxn 500005
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		set<P>sets[3];
		vector<vector<int> >pos(3,vector<int>(n+1,0));
		for (int i = 0; i < n; ++i)
		{
			cin >> pos[0][i] >> pos[1][i] >> pos[2][i];
			sets[0].insert(make_pair(pos[0][i], i));
			sets[1].insert(make_pair(pos[1][i], i));
			sets[2].insert(make_pair(pos[2][i], i));
		}
		int ans = 0;
		while (sets[0].size())
		{
			P x = *sets[0].begin(), y = *sets[1].begin(), z = *sets[2].begin();
			vector<P>k;
			for (int i = 0; i < 3; ++i)
			{
				P cur =*sets[i].begin();
				k.push_back(make_pair(max(pos[0][cur.second] - x.first, max(pos[1][cur.second] - y.first, pos[2][cur.second] - z.first)), cur.second));
			}
			sort(k.begin(), k.end());
			ans = max(ans, k[0].first);
			for (int i = 0; i < 3; ++i)
				sets[i].erase(P(pos[i][k[0].second], k[0].second));
		}
		cout << ( ans + 1 ) / 2 << endl;
	}
	return 0;
}