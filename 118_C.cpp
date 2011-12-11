#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int countS(string& s, int t, int k)
{
	int count = 0;
	for(int i=0;i<(int)s.length();i++)
	{
		if((t+'0') == s[i])
			count++;
	}

	return (k-count);
}

pair<int,string> solve(string&s, int t, int k)
{
	vector< vector<int> >p(10);
	vector< vector<int> >n(10);
	int req = countS(s,t,k);
//	cout<<req<<" "<<t<<endl;
	if(req<=0)
	{
		return make_pair(0,s);
	}

	for(int i=0;i<(int)s.length();i++)
	{
		int diff = s[i]-'0' - t;
		if(diff==0)
			continue;
		if(diff>=0)
			p[diff].push_back(i);
		else
			n[abs(diff)].push_back(i);
	}
	
	string m = s;
	int cost = 0;
	for(int i=0;i<10;i++)
	{
		if(req<=0)
			break;
		if((int)p[i].size()>0)
		{
			for(int j=0;j<p[i].size();j++)
			{
				if(req<=0)
					break;
				m[p[i][j]] = t+'0';
				cost+=i;
				req--;
			}
		}
		if((int)n[i].size()>0)
		{
			for(int j=(int)n[i].size()-1;j>=0;j--)
			{
				if(req<=0)
					break;
				m[n[i][j]] = t + '0';
				cost+=i;
				req--;
			}
		}
	}
	return make_pair(cost,m);
}



int main()
{
	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	int minm = INT_MAX;
	string ret;
	for(int i=0;i<10;i++)
	{
		pair<int,string> a = solve(s,i,k);
		if(a.first<minm)
		{
			ret = a.second;
			minm = a.first;
		}
		else if(a.first == minm)
		{
			if(a.second<ret)
			{
				ret = a.second;
			}
		}
	}
	cout<<minm<<endl<<ret<<endl;
	return 0;
}
