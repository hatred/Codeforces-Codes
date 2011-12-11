#include<iostream>
#include<climits>
#include<vector>
#include<map>
#include<cstring>

using namespace std;


int main()
{
	long long n;
	cin>>n;
	vector<long long>a;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	long long sum = 0;

	for(int i=0;i<(int)a.size();i++)
	{
		if(a[i]!=1)
			sum += ( a[i] + (long long)(i)*(a[i]-1));
		else
			sum += 1;

	}

	cout<<sum<<endl;

return 0;
}