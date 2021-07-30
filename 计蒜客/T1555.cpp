#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a(100000);
vector<int> ask(100000);
int findbinary(int min, int max, int n);
int main()
{
    int n,m,x;
    int askindex = 0;
    int answerindex = 0;
    cin>>n>>m;
    for (int i = 0;i<n;++i)
        cin >> a[i];
    sort(a.begin(), a.begin()+n);
    for(int i=0;i<m;++i)
    {
        cin >> x;
        cout<<findbinary(0,n-1,x)<<endl;
    }
   return 0;
}
int findbinary(int min,int max,int n)
{
    int middle=(max+min)/2;
    if(min==max)
        if(a[min]<=n)
            return a[min];
        else
            if(min==0)
                return -1;
            else
                return a[min-1];
    if(a[middle]==n)
        return a[middle];
    if(n>a[middle])
        findbinary(middle+1, max,n);
    else
        findbinary(min, middle,n);
}