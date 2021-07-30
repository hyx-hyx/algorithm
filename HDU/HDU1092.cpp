#include<iostream>
using namespace std;
int main()
{
    int n=1,temp,sum;
    while(cin>>n&&n!=0)
    {
        sum = 0;
        for (int i = 0; i < n;++i)
        {
            cin >> temp;
            sum += temp;
        }
        cout << sum<<endl;
    }
    return 0;
}