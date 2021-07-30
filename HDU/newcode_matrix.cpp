#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
namespace GenHelper
{
    unsigned z1, z2, z3, z4, b, u;
    unsigned get()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
    bool read() {
        while (!u) u = get();
        bool res = u & 1;
        u >>= 1; return res;
    }
    void srand(int x)
    {
        z1 = x;
        z2 = (~x) ^ 0x233333333U;
        z3 = x ^ 0x1234598766U;
        z4 = (~x) + 51;
        u = 0;
    }
}
using namespace GenHelper;
typedef std::pair<int, int> Pair;
int ans[8005][8005];
int edgereverse[8005][8005];
int edge[8005][8005];
int temp[8005][8005];
int main() {
    int seed;
    std::cin >> n >> seed;
    srand(seed);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (read())
            {
                edge[j][i] = 1;
                edge[i][j] = 1;
                edgereverse[i][j] = 0;
                edgereverse[j][i] = 0;
            }
            else
            {
                edge[j][i] = 0;
                edge[i][j] = 0;
                edgereverse[i][j] = 1;
                edgereverse[j][i] = 1;
            }
        }
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k <n; k++)
                ans[i][j] += edge[i][k] * edge[k][j];
        }
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            for (int k = 0; k <n; k++)
                temp[i][j] += edge[i][k] *ans[k][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cnt += temp[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k < n; k++)
                ans[i][j] += edge[i][k] * edge[k][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                temp[i][j] += edge[i][k] * ans[k][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cnt += temp[i][i];
    }
    printf("%d\n", cnt / 6);
    return 0;
}


