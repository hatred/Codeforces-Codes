#include<iostream>
#include<vector>

using namespace std;


int main()
{
	long long n;
	cin>>n;
	vector<long long>a(n);
	long long x,y;
	cin>>x>>y;
	for(int i=0;i<n-1;i++)
	{
		a[i] = 1;
	}
	a[n-1] = y-(n-1);
	if(a[n-1] <= 0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
//	cout<<"dd"<<" "<<a[n-1]<<endl;
	long long sum = x - (n-1);
	//if(sum<0)
//	{
//		cout<<"-1"<<endl;
//		return 0;
//	}

	bool good = false;
	if(a[n-1]>=10000000LL)
	{
	 	good = true;
	}
	else
	{
		if(a[n-1]*a[n-1] >= sum)
			good = true;
	}

	if(good)
	{
		for(int i=0;i<(int)a.size();i++)
		{
			cout<<a[i]<<endl;
		}
	}
	else
	{
		cout<<"-1"<<endl;
	}

	return 0;
}

	