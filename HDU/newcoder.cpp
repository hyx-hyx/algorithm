#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
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
bool edge[8005][8005];
typedef std::pair<int, int> Pair;
std::vector<Pair> black;
std::vector<Pair> white;
bool cmp(Pair p1, Pair p2)
{
    if (p2.second == p1.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}
int main() {
    int n, seed;
    std::cin >> n >> seed;
    srand(seed);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edge[j][i] = edge[i][j] = read();
            if (edge[i][j] == true)
                black.push_back(std::make_pair(i, j));
            else
                white.push_back(std::make_pair(i, j));
        }
    }
    sort(black.begin(), black.end());
    sort(white.begin(), white.end());
    int b = black.size();
    int w = white.size();
    for (int i = 0; i < b-1; ++i)
    {
        if (black[i].first == black[i + 1].first && edge[black[i].second][black[i + 1].second] == true)
        {
            cnt++;
            continue;
        }
        if (black[i].second == black[i + 1].second && edge[black[i].first][black[i + 1].first] == true)
        {
            cnt++;
            continue;
        }
    }
    for (int i = 0; i < w - 1; ++i)
    {
        if (white[i].first == white[i + 1].first && edge[white[i].second][white[i + 1].second] == false)
        {
            cnt++;
            continue;
        }
        if (white[i].second == white[i + 1].second && edge[white[i].first][white[i + 1].first] == false)
        {
            cnt++;
            continue;
        }
	}
    sort(black.begin(), black.end(),cmp);
    sort(white.begin(), white.end(),cmp);
    for (int i = 0; i < b - 1; ++i)
    {
        if (black[i].second == black[i + 1].second && edge[black[i].first][black[i + 1].first] == true)
        {
            cnt++;
            continue;
        }
        if (black[i].first == black[i + 1].first && edge[black[i].second][black[i + 1].second] == true)
        {
            cnt++;
            continue;
        }
    }
    for (int i = 0; i < w - 1; ++i)
    {
        if (white[i].first == white[i + 1].first && edge[white[i].second][white[i + 1].second] == false)
        {
            cnt++;
            continue;
        }
        if (white[i].second == white[i + 1].second && edge[white[i].first][white[i + 1].first] == false)
        {
            cnt++;
            continue;
        }
    }
    printf("%d\n", cnt);
    return 0;
}