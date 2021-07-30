#include <iostream>
#include <string>
using namespace std;
int main()
{
    string one, two;
    //int plusone[200],plustwo[200];
    int result[201] = {0};
    cin >> one >> two;
    int onelen = one.size();
    int twolen = two.size();
    int flag = 0;
    for (int i = 0; i < max(onelen, twolen); ++i)
    {
        int onetemp = 0;
        if (one.size())
        {
            onetemp = one.at(one.size() - 1) - 48;
            one.pop_back();
        }
        int twotemp = 0;
        if (two.size())
        {
            twotemp = two.at(two.size() - 1) - 48;
            two.pop_back();
        }
        result[i] = (onetemp + twotemp + flag) % 10;
        flag = (onetemp + twotemp + flag) / 10;
    }
    int begin;
    if (flag)
    {
        result[max(onelen, twolen)] = flag;
        begin = max(onelen, twolen);
    }
    else
        begin = max(onelen, twolen) - 1;
    int out = 0;
    for (int i = begin; i >= 0; --i)
    {
        if (result[i] || out)
        {
            cout << result[i];
            out = 1;
        }
    }
    if (!out)
        cout << "0";
    return 0;
}