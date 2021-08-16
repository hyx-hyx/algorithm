#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 105
typedef long long ll;
int M,N;            //M, N分别表示左、右侧集合的元素数量
int Map[maxn][maxn]; //邻接矩阵存图
int p[maxn];         //记录当前右侧元素所对应的左侧元素
bool vis[maxn];      //记录右侧元素是否已被访问过
typedef pair<int,int> P;
vector<P>ans;
int match(int i)
{
    for(int j = 1; j<=N; ++j)
        if(Map[i][j]&&!vis[j]) //有边且未访问
        {
            vis[j] = true;                 //记录状态为访问过
            if(p[j]==0||match(p[j])) //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
            {
                p[j] = i;    //当前左侧元素成为当前右侧元素的新匹配
                return j; //返回匹配成功
            }
        }
    return 0; //循环结束，仍未找到匹配，返回匹配失败
}
int Hungarian()
{
    int cnt = 0;
    for(int i = 1; i<=M; ++i)
    {
        memset(vis,0,sizeof(vis)); //重置vis数组
        int temp = match(i);
        if(temp)
        {
            ans.push_back(P(i,temp));
            cnt++;
        }
    }
    return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>M>>N;
	vector<int> a,b;
	while(1)
	{
		int x,y;
		cin>>x>>y;
		if(x==-1&&y==-1)
			break;
        Map[x][y] = 1;
	}
    int cnt = Hungarian();
    cout<<cnt<<endl;
    for(int i = 0; i<cnt; ++i)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}
