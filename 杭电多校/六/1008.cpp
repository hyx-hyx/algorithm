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

using ll = long long; using db = long double; using str = string;
using pi = pair<int, int>; using pl = pair<ll, ll>; using pd = pair<db, db>;
using vi = vector<int>; using vb = vector<bool>; using vl = vector<ll>;
using vd = vector<db>; using vs = vector<str>;
using vpi = vector<pi>; using vpl = vector<pl>; using vpd = vector<pd>;

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;  tcT, size_t SZ > using AR = array<T, SZ>; tcT > using PR = pair<T, T>;

#define mp make_pair 
#define f first
#define s second
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define lb lower_bound
#define ub upper_bound

tcT > int lwb(V<T>& a, const T& b) { return int(lb(all(a), b) - bg(a)); }

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9 + 7;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }; // for every grid problem!!
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll cdiv(ll a, ll b) { return a / b + ( ( a ^ b ) > 0 && a % b ); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ( ( a ^ b ) < 0 && a % b ); } // divide a by b rounded down
tcT > bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
tcT > bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
tcTU > T fstTrue(T lo, T hi, U f) { hi++; assert(lo <= hi); while (lo < hi) { T mid = lo + ( hi - lo ) / 2; f(mid) ? hi = mid : lo = mid + 1; } return lo; }
tcTU > T lstTrue(T lo, T hi, U f) { lo--; assert(lo <= hi); while (lo < hi) { T mid = lo + ( hi - lo + 1 ) / 2; f(mid) ? lo = mid : hi = mid - 1; } return lo; }
tcT > void remDup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }
tcTU > void erase(T& t, const U& u) { auto it = t.find(u); assert(it != end(t)); t.erase(it); }

void solve(){
	int n;
	vi x, y, z;
	cin >> n;
	x.rsz(n); y.rsz(n); z.rsz(n); F0R(i, n) cin >> x[i] >> y[i] >> z[i];
	set<pi> A, B, C;
	F0R(i, n) {
		A.ins(mp(x[i], i));
		B.ins(mp(y[i], i));
		C.ins(mp(z[i], i));
	}
	int cx, cy, cz, ans = 0;
	while (A.size()) {
		pi c = *A.begin(), d = *B.begin(), e = *C.begin();
		cx = c.f; cy = d.f; cz = e.f;
		vpi K;
		K.pb(mp(max(x[c.s] - cx, max(y[c.s] - cy, z[c.s] - cz)), c.s)); c = d;
		K.pb(mp(max(x[c.s] - cx, max(y[c.s] - cy, z[c.s] - cz)), c.s)); c = e;
		K.pb(mp(max(x[c.s] - cx, max(y[c.s] - cy, z[c.s] - cz)), c.s));
		sor(K);
		ans = max(ans, K[0].f);
		C.erase(mp(z[K[0].s], K[0].s));
		B.erase(mp(y[K[0].s], K[0].s));
		A.erase(mp(x[K[0].s], K[0].s));
	}
	cout << ( ans + 1 ) / 2 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	// END OF CODE
	return 0;
}
//=============================
/*
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
		set<pair<int,int> >sets[3];
		vector<int>pos[3];
		for (int i = 0; i < n; ++i)
		{
			int x, y, z;
			cin >> pos[0][i] >> pos[1][i] >> pos[2][i];
			sets[0].insert(make_pair(x, i));
			sets[1].insert(make_pair(y, i));
			sets[2].insert(make_pair(z, i));
		}
		vector<pair<int,int> >k;
		int ans = 0;
		while (sets[0].size())
		{
			pair<int,int> x = sets[0].begin(), y = sets[1].begin(), z = sets[2].begin();
			pair<int,int> cur = x;
			for (int i = 0; i < 3; ++i)
			{
				P cur=sets[i].begin();
				k.push_back(make_pair(max(pos[0][cur.second]-cur.first, max(pos[1][cur.second]-y.first,pos[2][cur.second]-z.first)), cur.second));
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

*/