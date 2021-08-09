#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 1000
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        if (( a + 1 ) % 6 || ( a - 1 ) % 6)
            cout << "no" << endl;
        else
        {
            if (!( a % 3200 ))
            {
                cout << "no" << endl;
                continue;
            }
            if (!(a % 172800))
            {
                cout << "yes" << endl;
                continue;
            }
            if (a % 100)
            {
                if (a % 400)
                    cout << "no" << endl;
                else
                    cout << "yes" << endl;
                continue;
            }
            else
            {
                if (a % 4)
                    cout << "no" << endl;
                else
                    cout << "yess" << endl;
                continue;
            }
        }
    }
	return 0;
}
