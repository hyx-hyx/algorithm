## 题意
[题目链接](https://codeforces.com/problemset/problem/801/D)

按顺时针给出n个点,n<=1e3,组成的凸多边形,求出最大的D,使得任意点按任意方向移动不超过D后,n个点依然组成凸多边形.
## 分析
对于每个点来说，将相邻两个点连一条直线，每个点与该直线组成一个三角形。

要想保持凸多边形，每个点移动的距离最多使点在这条直线上，若超过，则为凹多边形。

只需遍历每个点，求出点到所连直线的距离再除以2即为d。

关于除2，相邻两点同时往当前点移动d，则直线往当前点移动d距离。当前点再向直线移动d，刚好重合。所以点到所连直线的距离为2*d。
### 点线距离模板
```cpp
/**********************计算几何----点线距离模板***********/
const double eps = 1e-8;
const int maxn=1010;
struct Point
{
    double x,y;
    Point(double x = 0,double y = 0) :x(x),y(y)
    {
    }
}points[maxn];

typedef Point point;

point operator -(Point a,Point b)
{
    return point(a.x - b.x,a.y - b.y);
}
point operator +(Point a,Point b)
{
    return point(a.x + b.x,a.y + b.y);
}
point operator *(Point a,double t)
{
    return point(a.x * t,a.y * t);
}
point operator /(Point a,double t)
{
    return point(a.x / t,a.y / t);
}
bool operator < (const Point& a,const Point& b)
{
    return a.y < b.y || (fabs(a.y - b.y) <= eps && a.x < b.x);
}
bool operator == (const Point& a,const Point& b)
{
    if(fabs(a.x - b.x) <= eps && fabs(a.y - b.y) <= eps)
        return true;
    return false;
}
int dcmp(double x)
{
    if(fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}

double dot(point a,point b) //点积
{
    return a.x * b.x + a.y * b.y;
}
double cross(Point a,Point b) //叉积
{
    return a.x * b.y - a.y * b.x;
}
/*两点之间的距离*/
double disn(Point a,Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}
double lentgh(Point a)//向量长度
{
    return sqrt(dot(a,a));
}
double vec_angle(point a,point b)//两向量夹角
{
    return acos(dot(a,b) / lentgh(a) / lentgh(b));
}
/*
点到直线的距离
若不取绝对值 表示有向距离
*/
double distance(Point p,Point a,Point b)
{
    point v1 = b - a;
    point v2 = p - a;
    return fabs(cross(v1,v2)) / lentgh(v1);

}
/**********************计算几何----点线距离模板***********/
```
完整代码：
```cpp
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;
const int INF = 1e9 + 7;
const ll inf = (1LL << 62);
const int MOD = 1e9 + 7;
const ll mod = (1LL << 32);
const int N = 1e6 + 6;
const int M = 100010;
const int maxn = 1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
struct Point
{
    double x,y;
    Point(double x = 0,double y = 0) :x(x),y(y)
    {
    }
}points[1000010];

typedef Point point;

point operator -(Point a,Point b)
{
    return point(a.x - b.x,a.y - b.y);
}
point operator +(Point a,Point b)
{
    return point(a.x + b.x,a.y + b.y);
}
point operator *(Point a,double t)
{
    return point(a.x * t,a.y * t);
}
point operator /(Point a,double t)
{
    return point(a.x / t,a.y / t);
}
bool operator < (const Point& a,const Point& b)
{
    return a.y < b.y || (fabs(a.y - b.y) <= eps && a.x < b.x);
}
bool operator == (const Point& a,const Point& b)
{
    if(fabs(a.x - b.x) <= eps && fabs(a.y - b.y) <= eps)
        return true;
    return false;
}
int dcmp(double x)
{
    if(fabs(x) <= eps) return 0;
    return x < 0 ? -1 : 1;
}

double dot(point a,point b) //点积
{
    return a.x * b.x + a.y * b.y;
}
double cross(Point a,Point b) //叉积
{
    return a.x * b.y - a.y * b.x;
}
/*两点之间的距离*/
double disn(Point a,Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}
double lentgh(Point a)//向量长度
{
    return sqrt(dot(a,a));
}
double vec_angle(point a,point b)//两向量夹角
{
    return acos(dot(a,b) / lentgh(a) / lentgh(b));
}
/*
点到直线的距离
若不取绝对值 表示有向距离
*/
double distance(Point p,Point a,Point b)
{
    point v1 = b - a;
    point v2 = p - a;
    return fabs(cross(v1,v2)) / lentgh(v1);

}
int main()
{
	int n;
	scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%lf%lf",&points[i].x,&points[i].y);
	double ans = 1e9;
    for(int i = 0; i < n; ++i)
    {
        int next = (i + 1 == n ? 0 : i + 1);
        int last = (i - 1 == -1 ? n - 1 : i - 1);
        ans = min(distance(points[i],points[next],points[last]) / 2,ans);
    }
	printf("%.10lf",ans);
	return 0;
}
```