#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
		sum += t;
	}

	if(sum%n != 0)
	{
		cout<<"Unrecoverable configuration."<<endl;
	}
	else
	{
		int m = sum/n;

		int minm=INT_MAX,maxm=0;
		int minIndex = 0,maxIndex=0;
		
		int ret = 0;
		for(int i=0;i<(int)a.size();i++)
		{
			if(a[i]!=m)
			{
				ret++;
				if(a[i]<minm)
				{
					minm = min(minm,a[i]);
					minIndex = i;
				}
				if(a[i]>maxm)
				{
					maxm = a[i];
					maxIndex = i;
				}
			}
		}
		if(ret==0)
			cout<<"Exemplary pages."<<endl;
		else
		{
			if(ret==1 || ret>2)
				cout<<"Unrecoverable configuration."<<endl;
			else
				cout<<m-minm<<" ml. from cup #"<<(minIndex+1)<<" to cup #"<<(maxIndex+1)<<"."<<endl;
		}
	}
		return 0;
}
				

