#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
using namespace std;


int solve(vector<int>&d, int t)
{
	int sum = 0;

	for(int i=0;i<t;i++)
	{
		sum+=d[i];
	}

	return sum;
}

int main()
{
	int n,k;
	cin>>n>>k;

	vector<int>a(n);

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int t = n/k;

	int q;
	cin>>q;
	int minm = 1000000000;
	int maxm = 0;

	int c[n];
	memset(c,0,sizeof(c));

	for(int i=0;i<q;i++)
	{
		int sum = 0;
		for(int j=0;j<t;j++)
		{
			int temp;
			cin>>temp;
			sum+=a[temp-1];
			c[temp-1] = 1;
		}
		minm = min(minm,sum);
		maxm = max(maxm,sum);
	}

	vector<int>d;

	for(int i=0;i<n;i++)
	{
		if(!c[i])
		{
			d.push_back(a[i]);
		}
	}

	sort(d.begin(),d.end());

	int sum = 0;
	
	int left = n - t*k;
	if((int)d.size()-left>=t)
	{
		maxm = max(maxm,solve(d,t));
		minm = min(minm,solve(d,t));

		sort(d.begin(),d.end(),greater<int>());

		maxm = max(maxm,solve(d,t));
		minm = min(minm,solve(d,t));
	}
	cout<<setprecision(10)<<(double)minm/(double)t<<" "<<(double)maxm/(double)t<<endl;

	return 0;
}


