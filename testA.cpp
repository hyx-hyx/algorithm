#include<iostream>
#include<map>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
int main(){
    int m;
    cin >> m;
    int num[m];
    set<int, less<int>> idxAsc;
    set<int, greater<int>> idxDec;
    multiset<int> st;
    long long preNum[m + 2];
    memset(preNum, 0, sizeof(preNum));
    for(int i = 1; i <= m; i++){
        int a;
        cin >> a;
        preNum[i] += a;
    }
    for(int i =0; i <= m + 1; i++) cout << preNum[i] << " ";
    cout << endl;
    idxAsc.insert(0); idxAsc.insert(m+1);
    idxDec.insert(m + 1); idxDec.insert(0);
    preNum[m+1] = preNum[m];
    for(int i = 0 ; i < m; i++){
        int deleteIdx =  0;
        cin >> deleteIdx;
        auto right = idxAsc.upper_bound(deleteIdx);
        auto left  = idxDec.upper_bound(deleteIdx);
        long long last =  preNum[*right] - preNum[*left];
        auto lastIdx =  st.find(last);
        st.erase(lastIdx);
        st.insert(preNum[deleteIdx-1] - preNum[*left]);
        st.insert(preNum[*(right) - 1] - preNum[deleteIdx]);
        cout << *st.begin() << " ";
    }   
}