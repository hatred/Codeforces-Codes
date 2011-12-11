#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int a[1001][1001];
int n;

struct output
{
	int tank;
	int tap;
	int val;
};

int dfs(int s,int d, int minm)
{
	if(s==d)
		return minm;
	
	for(int i=0;i<n;i++)
	{
		if(a[s][i]>0)
			return dfs(i,d,min(minm,a[s][i]));
	}

	return 0;
}

int main()
{
	int m;
	cin>>n>>m;

	
	for(int i=0;i<m;i++)
	{
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		a[t1-1][t2-1] = t3;
	}

	vector<int>tank;
	vector<int>tap;

	for(int i=0;i<n;i++)
	{
		int incoming = 0;
		int outgoing = 0;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>0)
				outgoing++;
			if(a[j][i]>0)
				incoming++;
		}

		if(outgoing>0 && incoming == 0)
			tank.push_back(i);
		if(incoming>0 && outgoing == 0)
			tap.push_back(i);
	}
	
	vector<output>t;
	for(int i=0;i<(int)tank.size();i++)
	{
		for(int j=0;j<(int)tap.size();j++)
		{
			int retVal = dfs(tank[i],tap[j],INT_MAX);
			if(retVal>0)
			{
				output temp;
				temp.tank = tank[i];
				temp.tap =  tap[j];
				temp.val = retVal;
				t.push_back(temp);
			}
		}
	}

	cout<<(int)t.size()<<endl;

	for(int i=0;i<(int)t.size();i++)
	{
		cout<<(t[i].tank+1)<<" "<<(t[i].tap+1)<<" "<<t[i].val<<endl;
	}

	return 0;
}

				

			