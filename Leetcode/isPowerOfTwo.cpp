#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isPowerOfTwo(int n) 
{
    if(n%2==1&&n!=1)
        return false;
    if(n==2)return true;
    if(n==1)
        return true;
    else
        return isPowerOfTwo(n>>1);               
}
int main()
{
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n)<<endl;
    return 0;
}
