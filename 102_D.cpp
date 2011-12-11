#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;

int dp[1002][1002];
int dp2[1002][1002];

pair<int,int> findPoint(char** a,int n,int m,char c)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==c)
				return make_pair(i,j);
		}
	}
	return make_pair(0,0);
}
bool checkRow(char** a, int intl, int final, int col)
{
	if(dp[intl][final]!=-1)
		return dp[intl][final];
		
	for(int i=intl;i<=final;i++)
	{
		if(a[i][col]=='#')
		{
			//cout<<i<<" "<<col<<" row "<<endl;
			return dp[intl][i] = true;
		}
		dp[intl][i] = 0;
	}
	return dp[intl][final]=0;
}
bool checkCol(char**a, int intl,int final,int row)
{
	if(dp2[intl][final]!=-1)
		return dp2[intl][final];

	for(int i=intl;i<=final;i++)
	{
		if(a[row][i]=='#')
		{
//			cout<<i<<" "<<row<<" "<<" col "<<endl;
			return dp2[intl][i]=true;
		}
		dp2[intl][i] = false;
	}
	return dp2[intl][final]=false;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	int n,m;
	cin>>n>>m;
	char** a;
	a = (char**)malloc(sizeof(char*)*n);

	for(int i=0;i<n;i++)
	{
		a[i] = (char*)malloc(sizeof(char)*m);
	}

	int p[26] = {0};

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(isalpha(a[i][j]))
				p[a[i][j] - 'A'] = 1;
		}
	}

	int k;
	cin>>k;

	vector<int>steps(k);
	vector<char>d(k);

	for(int i=0;i<k;i++)
	{
		cin>>d[i];
		cin>>steps[i];
	}

	string ans;
	for(int i=0;i<26;i++)
	{
		if(p[i])
		{
			pair<int,int>point = findPoint(a,n,m,i+'A');
			//cout<<point.first<<" "<<point.second<<endl;
			bool good = true;
			for(int j=0;j<k;j++)
			{
				switch ( d[j] )
				{
					case 'N':
								if(point.first-steps[j] < 0 || a[point.first-steps[j]][point.second] == '#' || checkRow(a,point.first-steps[j],point.first,point.second))
								{
									good = false;
								}
								if(good)
									point.first = point.first-steps[j];
								break;
					case 'S':
								if(point.first+steps[j] >=n || a[point.first+steps[j]][point.second] == '#' || checkRow(a,point.first,point.first+steps[j],point.second))
								{
									good = false;
								}
								if(good)
									point.first = point.first+steps[j];
								break;
					case 'E':
								if(point.second+steps[j] >=m || a[point.first][point.second+steps[j]] == '#' || checkCol(a,point.second,point.second+steps[j],point.first))
								{
									good = false;
								}
								if(good)
									point.second = point.second+steps[j];
								break;
					case 'W':
								if(point.second-steps[j] < 0 || a[point.first][point.second-steps[j]] == '#' || checkCol(a,point.second-steps[j],point.second,point.first))
								{
									good = false;
								}
								if(good)
									point.second = point.second-steps[j];
								break;
					default:
							 	good = good;
					}
				if(!good)
				{
					//cout<<j<<" "<<point.first<<" "<<point.second<<endl;
					break;
				}
			}
			if(good)
			{
				ans += (i+'A');
			}
		}
	}
	if(ans!="")
		cout<<ans<<endl;
	else
		cout<<"no solution"<<endl;
	
	return 0;
}