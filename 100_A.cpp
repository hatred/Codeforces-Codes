#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][n];
	memset(a,0,sizeof(a));
	int c[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		a[t1-1][t2-1] = 1;
		a[t2-1][t1-1] = 1;
	}

	int minm = INT_MAX;
	bool found = false;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[i][j] && a[j][k] && a[k][i])
				{
					minm = min(minm,c[i] + c[j] + c[k]);
					found = true;
				}
			}
		}
	}
	if(!found)
		cout<<"-1"<<endl;
	else
		cout<<minm<<endl;
	return 0;
}

