#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool find(int n1,int t1,int t2)
{
	if(n1>=t1 && n1<=t2)
		return true;
	int k = t1/n1;
	while(true)
	{
		int m = n1*k;
		if(m>t2)
			return false;
		if(m>=t1 && m<=t2)
			return true;
		k++;
	}

	return false;
}

int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		int xi,yi;
		cin>>xi>>yi;
		int sqrT = sqrt(xi);
		int count = 0;
		for(int i=1;i<=sqrT;i++)
		{
			if(xi%i!=0)
				continue;
			int n1 = i;
			int n2 = xi/i;
			int t1 = xi-yi;
			int t2 = xi-1;
			if(true)
			{
				bool found = find(n1,t1,t2);
				cout<<n1<<" "<<t1<<" "<<t2<<" "<<found<<" "<<t1/n1<<endl;
				if(!found)
					count++;
			}

			if(n1!=n2)
			{
				bool found = find(n2,t1,t2);
				cout<<n2<<" "<<t1<<" "<<t2<<" "<<found<<" "<<t2/n2<<endl;
				if(!found)
					//cout<<n2<<" "<<t1<<" "<<t2<<" "<<found<<" "<<t2/n2<<endl;
					count++;
			}
		}

		cout<<count<<endl;
	}

	return 0;
}