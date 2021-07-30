#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> sources[10], dst[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> sources[i];
    
    for (int i = 0; i < n; ++i)
        cout << dst[i] << " ";
    return 0;
}