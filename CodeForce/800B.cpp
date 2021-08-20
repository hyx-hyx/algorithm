#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath> 
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int maxn = 1010;
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
