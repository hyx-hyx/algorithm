#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int count1 = 0, count0 = 0, count1max = 0,count0max;
    char temp=s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        if(s[i]=='1')
        {
            if(s[i]==temp)
                count1++;
            else
            {
                count0max =max(count0max, count0);
                count1 = 0;
            }
        }
        if (s[i] == '0')
        {
            if (s[i] == temp)
                count0++;
            else
            {
                count1max = max(count1max, count1);
                count0 = 0;
            }
        }
        temp = s[i];
    }
    return 0;
}