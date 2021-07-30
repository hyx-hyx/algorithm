#include <iostream>
#include <vector>
#include <string>
#define inf 1000000
using namespace std;
int main()
{
    int dptable[10001] = {1000000}, n, amount;
    vector<int> coins(1000);
    cin >> n;
    cin >> amount;
    dptable[0] = 0;
    for (int i = 0; i < n;++i)
        cin >> coins[i];
    for (int i = 1; i <=amount; ++i)
    {
        for(int j=0;j<coins.size();++j)
        {
            if(i-coins[j]>=0)
                dptable[i]=min(dptable[i],dptable[i-coins[j]]+1);
        }
    }
    if(dptable[amount]>=inf)
        cout<<"-1"<<endl;
    else
        cout << dptable[amount] << endl;
    return 0;
}