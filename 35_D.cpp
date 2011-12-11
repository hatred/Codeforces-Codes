#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

int dp[101][10002];

int main(){

	int n,X;
	cin>>n>>X;

	int a[n];

	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a[i] = (n-i)*t;
	}

	for(int i=0;i<n;i++){
		dp[i][0]=0;
	}

	for(int i=0;i<10002;i++){
		dp[0][i] = 0;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<=X;j++){
			if(j<a[i])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+1);
			}
		}
	}
	
	for(int i=0;i<n;i++){
	        for(int j=0;j<=X;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	int count = 0;
	int r = n-1;
	int c = X;
	while(r>0 && c>=0)
	{
		if(dp[r][c] != dp[r-1][c])
		{
			count++;
			c = c - a[r];
		}
		r = r-1;
	}
	cout<<count<<endl;
}




	