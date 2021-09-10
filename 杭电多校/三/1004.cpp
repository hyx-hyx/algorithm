#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
const int N=100005;
//f下标i对应直线出现的次数，值对应有多少种出现了i次的直线。
int Case,n,i,j,k,f[N];
P a[N];
inline int abs(int x){return x>0?x:-x;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      int dx=x2-x1,dy=y2-y1;
      if(dx==0)dy=1;
      else if(dy==0)dx=1;
      else{
        if(dx<0)dx=-dx,dy=-dy; 
        int d=gcd(abs(dx),abs(dy));
        dx/=d,dy/=d;
      }
      a[i]=P(dx,dy);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)f[i]=0;
    for(i=1;i<=n;i=j){
      for(j=i;j<=n&&a[i]==a[j];j++);
      for(k=1;k<=j-i;k++)f[k]++;
    }
    for(i=j=1;i<=n;i++){
      while(!f[j])j++;
      f[j]--;
      printf("%d\n",i-j);
    }
  }
}
//=========================================================
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
typedef pair<int,int>P;
map<P,int> mp;
int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,xa,ya,xb,yb;
		cin >> n;
		mp.clear();
		int maxv = -1;
		for(int i = 1; i <= n; ++i)
		{
			cin >> xa >> ya >> xb >> yb;
			int diffx = xa - xb;
			int diffy = ya - yb;
			if(diffx == 0)
				diffy = 1;
			else
			{
				if(diffy == 0)
					diffx = 1;
				else
				{
					int d = gcd(abs(diffx),abs(diffy));
					diffx /= d,diffy /= d;
					if((xa - xb) < 0)
						diffx = -diffx,diffy = -diffy;
				}
			}
			if(mp.find(P(diffy,diffx)) == mp.end())
				mp[P(diffy,diffx)] = 1;
			else
				mp[P(diffy,diffx)]++;
			maxv = max(maxv,mp[P(diffy,diffx)]);
		}
		int size = mp.size();
		for(int i = 1; i <= n; ++i)
		{
			if(i <= size)
				cout << i - 1 << endl;
			else
				cout << i-(i / size+i%size) << endl;
		}
	}
	return 0;
}