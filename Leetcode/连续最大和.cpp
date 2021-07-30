#include <iostream>
using namespace std;
int main()
{
    int temp,a[100],count=0,temparr[100],max=-10000,n;
    cin >> count;
    
    for (int i = 0; i < count;++i)
        cin >> a[i];
    for (int i = 0; i < count-1; ++i)
    {
        temparr[i] = a[i];
        for (int j = i+1; j < count; ++j)
        {
            temparr[j] = temparr[j-1] + a[j];
            if (max < temparr[j])
                max = temparr[j];
        }
    }
    cout << max << endl;
    return 0;
}