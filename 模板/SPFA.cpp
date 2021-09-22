void SPFA(int s)
{
    vector<int> inqueue(pointcount, 0);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    inqueue[s] = 1;
    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        inqueue[p] = 0;
        for (int e = head[p]; e != 0;e=edges[e].next)
        {
            int to = edges[e].to;
            if (dist[to] > dist[p]+edges[e].w)
            {
                dist[to] = dist[p] + edges[e].w;
                if(!inqueue[to])
                {
                    Q.push(to);
                    inqueue[to] = 1;
                }
            }
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m;++i)
    {
        int to, w, from;
        cin >> from >> to >> w;
        add(from, to, w);
    }
    dij(s);
    for (int i = 1; i <=n;++i)
    {
        if(dist[i]==inf)
        {
            cout << (int)(pow(2,31) - 1) << " ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    return 0;
}