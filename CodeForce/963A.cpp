#include<iostream>
#define MAXN 200000
#define ll long long
#define P 1000000009
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

ll power(ll a,int n){
    if(n==0) return 1;
    if(n==1) return a;
    if(n==2) return (a*a)%P;
    if(n%2) return power(power(a,n/2),2)*a%P;
    return power(power(a,n/2),2);
}


int n,a,b,k,s[MAXN];
int x,y;
ll sum;

int main(){

scanf("%d%d%d%d",&n,&a,&b,&k);

for(int i=0;i<k;i++){
    char sym; cin>>sym;
    if(sym=='+') s[i]=1;
    else s[i]=-1;
}

for(int i=0;i<k;i++){//Z
    if(s[i]==1) sum=(sum+power(a,n-i)*power(b,i)%P)%P;
    else sum=(sum-power(a,n-i)*power(b,i)%P+P)%P;
}

exgcd(a,P,x,y);//找a的逆元
int inva=x;
inva+=P; inva%=P;
ll q = power(b,k)*power(inva,k)%P;

if(q==1){
    cout<<sum*((n+1)/k)%P;
}
else{
    x=0; y=0;
    exgcd(q-1,P,x,y); x+=P; x%=P;
    printf("%d",sum*x%P*( power(q,(n+1)/k) -1 )%P );
}

    return 0;
}