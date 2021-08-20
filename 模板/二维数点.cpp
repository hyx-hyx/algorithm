/*我们设S(x,y)表示(0,0)(x,y)这个矩阵中点的个数
每次询问的答案很明显是
S(c,d)−S(a−1,d)−S(c,b−1)+S(c−1,d−1)
我们就将个询问拆成这四部分分解维护
之后用扫描线的思想维护树状数组,大体思路是这样的:
先将所有的点,和我们拆分完成之后的询问全部按照x进行排序
(对于x这一维)之后每次扫到一个询问的x,就把当前还剩下的小于等于x的点全部加上这个点在y这一维的贡献(可能有点绕)
就是我们把树状数组的下标看做权值
当前影响的是1−y这个范围的点.所以在树状数组上将这个区间的贡献+1s
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e5 + 5;  //查询次数
int c[10000003];//树状数组
int n,m;
int ans[N]; 
struct tree   //存储每个点的结构体 
{
	int x,y;
}v[N];
struct ques  //离线算法，存储每一次查询
{
	int x,y;
	int id,opt; //id:第几次查询
	ques(int xx = 0,int yy = 0,int num = 0,int o = 0)
	{
		x = xx,y = yy,id = num,opt = o;
	}
}q[N << 2]; //记录查询的数组
inline bool cmp1(tree x,tree y)
{
	return x.x < y.x;
}
inline bool cmp2(ques x,ques y)
{
	return x.x < y.x;
}
inline void updata(int x,int val)
{
	for(; x <= n; x += x & -x) c[x] += val;
}
inline int query(int x)
{
	int res = 0;
	for(; x; x -= x & -x) res += c[x];
	return res;
}
int main()
{
	int cnt = 0;
	cin >> n >> m;
	int x,y;
	for(int i = 1; i <= n; ++i)
		cin >> x >> y,v[i].x = x+ 1,v[i].y =y + 1;    //v数组存储每个点的坐标
	for(int i = 1; i <= m; ++i)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2; 
		x1++,x2++,y1++,y2++;                      //树状数组下标从1开始，查询的x1,y1,x2,y2加1
		q[++cnt] = ques(x2,y2,i,1);              //q数组用ques结构体存储每次查询的信息，
		q[++cnt] = ques(x1 - 1,y2,i,-1);
		q[++cnt] = ques(x2,y1 - 1,i,-1);
		q[++cnt] = ques(x1 - 1,y1 - 1,i,1);
	}
	sort(v + 1,v + n + 1,cmp1);                   //对每个点按x排序
	sort(q + 1,q + cnt + 1,cmp2);                //对每一次查询按x排序
	int now = 1;                              //当前的点
	for(int i = 1; i <= cnt; ++i)
	{
		while(v[now].x <= q[i].x && now <= n)    //当前x值小于查询的x时，说明当前点在查询范围内。将当前点的y值存入树状数组中
			updata(v[now].y,1),now++;  
		ans[q[i].id] += q[i].opt * query(q[i].y);     //答案按每次查询的id存储
	}
	for(int i = 1; i <= m; ++i) printf("%d\n",ans[i]);
	return 0;
}
