#include<iostream>
using namespace std;
int main()
{
    int n, m, sum,temp;
    cin >> n;
    for (int i = 0; i < n;++i)
    {
        cin >> m;
        sum = 0;
        for (int j = 0; j < m;++j)
        {
            cin >> temp;
            sum += temp;
        }
        if(i<=n-2)
            cout << sum << endl << endl;
        else
            cout << sum << endl;
    }
    return 0;
}