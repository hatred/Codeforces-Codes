#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

string toString(char c,int count)
{
	string ret;
	for(int i=0;i<count;i++)
	{
		ret+=c;
	}
	return ret;
}

int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;

	int n = (int)s.length();
	if(k>=n)
	{
		cout<<"0"<<endl;
		string t;
		cout<<endl;
		return 0;
	}
	vector<int>a(26);
	for(int i=0;i<(int)s.length();i++)
	{
		a[s[i]-'a']++;
	}

	bool found = false;
	while(!found && k>0)
	{
		int minm = INT_MAX;
		int index = 0;
		for(int i=0;i<26;i++)
		{
			if(a[i]>0 && k>=a[i])
			{
				if(a[i]<minm)
				{
					minm = a[i];
					index = i;
				}
			}
		}
		if(minm==INT_MAX)
		{
			found = true;
			continue;
		}
		int t = a[index];
		a[index] = 0;
		k-=t;
		string m;
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i] == (char)(index+'a'))
				continue;
			m+=s[i];
		}
		s = m;
	}

	int count = 0;
	for(int i=0;i<(int)s.length();i++)
	{
		if(a[s[i]-'a']>0)
		{
			count++;
			a[s[i]-'a'] = 0;
		}
	}
	cout<<count<<endl;
	cout<<s<<endl;
	return 0;
}