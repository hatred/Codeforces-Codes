#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(n%2==0)
	{
		cout<<"Marsel"<<endl;
	}
	else
	{
		bool found = false;
		for(int i=1;i<=sqrt(m);i++)
		{
			if(m%i==0)
			{
				int k1 = i;
				int k2 = m/i;
				if(k1>=k || k2>=k)
				{
					found = true;
					break;
				}
			}
		}
		if(found)
			cout<<"Timur"<<endl;
		else
			cout<<"Marsel"<<endl;
	}
	return 0;
}