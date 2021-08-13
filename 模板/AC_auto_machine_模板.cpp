#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
const int N=10000;  //节点数
typedef long long ll;
using namespace std;
struct Trie{//trie树
    int fail;//失配指针
    int vis[30];//子结点的位置编号
    //vis数组实际上就是trie树里的trie[p][ch],指向的是该结点的子结点的编号
    int End;//trie树里用于标记有几个单词是以这个结点结尾的
}AC[N];

int tot=0;//AC自动机里是从根节点0开始，trie树一般是从根节点1开始

inline void build(string s)
{//构造tried树//基本的trie树的操作
    int len = s.length();
    int p = 0;//trie树的当前指针（当前结点）从根节点0开始
    for(int i = 0;i < len;++i)
    {
        if(AC[p].vis[s[i]-'a'] == 0)//tire树的老规矩（不存在这个结点）
            AC[p].vis[s[i]-'a'] = ++tot;//不存在就构造一个新结点
        p = AC[p].vis[s[i]-'a'];//往下走
    }
    AC[p].End++;//标记每一个单词的结尾//因为最后要求的是有多少个单词。要计算重复的
}

void Get_fail()
{//构造失配指针利用bfs 遍历
    queue<int>Q;// 队列存
    for(int i= 0;i < 26;++i)
    {//处理第二层的失配指针（26个字母遍历一遍）
        if(AC[0].vis[i] != 0)
        {//若存在这个点
            AC[AC[0].vis[i]].fail = 0;//第二层都要指向根节点
            Q.push(AC[0].vis[i]);//并将该结点编号压入队列
        }
    }
    while(!Q.empty()){//遍历所有的结点
        int u = Q.front();//每次取出队头
        Q.pop();
        for(int i = 0;i < 26;++i){//枚举所有可能的子结点（26个字母）
            if(AC[u].vis[i]!=0){//若存在这个字母的子结点
                AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];//注意是vis[i],一定是指向与该结点字母相同的结点，若不存在就会是指向0（根节点）
                //让当前结点的子结点的失配指针fail指向 当前结点的失配指针fail所指向的结点的 与当前结点的子结点字母相同的子结点
                Q.push(AC[u].vis[i]);
                //并把该结点压入队列里等待继续往下遍历
            }
            else//若不存在子结点
            AC[u].vis[i] = AC[AC[u].fail].vis[i];
            //因为不存在该结点，本身在trie树里会直接结束，但是会浪费时间
            //所以这里本身没有路可以走了，
            //但是这里让当前结点的子结点直接指向当前结点的失配指针fail指向的结点，
            //把路连上，下次遇上了可以直接走，这样将trie树构造成trie图，更加的优化、
            //其实就是相当于先预处理好，因为每一个点都要尽量连到另一个相同字母的结点，每一次遍历可能尽管这个结点没有这个字母
            //但是先把他连到结点的失配指针指向的那一个结点，说不定就有这个字母
        }
    }
}

int AC_Query(string s){//AC自动机匹配
    int len = s.length();
    int p = 0,ans = 0;
    for(int i = 0;i < len;++i){
        p = AC[p].vis[s[i]-'a'];//往下一层走
        for(int k = p;k&&AC[k].End!=-1;k = AC[k].fail){//往后走，若没有到走过的结点或者到达根节点，就一直往失配指针指向的地方走
                ans += AC[k].End;//加上路径上的值
                AC[k].End = -1;//标记已走过（已经加过一遍了）
        }
    }
    return ans;
}

int n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(AC, 0, sizeof(AC));//memset可以初始化结构体哇
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        build(s);//建trie树（图）
    }
    AC[0].fail = 0;//结束标志（根节点的失配指针是一定指向自己的）
    Get_fail();//求出失配指针
    cin>>s;
    cout<<AC_Query(s)<<endl;
    return 0;
}