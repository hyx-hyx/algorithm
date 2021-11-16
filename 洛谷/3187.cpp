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
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 10005;
//`Compares a double to zero`
int sgn(double x)
{
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
//square of a double
inline double sqr(double x)
{
	return x * x;
}
struct Point
{
	double x,y;
	Point()
	{
	}
	Point(double _x,double _y)
	{
		x = _x;
		y = _y;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	void output()
	{
		printf("%.2f %.2f\n",x,y);
	}
	bool operator == (Point b)const
	{
		return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
	}
	bool operator < (Point b)const
	{
		return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
	}
	Point operator -(const Point& b)const
	{
		return Point(x - b.x,y - b.y);
	}
	//叉积
	double operator ^(const Point& b)const
	{
		return x * b.y - y * b.x;
	}
	//点积
	double operator *(const Point& b)const
	{
		return x * b.x + y * b.y;
	}
	//返回长度
	double len()
	{
		return hypot(x,y);//库函数
	}
	//返回长度的平方
	double len2()
	{
		return x * x + y * y;
	}
	//返回两点的距离
	double distance(Point p)
	{
		return hypot(x - p.x,y - p.y);
	}
	Point operator +(const Point& b)const
	{
		return Point(x + b.x,y + b.y);
	}
	Point operator *(const double& k)const
	{
		return Point(x * k,y * k);
	}
	Point operator /(const double& k)const
	{
		return Point(x / k,y / k);
	}
	//`计算pa  和  pb 的夹角`
	//`就是求这个点看a,b 所成的夹角`
	//`测试 LightOJ1203`
	double rad(Point a,Point b)
	{
		Point p = *this;
		return fabs(atan2(fabs((a - p) ^ (b - p)),(a - p) * (b - p)));
	}
	//`化为长度为r的向量`
	Point trunc(double r)
	{
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x * r,y * r);
	}
	//`逆时针旋转90度`
	Point rotleft()
	{
		return Point(-y,x);
	}
	//`顺时针旋转90度`
	Point rotright()
	{
		return Point(y,-x);
	}
	//`绕着p点逆时针旋转angle`
	Point rotate(Point p,double angle)
	{
		Point v = (*this) - p;
		double c = cos(angle),s = sin(angle);
		return Point(p.x + v.x * c - v.y * s,p.y + v.x * s + v.y * c);
	}
};
struct Line
{
	Point s,e;
	Line()
	{
	}
	Line(Point _s,Point _e)
	{
		s = _s;
		e = _e;
	}
	bool operator ==(Line v)
	{
		return (s == v.s) && (e == v.e);
	}
	//`根据一个点和倾斜角angle确定直线,0<=angle<pi`
	Line(Point p,double angle)
	{
		s = p;
		if(sgn(angle - pi / 2) == 0)
		{
			e = (s + Point(0,1));
		}
		else
		{
			e = (s + Point(1,tan(angle)));
		}
	}
	//ax+by+c=0
	Line(double a,double b,double c)
	{
		if(sgn(a) == 0)
		{
			s = Point(0,-c / b);
			e = Point(1,-c / b);
		}
		else if(sgn(b) == 0)
		{
			s = Point(-c / a,0);
			e = Point(-c / a,1);
		}
		else
		{
			s = Point(0,-c / b);
			e = Point(1,(-c - a) / b);
		}
	}
	void input()
	{
		s.input();
		e.input();
	}
	void adjust()
	{
		if(e < s)swap(s,e);
	}
	double length()
	{
		return s.distance(e);
	}
	double dispointtoline(Point p)
	{
		return fabs((p - s) ^ (e - s)) / length();
	}
	//`返回直线倾斜角 0<=angle<pi`
	double angle()
	{
		double k = atan2(e.y - s.y,e.x - s.x);
		if(sgn(k) < 0)k += pi;
		if(sgn(k - pi) == 0)k -= pi;
		return k;
	}
	Point lineprog(Point p)
	{
		return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
	}
};
struct polygon
{
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n)
	{
		n = _n;
		for(int i = 0; i < n; i++)
			p[i].input();
	}
	void add(Point q)
	{
		p[n++] = q;
	}
	void getline()
	{
		for(int i = 0; i < n; i++)
		{
			l[i] = Line(p[i],p[(i + 1) % n]);
		}
	}
	struct cmp
	{
		Point p;
		cmp(const Point& p0)
		{
			p = p0;
		}
		bool operator()(const Point& aa,const Point& bb)
		{
			Point a = aa,b = bb;
			int d = sgn((a - p) ^ (b - p));
			if(d == 0)
			{
				return sgn(a.distance(p) - b.distance(p)) < 0;
			}
			return d > 0;
		}
	};
	void norm()
	{
		Point mi = p[0];
		for(int i = 1; i < n; i++)mi = min(mi,p[i]);
		sort(p,p + n,cmp(mi));
	}
	//`得到凸包`
	//得到的凸包里面的点编号是0~n-1的
	//`两种凸包的方法`
	//`注意如果有影响，要特判下所有点共点，或者共线的特殊情况`
	//`测试 LightOJ1203  LightOJ1239`
	void getconvex(polygon& convex)
	{
		sort(p,p + n);
		convex.n = n;
		for(int i = 0; i < min(n,2); i++)
		{
			convex.p[i] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
		if(n <= 2)return;
		int& top = convex.n;
		top = 1;
		for(int i = 2; i < n; i++)
		{
			while(top && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		int temp = top;
		convex.p[++top] = p[n - 2];
		for(int i = n - 3; i >= 0; i--)
		{
			while(top != temp && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
		convex.norm();//`原来得到的是顺时针的点，排序后逆时针`
	}

};
double cross(Point A,Point B,Point C)
{
	return (B - A) ^ (C - A);
}
//`AB*AC`
double dot(Point A,Point B,Point C)
{
	return (B - A) * (C - A);
}
Point point[4];
double minRectangleCover(polygon A)
{
	//`要特判A.n < 3的情况`
	if(A.n < 3)return 0.0;
	A.p[A.n] = A.p[0];
	double ans = -1;
	int r = 1,p = 1,q;
	for(int i = 0; i < A.n; i++)
	{
		//`卡出离边A.p[i] - A.p[i+1]最远的点`
		while(sgn(cross(A.p[i],A.p[i + 1],A.p[r + 1]) - cross(A.p[i],A.p[i + 1],A.p[r])) >= 0)
			r = (r + 1) % A.n;
		//`卡出A.p[i] - A.p[i+1]方向上正向最远的点`
		while(sgn(dot(A.p[i],A.p[i + 1],A.p[p + 1]) - dot(A.p[i],A.p[i + 1],A.p[p])) >= 0)
			p = (p + 1) % A.n;
		if(i == 0)q = p;
		//`卡出A.p[i] - A.p[i+1]方向上负向最远的点`
		while(sgn(dot(A.p[i],A.p[i + 1],A.p[q + 1]) - dot(A.p[i],A.p[i + 1],A.p[q])) <= 0)
			q = (q + 1) % A.n;
		double d = (A.p[i] - A.p[i + 1]).len2();
		double tmp = cross(A.p[i],A.p[i + 1],A.p[r]) *
			(dot(A.p[i],A.p[i + 1],A.p[p]) - dot(A.p[i],A.p[i + 1],A.p[q])) / d;
		if(ans < 0 || ans > tmp)
		{
			ans = tmp;
			Line line1(A.p[i],A.p[i + 1]);
			point[0] = line1.lineprog(A.p[q]);
			point[1] = line1.lineprog(A.p[p]);
			Line line2(A.p[r],Line(A.p[i],A.p[i + 1]).angle());
			point[2] = line2.lineprog(A.p[p]);
			point[3] = line2.lineprog(A.p[q]);
		}
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		polygon p;
		p.input(n);
		polygon convex;
		p.getconvex(convex);
		printf("%.5lf\n",minRectangleCover(convex));
		int minindex=0;
		For(i,0,4)
		{
			if(point[i].y < point[minindex].y)
				minindex = i;
			else
				if(point[i].y == point[minindex].y)
					if(point[i].x < point[minindex].x)
						minindex = i;
		}
		For(i,0,4)
			printf("%.5lf %.5lf\n",fabs(point[(i + minindex) % 4].x),fabs(point[(i + minindex) % 4].y));
	}
	return 0;
}