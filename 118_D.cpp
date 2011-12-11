#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


int dp[102][102][2];
const int MOD = 100000000;
int main()
{
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;

	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			for(int m=0;m<2;m++)
			{
				if(m==0)
				{
					for(int k=1;k<=k1;k++)
					{
						if(i-k>=0)
							dp[i][j][0] += dp[i-k][j][1]%MOD;
					}
				}
				else
				{
					for(int k=1;k<=k2;k++)
					{
						if(j-k>=0)
							dp[i][j][1] += dp[i][j-k][0]%MOD;
					}
				}
			}
		}
	}

	cout<<(dp[n1][n2][0]+dp[n1][n2][1])%MOD<<endl;
	return 0;
}
