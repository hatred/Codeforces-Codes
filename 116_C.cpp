#include<iostream>
#include<climits>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int a[n+1];

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	int maxm = 0;
	
	for(int i=1;i<=n;i++)
	{
		int t = a[i];
		int c = 1;
		while(t!=-1)
		{
			t = a[t];
			c++;
		}
		maxm = max(maxm,c);
	}

	cout<<maxm<<endl;
	return 0;
}