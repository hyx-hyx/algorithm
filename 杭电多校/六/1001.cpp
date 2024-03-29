#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#define maxn 20000010
using namespace std;
int prime[maxn];
int visit[maxn];
void Prime() {
    memset(visit, 0,sizeof(visit));
    memset(prime, 0,sizeof(prime));
    visit[0] = 1;
    visit[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        if (!visit[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
int main()
{
	int t;
    Prime();
	scanf("%d", &t);
	while (t--)
	{
		int x;
		scanf("%d", &x);
        int minindex = maxn;
		if (x <= 0)
		{
            int i;
            for (i = 1 - x; visit[i]; ++i);
            minindex = min(minindex, 2 * i);
            for (i = 2 - x; visit[2 * i - 1]; ++i);
            minindex = min(minindex, 2*i-1);
            printf("%d\n", minindex);
		}
        else
        {
            int i = 0;
            if (!visit[x])
                printf("1\n");
            else
            {
                if (!visit[2 * x + 1] || !visit[2 * x - 1])
                    printf("2\n");
                else
                {
                    for (i = x; visit[i]; ++i);
                    minindex = min(minindex, 2*i);
                    for (i = x; visit[2 * i - 1]; ++i);
                    minindex = min(minindex, 2 * i - 1);
                    printf("%d\n", minindex);
                }
            }
        }
	}
	return 0;
}
