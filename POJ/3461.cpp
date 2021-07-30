#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> nextval(1000005);
void getNext(string s, vector<int>& nextval)
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
int KMP(string text, string p)
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
            j == nextval[j];
        }
    }
    return ans;
}
int main()
{
    string text, p;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p >> text;
        getNext(p, nextval);
        cout<<KMP(text, p)<<endl;
    }
    return 0;
}