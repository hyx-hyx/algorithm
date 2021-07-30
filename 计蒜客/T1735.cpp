#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
void print(int step);
int flag[10] = { 1,1,1,1,1,1,1,1,1,1 };
int dfs[10];
int indexi = 0;
int n;
int main()
{
    cin >> n;
    print(n);
    return 0;
}
void print(int step)
{
    if (step == 0)
    {
        for (int i = 1; i <= n; ++i)
            printf("%5d", dfs[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (flag[i])
        {
            dfs[++indexi] = i;
            flag[i] = 0;
            print(step - 1);
            indexi--;
            flag[i] = 1;
        }
    }
}