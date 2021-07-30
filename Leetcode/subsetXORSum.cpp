#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int flag[12],sum=0;
void subsetXORSum(int a[],int n) 
{
    int result = 0;
    for (int i = 0; i < n;++n)
        result ^= a[i];
    sum += result;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        if(a[i])
        {
            temp = a[i];
            a[i] = 0;
            subsetXORSum(a, n);
            a[i] = temp;
        }
        else
            continue;
    }
    return;
}
    
int main()
{
    int n,a[100];
    cin>>n;
    for (int i = 0; i < n;++i)
        cin >> a[i];
    subsetXORSum(a,n);
    cout << sum << endl;
    return 0;
}
