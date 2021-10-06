#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fastpower(ll base,ll power)
{
    ll res = 1;
    while(power)
    {
        if(power&1)
            res = res*base;
        base *= base;
        power >>= 1;
    }
    return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
    string s;
    int m=fastpower(2,n);
    for(int i = 0; i<m; ++i)
    {
        int cnt = 0;
        int num = i;
        while(num)
        {         
            if(num&1)
                cnt++;
            num >>= 1;
        }
        if(cnt%2)
            s.push_back('1');
        else
            s.push_back('0');
    }
    for(int i = 0; i<s.size(); ++i)
        cout<<s[i];
	return 0;
}
