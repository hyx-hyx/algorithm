#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
#define MAXN 1005
#define MAXM 30 
char ch[MAXN];
int sa[MAXN], a[MAXN], t[MAXN], c[MAXN], n, m = MAXM, p;
int main()
{
	scanf("%s", ch), n = strlen(ch);
	for (int i = 0; i < n; i++) c[a[i] = (ch[i] - 'a' + 1)]++;
	for (int i = 1; i < m; i++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)
		sa[--c[a[i]]] = i;
	for (int k = 1; k <= n; k <<= 1) {
		int p = 0;
		for (int i = n - k; i < n; i++) t[p++] = i;
		for (int i = 0; i < n; i++) if (sa[i] >= k) t[p++] = sa[i] - k;
		for (int i = 0; i < m; i++) c[i] = 0;
		for (int i = 0; i < n; i++) c[a[t[i]]]++;
		for (int i = 0; i < m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--c[a[t[i]]]] = t[i];
		swap(a, t);
		p = 1, a[sa[0]] = 0;
		for (int i = 1; i < n; i++) a[sa[i]] = (t[sa[i - 1]] == t[sa[i]] && t[sa[i - 1] + k] == t[sa[i] + k]) ? p - 1 : p++;
		if (p >= n) break;
		m = p;
	}
	return 0;
}