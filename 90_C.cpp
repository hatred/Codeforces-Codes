#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main()
{
	long long n,m,k;
	cin>>n>>m>>k;

	vector<long long>a(n);
	for(int i=0;i<(int)a.size();i++)
	{
		cin>>a[i];
	}

	bool good = true;

	if(n%2==0)
		good = false;
	
	long long allowed = (n/2) + 1;
	if(m<allowed)
		good = false;
	
	long long minm = INT_MAX;

	for(int i=0;i<n;i+=2)
	{
		minm = min(a[i],minm);
	}

	if((int)a.size()==1)
	{
		minm = m*k;
		minm = min(a[0],minm);
		cout<<minm<<endl;
	}
	else
	{
		long long obj = (n+1)/2;
		long long ans = k*(m/obj);
		if(good)
			cout<<min(minm,ans)<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;
}