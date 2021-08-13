#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int cnt = 0;
typedef pair<int, int> loc;
typedef struct ACNODE 
{
	int child[26] = {0};
	int fail;
	vector<int> exist;
}acnode;
acnode ac_auto[100];
queue<loc> Q;
int vis[26][26] = { 0 };
void insert(const string s)
{
	int cur = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (!ac_auto[cur].child[c - 'a'])
			ac_auto[cur].child[c - 'a'] = ++cnt;
		if (!vis[cur][c - 'a'])
		{
			Q.push(make_pair(cur, c - 'a'));
			vis[cur][c - 'a']=1;
		}
		cur = ac_auto[cur].child[c - 'a'];
	}
	ac_auto[cur].exist.push_back(s.size());
}
void create_fail()
{	
	while (!Q.empty())
	{
		int fanum = Q.front().first;
		acnode fa =ac_auto[fanum];
		int childnode = Q.front().second;
		Q.pop();
		if (!fanum)
			ac_auto[fa.child[childnode]].fail = 0;
		else
		{
			if (ac_auto[fa.fail].child[childnode])
			{
				vector<int> *fail_exist = &(ac_auto[ac_auto[fa.fail].child[childnode]].exist);
				vector<int> *child_exist=&(ac_auto[fa.child[childnode]].exist);
				ac_auto[fa.child[childnode]].fail = ac_auto[fa.fail].child[childnode];
				(*child_exist).insert((*child_exist).end(),(*fail_exist).begin(), (*fail_exist).end());
			}
			else
			{
				ac_auto[fa.child[childnode]].fail = fa.fail;
			}
		}
	}
}
void search(const string s)
{
	int cur = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		int child = ac_auto[cur].child[c - 'a'];
		if (child)
		{
			cur = child;
			int count = ac_auto[cur].exist.size();
			while (count)
			{
				int str_len = ac_auto[cur].exist[count - 1];
				cout << s.substr(i -str_len+1,str_len )<<" ";
				count--;
			}
		}
		else
			cur = ac_auto[ac_auto[cur].fail].child[c-'a'];
	}
}
int main()
{
	string s;
	for (int i = 0; i < 4; ++i)
	{
		cin >> s;
		insert(s);
	}
	create_fail();
	cin >> s;
	search(s);
	return 0;
}