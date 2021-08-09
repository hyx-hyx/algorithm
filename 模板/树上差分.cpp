//按点差分
int lca=getlca(x,y);//求LCA可参见LCA的模板
mark[x]++,mark[y]++;
mark[lca]--,mark[fa[lca][0]]--;

//按边差分(边权下放：将边权转换为深度较大的节点的点权)
int lca=getlca(x,y);
mark[x]++,mark[y]++,mark[lca]-=2;
