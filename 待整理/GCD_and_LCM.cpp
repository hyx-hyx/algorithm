#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int gcd(int a,int b)
{
    if(!(a%b))
        return b;
    else
        gcd(b, a % b);
}
int main()
{
    long long a, b;
    while(cin>>a>>b)
    {
        long long temp = gcd(a, b);
        cout << temp << " " <<((long long)((a * b))/temp) << endl;
    }
    return 0;
}
