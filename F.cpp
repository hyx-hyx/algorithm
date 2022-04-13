#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
int MAXN = 205;
int T, maxDis, u;
typedef pair<int,int> P;
std::vector<P> v;
vector<bool> hasV(MAXN);
vector<bool> has(MAXN);
vector<vector<int>> g(MAXN);
vector<int> f;
int ans=INT_MIN;
void get(int curnode){
	hasV[curnode] = true;
	for(auto ne : g[curnode]){ 
		if(not hasV) get(ne);
 	} 
}
int dfs(int curnode, int dis){
	if(dis > maxDis){
		u = curnode;
		maxDis = dis;
	 }
	 has[curnode] = true;
	 for(auto next : g[curnode]){ 
	 	if(not has[next]) dfs(next, dis + 1);
	 }
}
int getL(int curnode){ 
	maxDis = -1;
	has = vector<bool>(false);
	dfs(1, 0);
	maxDis = -1;
	dfs(u, 0);
	return maxDis;
}
int m, from, to;
int main(int argc, char * argv[]){
	cin >> m;
	for(int i = 0; i < m; i++){ 
		cin >> from >>to;
		v.push_back({from, to});
		g[from].push_back(to);
		g[to].push_back(from);
	}
	for(auto it : v){ 
		hasV = vector<bool>(MAXN, false);
		P del;
		for(auto ite = g[it.first].begin(); it != g[it.first].end(); it++){ 
			if(*ite == it.second) v[it.first].erase(ite);
		}
		for(auto ite = g[it.second].begin(); it != g[it.second].end(); it++){ 
			if(*ite == it.first) v[it.second].erase(ite);
		}
		int first = 1, second = 1;
		while(hasV[second]) second++;
		ans = max(ans, getL(first)*getL(second));
		g[del.first].push_back(del.second);
		g[del.second].push_back(del.first);
	}
	cout << ans << endl;
    return 0;
}