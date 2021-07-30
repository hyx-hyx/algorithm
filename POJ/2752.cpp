#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> nextval(400004);
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
            return i - p.size();
    }
    return -1;
}
int main()
{
    string S;
    while (cin >> S)
    {
        getNext(S, nextval);
        int i = S.size();
        int cnt = 0;
        vector<int>temp(400004, 0);
        temp[0]=S.size();
        while (nextval[i] != 0)
        {
            temp[++cnt]=nextval[i];
            i = nextval[i];
        }
        for (int i = cnt; i > 0; --i)
            cout << temp[i] << " ";
        cout << temp[0] << endl;
    }
    return 0;
}