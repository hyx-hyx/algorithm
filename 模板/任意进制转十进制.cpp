int Atoi(string s,int radix)    //s是给定的radix进制字符串
{
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		char t=s[i];
		if(t>='0'&&t<='9') ans=ans*radix+t-'0';
		else ans=ans*radix+t-'a'+10;
	}
		return ans;
}