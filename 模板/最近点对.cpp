struct pt
{
	int x,y,id;
};
bool cmpx(const pt a,const pt b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmpy(const pt a,const pt b)
{
	return a.y < b.y;
}
double mindist;
int ansa,ansb;
inline void upd_ans(const pt& a,const pt& b)
{
	double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + .0);
	if(dist < mindist) mindist = dist,ansa = a.id,ansb = b.id;
}
int n;
vector<pt> a;
void rec(int l, int r) 
{
  if (r - l <= 3) 
  {
    for (int i = l; i <= r; ++i)
		for(int j = i + 1; j <= r; ++j) upd_ans(a[i],a[j]);
    sort(a.begin() + l, a.begin() + r + 1,cmpy);
    return;
  }
  int m = (l + r) >> 1;
  int midx = a[m].x;
  rec(l, m), rec(m + 1, r);
  static pt t[maxn];
  merge(a.begin() + l, a.begin() + m + 1, a.begin() + m + 1, a.begin() + r + 1, t, cmpy);
  copy(t, t + r - l + 1, a.begin() + l);

  int tsz = 0;
  for (int i = l; i <= r; ++i)
    if (abs(a[i].x - midx) < mindist) {
      for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
        upd_ans(a[i], t[j]);
      t[tsz++] = a[i];
    }
}
//在主函数中调用,a[i]从0到n-1
sort(a.begin(),a.begin() + n,cmpx);
mindist = 1E20;
rec(0,n - 1);