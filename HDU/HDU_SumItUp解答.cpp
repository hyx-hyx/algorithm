#include<iostream>
#include<cstring>
using namespace std;
int N,n;
int ar[15];
int br[15];

bool judge=false;

void DFS(int num,int pos,int sum)
{
    if(sum==N)
    {
        judge=true;   //存在一个以上解 
        for(int i=1;i<num;i++){  //按格式输出 
            if(i==1) cout<<br[i];
            else cout<<"+"<<br[i];
        }
        cout<<endl;return;
    }
    if(sum>N) return ; //若大于，如后一个数特别大之类情况 
    if(pos>n) return ;

    br[num]=ar[pos]; 
    DFS(num+1,pos+1,sum+br[num]);
    while(pos+1<=n&&ar[pos]==ar[pos+1]) pos++;//重要 
    DFS(num,pos+1,sum);

}

int main(){
    while(cin>>N>>n&&N&&n)
    {
        for(int i=1;i<=n;i++) cin>>ar[i];
        judge=false;
        cout<<"Sums of "<<N<<":"<<endl;
        DFS(1,1,0);
        if(!judge)  cout<<"NONE"<<endl;
    }
    return 0;
} 