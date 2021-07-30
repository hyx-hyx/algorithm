#include <iostream>
using namespace std;

int findmax(int temparr[],int n)
{
    int max=-10000000,temp;
    if(n==1)
        return temparr[n - 1];
    temp = findmax(temparr, n - 1);
    if(temp+temparr[n-1]>temp)
        return (temp + temparr[n - 1]);
    else
        return temp;
}

int main()
{
    int a[100],count;
    cin >> count;
    for (int i = 0; i < count;++i)
        cin >> a[i];
    cout<<findmax(a, count);
}

