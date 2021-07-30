#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t, n, m;
    vector<int> digital(0, 0);
    cin >>t;
    for (int i = 0; i < t;++i)
    {
        int size = 0;
        digital.resize(0);
        cin >> n >> m;
        while(n)
        {
            digital.resize(size+1);
            digital[size] = n % 10;
            size++;
            n /= 10;
        }
        for (int j = 0; j < m;++j)
        {
            int temp = size;
            for (int k = 0; k < temp;++k)
            {
                digital[k]++;
                if(digital[k]==10)
                {
                    digital[k]=0;
                    digital.resize(size+1);
                    digital[size] = 1;
                    size++;
                }
            }
        }
        cout << size << endl;
    }
    return 0;
}