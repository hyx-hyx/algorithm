#include<iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> prices(100);
    int k;
    int min_front,max_back,max_temp=-1,max_index=0,max_total;
    cin >> k;
    for (int i = 0; i < k;++i)
        cin >> prices[i];
    min_front = prices[0];
    for(int i=1;i<prices.size();++i)
    {
        if(max_back<prices[i])
        {
            max_back=prices[i];
            max_index=i;
        }
    }
    for(int i=1;i<prices.size()-1;++i)
    {
        if(prices[i]<min_front)
            min_front=prices[i];
        if(i>=max_index)
        {
            int max_back=0;
            for(int j=i+1;j<prices.size();++j)
            {
                if(max_back>prices[j])
                    max_back=prices[j];
            }
        }
        if(max_back>min_front)
            max_total=max_back-min_front;
    }
    cout << max_total << endl;
}