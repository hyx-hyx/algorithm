#include <iostream>
using namespace std;
int main()
{
    int n,sum,temp;
    while(cin>>n)
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