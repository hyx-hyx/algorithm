#include <iostream>
using namespace std;
int main()
{
    int n,sum=0,a[10000],aim=0,cnt,preindex,nextindex;
    cin>>n;
    for (int i = 0; i < n;++i)
    {
        cin >>a[i];
        sum += a[i];
    }
    aim = sum / n;
    for (int i = 0;i<n;++i)
    {
        if(i==0)
        {
            preindex = n - 1;
            nextindex = i + 1;
        }
        if(i==n-1)
        {
            preindex = n - 2;
            nextindex = 0;
        }
        else
        {
            preindex = i - 1;
            nextindex = i + 1;
        }
        cnt += abs(a[i] - aim);
        a[i] = aim;
        if(a[preindex]>a[nextindex])
            a[preindex] = a[preindex] - cnt;
        else
            a[nextindex] = a[nextindex] - cnt;
    }
    cout << cnt << endl;
    return 0;
}