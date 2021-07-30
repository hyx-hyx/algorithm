#include <algorithm>
#include <iostream>
using namespace std;
struct activity
{
    int s;
    int f;
};
bool cmp1(activity x,activity y)
{
    if(x.f==y.f)
        return x.s>y.s;   //定义降序排序（从大到小） 
    else
        return x.f < y.f;   //定义升序排序（从小到大） 
}
int main()
{
    activity arr[1001];
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n;++i)
        cin >> arr[i].s >> arr[i].f;
    sort(arr, arr + n, cmp1);
    int finaltime =arr[0].f;
    for (int i = 1; i < n;++i)
    {
        if (arr[i].s < finaltime)
            continue;
        else
        {
            finaltime = arr[i].f;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
