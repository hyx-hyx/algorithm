#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int base = 29, mod = 1e9 + 7;
int f(string text)
{
	int sum = 0;
	for (int i = 0; i < text.size(); ++i)
	{
		sum += text[i] *(int)pow((double)base,i)%mod;
	}
	return sum;
}
int main()
{
	string text,p;
	vector<int> hash(1000004);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> p >> text;
		int temp = f(p);
		int cnt = 0;
		if(text.size()<p.size())
			cout << 0 << endl;
		hash[0] = f(text.substr(0, p.size()));
		if (hash[0] == temp)
			cnt++;
		for (int i = 1; i < text.size() - p.size() + 1; ++i)
		{
			hash[i] = ((hash[i-1]-text[i-1])/base+text[i+p.size()-1]*(int)pow((double)base,(int)p.size()-1))%mod;
			if(hash[i]==temp)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}