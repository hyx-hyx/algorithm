//POJ 1655
//链式前向星存图
//MAXN为节点数量
// 这份代码默认节点编号从 1 开始，即 i ∈ [1,n]
int sizet[MAXN],  // 这个节点的“大小”（所有子树上节点数 + 该节点）
weight[MAXN],  // 这个节点的“重量”
centroid[2];   // 用于记录树的重心（存的是节点编号）
void GetCentroid(int cur,int fa)
{  // cur 表示当前节点 (current)
    sizet[cur] = 1;
    weight[cur] = 0;
    for(int i = head[cur]; i != 0; i = edges[i].next)
    {
        if(edges[i].to != fa)
        {  // e[i].to 表示这条有向边所通向的节点。
            GetCentroid(edges[i].to,cur);
            sizet[cur] += sizet[edges[i].to];
            weight[cur] = max(weight[cur],sizet[edges[i].to]);
        }
    }
    weight[cur] = max(weight[cur],n - sizet[cur]);
    if(weight[cur] <= n / 2)
    {  // 依照树的重心的定义统计
        centroid[centroid[0] != 0] = cur;
    }
}