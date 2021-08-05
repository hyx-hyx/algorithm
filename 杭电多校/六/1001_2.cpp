#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define maxn 1005
#define mem memset
typedef long long ll;
using namespace std;
int prime[maxn];
int visit[maxn];
void Prime() {
	mem(visit, 0,sizeof(visit));
	mem(prime, 0,sizeof(prime));
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
	scanf("%d", &t);
	Prime();
	while (t--)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			printf("3\n");
			continue;
		}
		else
		{
			if (x > 0)
			{
				int flag = 0;
				if (!visit[x])
					printf("1\n");
				else
				{
					for (int i = 1; i <= maxn; ++i)
					{
						int left = i * x - (i * (i - 1) / 2);
						int right = i * x + (i * (i - 1) / 2);
						for (int j = left; j <= right; ++j)
						{
							if (!visit[j])
							{
								flag = 1;
								printf("%d\n", i);
								break;
							}
						}
						if (flag)
							break;
					}
					if (!flag)
						printf("-1\n");
				}
			}
			else
			{

			}
		}
	}
	return 0;
}
