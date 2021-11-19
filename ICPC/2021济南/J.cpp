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
const int MOD = 1e9 + 7;
const double EPS = 1E-9;
double Gauss(vector<vector<double>> a)
{
    double det = 1;
    for(int i = 0; i < a.size(); ++i)
    {
        int k = i;
        for(int j = i + 1; j < a.size(); ++j)
            if(abs(a[j][i]) > abs(a[k][i])) k = j;
        if(abs(a[k][i]) < EPS)
        {
            det = 0;
            break;
        }
        swap(a[i],a[k]);
        if(i != k) det = -det;
        det *= a[i][i];
        for(int j = i + 1; j < a.size(); ++j) a[i][j] /= a[i][i];
        for(int j = 0; j < a.size(); ++j)
            if(j != i && abs(a[j][i]) > EPS)
                for(int k = i + 1; k < a.size(); ++k) a[j][k] -= (a[i][k] * a[j][i]);
    }
    return det;
}
string s;
ll mod()
{
	ll ans = s[0] - '0';
	For(i,1,s.size())
		ans = (ans * 10 % MOD + s[i] - '0')%MOD;
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
        vector<vector<double>> a(n,vector<double>(n,0));
		cin >> s;
        For(i,0,n)
        {
            For(j,0,n)
                cin >> a[i][j];
        }
        ll ans=(ll)Gauss(a);
        printf("%c\n",ans == mod() ? '+' : '-');
	}
	return 0;
}
