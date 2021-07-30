// deg是入度，在存图的时候需要录入数据
// A是排序后的数组
int deg[MAXN], A[MAXN];
bool toposort(int n)
{
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        A[cnt++] = t;
        for (auto to : edges[t])
        {
            deg[to]--;
            if (deg[to] == 0) // 出现了新的入度为0的点
                q.push(to);
        }
    }
    return cnt == n;
}
//返回值为是否成功进行拓扑排序，也即是否存在环。也就是说拓扑排序是可以用来简单地判环的。
//有时会要求输出字典序最小的方案，这时把queue改成priority_queue即可.