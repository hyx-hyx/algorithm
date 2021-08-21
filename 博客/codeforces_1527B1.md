## 题意
给出一个只含01的字符串，alice（以下简称a）和bob（以下简称b）有以下两种操作，alice先开始。

1.选一个0将其变换为1，花费一刀。

2.如果该字符串当前不是回文串，将其翻转，0花费，与此同时对手下一阶段不得翻转。

当字符串全部为1时游戏结束。花费更少者获胜，相同时平局。
## 分析
因为输入保证给出的字符串必定是回文。
* 当字符串长度为偶数时，如1001，则先手必定会破坏回文，而后手只需在对称位置将0变为1，即可恢复回文。当只剩下一个0时，后手选择反转，先手只能将最后一个0变为1，后手必胜。
* 当字符串长度为奇数时
  * 若只有1个数，则先手必败。
  * 若字符串长度大于1，但只有一个0，即使0在最中间也是先手必败。容易遗漏这种情况！！！！
  * 若字符串长度大于一，且0的个数大于1，如10001.则需看最中间的数是0还是1。
    * 若为0，则先手将中间的0变为1，仍然是回文，后手便会破坏回文。先手只需采取跟随策略，到最后反转便可胜。
    * 若为1，则先手只能破坏回文，后手只需采取跟随策略，到最后反转便可胜。
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<assert.h>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		if((n % 2) && (n > 1))
		{
			if(s[n / 2] == '0')
			{
				int cnt = 0;
				for(int i = 0; i < n; ++i)
					if(s[i] == '0')
						cnt++;
				if(cnt > 1)
					cout << "ALICE" << endl;
				else
					cout << "BOB" << endl;
			}
			else
				cout << "BOB" << endl;
		}
		else
			cout << "BOB" << endl;
	}
	return 0;
}

```