#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct bun
{
	int ai;
	int bi;
	int ci;
	int di;
};

int dp[12][1005];
int main()
{
	int n,m,c0,d0;
	cin>>n>>m>>c0>>d0;
	vector<bun>a;

	bun d;
	d.ai = 100000;
	d.bi = 1;
	d.ci = c0;
	d.di = d0;
	a.push_back(d);
	for(int i=0;i<m;i++)
	{
		int ai,bi,ci,di;
		cin>>ai>>bi>>ci>>di;
		bun temp;
		temp.ai = ai;
		temp.bi = bi;
		temp.ci = ci;
		temp.di = di;
		a.push_back(temp);
	}

	for(int i=1;i<=(int)a.size();i++)
	{
		for(int j=0;j<=n;j++)
		{
			int	k = a[i-1].ai/a[i-1].bi;
			for(int m=0;m<=k;m++)
			{
				if( j - m*a[i-1].ci >= 0 )
					dp[i][j] = max(dp[i][j], dp[i-1][j-m*a[i-1].ci] + a[i-1].di*m);
			}
		}
	}
	cout<<dp[(int)a.size()][n]<<endl;
	return 0;
}
