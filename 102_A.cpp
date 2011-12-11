#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isGreat(char c1,char c2)
{
	if(isalpha(c1) && isalpha(c2))
	{
		map<char,char>p;
		p['T'] = 10;
		p['J'] =11;
		p['Q'] = 12;
		p['K'] = 13;
		p['A'] = 14;

		return (p[c1] > p[c2]);
	}
	
	return c1>c2;
}
int main()
{
	char c;
	cin>>c;
	string s1,s2;
	cin>>s1>>s2;
	if(s1[1] != c)
	{
		if(s1[1]==s2[1] && isGreat(s1[0],s2[0]))
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	else if(s1[1] == c)
	{
		if(s1[1] == s2[1] && isGreat(s1[0],s2[0]))
		{
			cout<<"YES"<<endl;
			return 0;
		}
		if(s1[1] != s2[1])
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
		cout<<"NO"<<endl;
	
	return 0;
	
}