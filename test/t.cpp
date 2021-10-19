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
int xx[4] = {1,0,-1,0};
int yy[4] = {0,-1,0, 1};
int target,len;
vector<vector<bool>> visited(2,vector<bool>(1000, false));
void dfs(int curX, int curY, int curStep){
    if(curStep == target){
        ans++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nextX = xx[i] + curX;
        int nextY = yy[i] + curY;
        if(nextX >= 0 and nextX < len and nextY >= 0 and nextY < 2 and !visted[nextX][nextY] ){
            visited[nextX][nextY] = true;
            dfs(nextX, nextY, curStep + 1);
            visited[nextX][nextY] = false;
        }
    }
}
int main()
{
    cin >> target;
    dfs(0,0, 0);
    
    visited[0][0] = true;
    
	return 0;
}
