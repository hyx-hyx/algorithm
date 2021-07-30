#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int flag = 1;
int main()
{
    int n;
    vector<int> arr(10);
    int tempindex;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = i;
        printf("%5d", i);
    }
    printf("\n");
    while (flag)
    {
        flag = 0;
        for (int i=n;i>1;--i)
        {
            if (arr[i - 1] < arr[i])
            {
                flag = 1;
                tempindex = i - 1;
                for (int j=n;j>0;--j)
                {
                    if (arr[j] > arr[tempindex])
                    {
                        int temp;
                        temp = arr[j];
                        arr[j] = arr[tempindex];
                        arr[tempindex] = temp;
                        sort(arr.begin() +i, arr.begin() + n+1);
                        break;
                    }  
                }
                for (int i=1;i<=n;++i)
                    printf("%5d", arr[i]);
                printf("\n");
                break;
            }
        }
    }
    return 0;
}