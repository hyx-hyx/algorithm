#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str="123";
    while(next_permutation(str.begin(),str.end()))
        cout<<str<<endl;
    return 0;
}