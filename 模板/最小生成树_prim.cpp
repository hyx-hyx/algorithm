struct edge {
	int to;		//边的终点
	int next;	//下一条边储存的位置
	int weight;	//边的权重
} e[MAXM<<1];
//head[i]=x 表示i为起点的一个条边储存的位置
int head[MAXN],dis[MAXN],tot,vis[MAXN];
//存图
inline void addEdge(int u,int v,int w)
{
	++tot;
	e[tot].to=v;
	e[tot].weight=w;
	e[tot].next=head[u];
	head[u]=tot;
}
struct node {
	int dis;
	int pos;//当前访问结点
	int from;//这条边从哪来
	bool operator < (const node& x)const {
		return x.dis<dis;
	}
};
//升序队列，小根堆
priority_queue<node>q;
void Prim()
{
	for(int i=2; i<=n; i++)dis[i]=INF;//初始化
	q.push({0,1,1});//(1,1)的距离为0
	while(!q.empty() && cnt<n) {
		node now = q.top();
		int x = now.pos, d = now.dis;//x为当前访问结点
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		cnt++;
		printf("%d->%d 权重:%d\n",now.from,x,d);
		ans+=d;
		for(int i=head[x]; i!=0; i=e[i].next) {
			if(e[i].weight < dis[e[i].to]) {
				dis[e[i].to]=e[i].weight;
				q.push({ dis[e[i].to], e[i].to, x});
			}
		}
	}
}
