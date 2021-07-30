#include <iostream>
using namespace std;
int main()
{
    int t,n,one=0,two;
    cin >> t;
    for (int i = 0; i < t;++i)
    {
        cin >> n;
        one = 0;
        for (int j = 0; j < n;++j)
        {
            int temp;
            cin >> temp;
            if (temp == 1||temp==3)
                one++;
        }
        cout << one << endl;
    }
    return 0;
}