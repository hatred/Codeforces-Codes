#include<iostream>
#include<cstring>
using namespace std;


long long C[101][101];

long long calc(int n,int r)
{
	if(C[n][r]!=-1)
		return C[n][r];
	if(r>n)
		return 0;
	if(r==n)
		return 1;
	if(r==0)
		return 1;
	C[n][r] = calc(n-1,r) + calc(n-1,r-1);
	return C[n][r];
}

int main()
{
	memset(C,-1,sizeof(C));
	int m,n,t;
	cin>>m>>n>>t;
	long long tot = calc(m+n,t);

	for(int i=0;i<=3;i++)
	{
		tot-=calc(m,3-i)*calc(n,t-(3-i));
	}

	tot-=calc(m,t);

	cout<<tot<<endl;

	return 0;
}