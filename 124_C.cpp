#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

vector<int>findPrimes()
{
	vector<int>ans;
	for(int i=2;i<=1000;i++)
	{
		int count = 0;
		for(int j=2;j<=sqrt(i);j++)
		{
			if((i%j)==0)
				count++;
		}
		if(count==0)
			ans.push_back(i);
	}

	return ans;
}

int findMax(int* a)
{
	int maxm = 0;
	int index = 0;
	for(int i=0;i<26;i++)
	{
		if(a[i]>0)
		{
			if(a[i]>maxm)
			{
				maxm = a[i];
				index = i;
			}
		}
	}
	return index;
}

int find(int* a)
{
	for(int i=0;i<26;i++)
	{
		if(a[i]>0)
			return i;
	}

	return 0;
}

int main()
{
	string s;
	cin>>s;

	vector<int> p = findPrimes();

	int n = (int)s.length();

	int a[26];

	memset(a,0,sizeof(a));

	for(int i=0;i<(int)s.length();i++)
	{
		a[s[i]-'a']++;
	}

	int plac[n+1];
	bool bad = false;
	memset(plac,0,sizeof(plac));
	for(int i=0;i<(int)p.size();i++)
	{
		if(p[i]>n || bad)
			break;
		bool found = false;
		char c;
		for(int j=1;j<=n/p[i];j++)
		{
	
			if(plac[p[i]*j]!=0)
			{
				c = plac[p[i]*j];
				found = true;
				break;
			}
		}

		int count = 0;

		for(int j=1;j<=n/p[i];j++)
		{
			if(plac[p[i]*j]==0)
				count++;
		}
		//cout<<found<<" "<<count<<endl;
		if(!found)
		{
			int index = findMax(a);
			if(a[index]<count)
			{
				bad = true;
				break;
			}
			else
			{
				a[index]-=count;
			}
			//cout<<index<<endl;
			for(int j=1;j<=n/p[i];j++)
				plac[p[i]*j] = index + 'a';
		}
		else
		{
			int index = c-'a';
			if(a[index]<count)
			{
				bad = true;
				break;
			}
			else
			{
				a[index]-=count;
			}

			for(int j=1;j<=n/p[i];j++)
			{
				if(plac[j*p[i]]==0)
					plac[j*p[i]] = c;
			}
		}
	}

	if(bad)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			if(plac[i]==0)
			{
				int index = find(a);
				cout<<(char)(index+'a');
				a[index]-=1;
				continue;
			}
			cout<<(char)plac[i];
		}
		cout<<endl;
	}
	return 0;
}
		