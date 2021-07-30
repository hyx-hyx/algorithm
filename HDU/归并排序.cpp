#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int sources[10], dst[10];
void mergesort(int a[], int low, int up, int dst[])
{
    int mid = (up + low) / 2;
    int lindex = 0, rindex =0, dstindex = 0;
    int dst1[10], dst2[10];
    if (low == up)
    {
        dst[0] = a[low];
        return ;
    }
    mergesort(a, low, mid, dst1);
    mergesort(a, mid+ 1, up, dst2);
    while (lindex <= mid-low&& rindex <= up-mid-1)
        dst1[lindex] < dst2[rindex]? dst[dstindex++] = dst1[lindex++] : dst[dstindex++] = dst2[rindex++];
    while (lindex <= mid -low)
        dst[dstindex++] =dst1[lindex++];
    while (rindex <= up-mid-1)
        dst[dstindex++] = dst2 [rindex++];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> sources[i];
    mergesort(sources, 0, n - 1, dst);
    for (int i = 0; i < n; ++i)
        cout << dst[i] << " ";
    return 0;
}