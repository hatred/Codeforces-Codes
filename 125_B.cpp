#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
string mapper(char c)
{
	map<char,string>p;

	p['>'] = "1000";
	p['<'] = "1001";
	p['+'] = "1010";
	p['-'] = "1011";
	p['.'] = "1100";
	p[','] = "1101";
	p['['] = "1110";
	p[']'] = "1111";

	return p[c];
}

int power(long long a,long long b,long long mod)
{
	if(b==0)
		return 1;
	
	long long pow = power(a,b/2,mod);
	if(b%2==0)
	{
		return (pow*pow)%mod;
	}
	else
	{
		return (2*pow*pow)%mod;
	}
}

int main()
{
	string s;
	getline(cin,s);

	string bin;

	for(int i=0;i<(int)s.length();i++)
	{
		bin = bin + mapper(s[i]);
	}
	long long sum = 0;
	int index = 0;
	for(int i=(int)bin.length()-1;i>=0;i--)
	{
		if(bin[i]=='0')
		{
			index++;
			continue;
		}
		sum+=power(2,index,1000003);
		index++;
	}
	sum = sum % 1000003;
	cout<<sum<<endl;

	return 0;
}