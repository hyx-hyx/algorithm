#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> nextval(1000);
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
    int i = 0, j = 0;
    while (i <text.size())
    {
        if (j == -1 || text[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
        /*如果求成功匹配的次数
        if (j == p.size())
        {
            ans++;
            j = nextval[j];
        }
    }
    return ans;*/
        if (j == p.size())
            return i - p.size();
        
    }
    return -1;
}
int main()
{
    
    cin >> text >> p;
    getNext(p, nextval);
    cout<<KMP(text, p)<<endl;
    return 0;
}