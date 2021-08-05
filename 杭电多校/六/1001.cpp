#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 10000005
#define mem memset
using namespace std;
int prime[maxn] = {0};
int visit[maxn] = {0};
void Prime() {
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
	scanf("%d", &t);
    Prime();
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
            printf("3\n");
        else
        {
            if (n > 0)
            {
                if (!visit[n]&&n!=1)
                {
                    printf("1\n");
                    continue;
                }
                else
                { 
                    int flag = 1;
                    if (!visit[2 * n + 1] || !visit[2 * n - 1])
                    {
                        printf("2\n");
                        continue;
                    }
                    else
                    {
                        int i;
                        for (i = n; visit[i]; ++i);
                        printf("%d\n", 2 * i);
                    }
                }
            }
            else
            {
                if (!visit[-n + 1])
                    printf("%d\n", 2* (-n+1));
                else
                {
                    if (visit[-2 * n + 3])
                        printf("%d\n", (-2) * n + 3);
                    else
                    {
                        int i;
                        for (i = -n + 2; visit[i]; ++i);
                        printf("%d\n", 2 * i);
                            
                    }
                }
            }
        }
    }
	return 0;
}
