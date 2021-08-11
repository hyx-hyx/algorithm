//Ford-Fulkerson算法
#define INF 0x3f3f3f3f
int n, m, s, t; // s是源点，t是汇点
bool vis[maxn];
int dfs(int p = s, int flow = INF)
{
    if (p == t)
        return flow; // 到达终点，返回这条增广路的流量
    vis[p] = true;
    for (int eg = head[p]; eg; eg = edges[eg].next)
    {
        int to = edges[eg].to, vol = edges[eg].w, c;
        // 返回的条件是残余容量大于0、未访问过该点且接下来可以达到终点（递归地实现）
        // 传递下去的流量是边的容量与当前流量中的较小值
        if (vol > 0 && !vis[to] && (c = dfs(to, min(vol, flow))) != -1)
        {
            edges[eg].w -= c;
            edges[eg ^ 1].w += c;
            // 这是链式前向星取反向边的一种简易的方法
            // 建图时要把cnt置为1，且要保证反向边紧接着正向边建立
            return c;
        }
    }
    return -1; // 无法到达终点
}
inline int FF()
{
    int ans = 0, c;
    while ((c = dfs()) != -1)
    {
        memset(vis, 0, sizeof(vis));
        ans += c;
    }
    return ans;
}
//==========================================================================================

//EK算法就是BFS实现的FF算法。
int n, m, s, t, last[maxn], flow[maxn];
inline int bfs()
{
    memset(last, -1, sizeof(last));
    queue<int> q;
    q.push(s);
    flow[s] = INF;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (p == t) // 到达汇点，结束搜索
            break;
        for (int eg = head[p]; eg; eg = edges[eg].next)
        {
            int to = edges[eg].to, vol = edges[eg].w;
            if (vol > 0 && last[to] == -1) // 如果残余容量大于0且未访问过（所以last保持在-1）
            {
                last[to] = eg;
                flow[to] = min(flow[p], vol);
                q.push(to);
            }
        }
    }
    return last[t] != -1;
}
inline int EK()
{
    int maxflow = 0;
    while (bfs())
    {
        maxflow += flow[t];
        for (int i = t; i != s; i = edges[last[i] ^ 1].to) // 从汇点原路返回更新残余容量
        {
            edges[last[i]].w -= flow[t];
            edges[last[i] ^ 1].w += flow[t];
        }
    }
    return maxflow;
}
//===========================================================================================

/*
然而，最常用的网络流算法是Dinic算法。作为FF/EK算法的优化，它选择了先用BFS分层，再用DFS寻找。它的时间复杂度上界是 [公式] 。
所谓分层，其实就是预处理出源点到每个点的距离（注意每次循环都要预处理一次，因为有些边可能容量变为0不能再走）。
我们只往层数高的方向增广，可以保证不走回头路也不绕圈子。
我们可以使用多路增广节省很多花在重复路线上的时间：在某点DFS找到一条增广路后，如果还剩下多余的流量未用，继续在该点DFS尝试找到更多增广路。
此外还有当前弧优化。因为在Dinic算法中，一条边增广一次后就不会再次增广了，所以下次增广时不需要再考虑这条边。我们把head数组复制一份，但不断更新增广的起点。
值得注意的是，这个算法如果用在二分图中,优于匈牙利算法。
*/
int n, m, s, t, lv[maxn], cur[maxn]; // lv是每个点的层数，cur用于当前弧优化标记增广起点
inline bool bfs() // BFS分层
{
    memset(lv, -1, sizeof(lv));
    lv[s] = 0;
    memcpy(cur, head, sizeof(head)); // 当前弧优化初始化
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int eg = head[p]; eg; eg = edges[eg].next)
        {
            int to = edges[eg].to, vol = edges[eg].w;
            if (vol > 0 && lv[to] == -1)
                lv[to] = lv[p] + 1, q.push(to);
        }
    }
    return lv[t] != -1; // 如果汇点未访问过说明已经无法达到汇点，此时返回false
}
int dfs(int p = s, int flow = INF)
{
    if (p == t)
        return flow;
    int rmn = flow; // 剩余的流量
    for (int eg = cur[p]; eg && rmn; eg = edges[eg].next) // 如果已经没有剩余流量则退出
    {
        cur[p] = eg; // 当前弧优化，更新当前弧
        int to = edges[eg].to, vol = edges[eg].w;
        if (vol > 0 && lv[to] == lv[p] + 1) // 往层数高的方向增广
        {
            int c = dfs(to, min(vol, rmn)); // 尽可能多地传递流量
            rmn -= c; // 剩余流量减少
            edges[eg].w -= c; // 更新残余容量
            edges[eg ^ 1].w += c; // 再次提醒，链式前向星的cnt需要初始化为1（或-1）才能这样求反向边
        }
    }
    return flow - rmn; // 返回传递出去的流量的大小
}
inline int dinic()
{
    int ans = 0;
    while (bfs())
        ans += dfs();
    return ans;
}
//=================================================================================================
/*最大流最小割定理:
所谓割，就是从网络中选择一些边，使得去掉这些边后，剩下两个不连通的分别包含源点和汇点的点集。
割的大小是这些边的容量之和。在所有可行的割中，最小的割称为最小割。
这个神奇的定理只有短短几个字：最大流等于最小割。
*/