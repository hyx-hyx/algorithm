#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define maxn 200005
using namespace std;
vector<int> nextval(maxn);
void getNext(vector<int>& s, vector<int>& nextval)
{
    nextval[0] = -1;
    int i = 0, j = -1;
    while (i < s.size())
    {
        if (j == -1 || s[i] == s[j])
            nextval[++i] = ++j;
        else
            j = nextval[j];
    }
}
int KMP(vector<int>& text, vector<int>& p)
{
    int i = 0, j = 0, ans = 0;
    while (i < text.size())
    {
        if (j == -1 || text[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
        if (j == p.size())
        {
            ans++;
            j = nextval[j];
        }
    }
    return ans;
}
int main()
{
    int n, w, first;
    vector<int> narr;
    vector<int> warr;
    scanf("%d%d", &n, &w);
    if (n == 1 && w == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n==1&&w!=1)
    {
        cout << 0 << endl;
        return 0;
    }
    scanf("%d", &first);
    for (int i = 0; i < n - 1; ++i)
    {
        int temp;
        scanf("%d", &temp);
        narr.push_back(temp - first);
        first = temp;
    }
    scanf("%d", &first);
    if (w == 1)
    {
        printf("%d", n);
        return 0;
    }
    else
    {
        for (int i = 0; i < w - 1; ++i)
        {
            int temp;
            scanf("%d", &temp);
            warr.push_back(temp - first);
            first = temp;
        }
    }
    getNext(warr, nextval);
    printf("%d\n", KMP(narr, warr));
    return 0;
}
