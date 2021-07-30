#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
{
    B.push_back(A.at(0));
    A.assign(A.begin() + 1, A.end());
    hanota(A,B,C);
    
    

}
int main()
{
    vector<int> A(10);
    vector<int> B(10);
    vector<int> C(10);
    hanota(A,B,C);
    return 0;
}
