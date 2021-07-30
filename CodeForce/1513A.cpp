#include<iostream>
using namespace std;
int main()
{
    int n,a[100],t,k;
    cin>>t;
    for (int i = 0; i < t;++i)
    {
        cin >> n>>k;
        for (int j = 0; j < n;++j)
            a[j] = j + 1;
        if(((n%2==0)&&(k>=n/2))||((n%2==1)&&(k>n/2)))
            cout << -1 << endl;
        else
        {
            for (int b = 0; b < k; ++b)
            {
                int temp,index=2*(b+1);
                temp=a[index];
                a[index] =a[index-1];
                a[index-1] = temp;
            }
            for (int b = 0; b < n;++b)
            {
                cout << a[b] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
