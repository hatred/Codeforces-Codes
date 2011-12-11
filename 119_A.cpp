#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool solve(int a,int b,int n, int turn)
{

	int gcdA = __gcd(a,n);
	int gcdB = __gcd(b,n);
	if(turn == 0 && n<gcdA)
		return 1;
	if(turn == 1 && n<gcdB)
		return 0;
	
	if(turn == 0)
		return solve(a,b,n - (__gcd(a,n)),1-turn);
	else
		return solve(a,b,n - (__gcd(b,n)),1-turn);
}

int main()
{
	int a,b,n;
	cin>>a>>b>>n;

	cout<<solve(a,b,n,0)<<endl;
	return 0;
}