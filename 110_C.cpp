#include<iostream>
#include<climits>
#include<utility>
using namespace std;


int main()
{
	int n;
	cin>>n;

	pair<int,int>p = make_pair(INT_MAX,INT_MAX);
	int minm = INT_MAX;
	for(int i=0;i<=(n/7);i++)
	{
		int t =  n - 7*i;
		if(t%4==0)
		{
			if((t+i <= minm))
			{
				if(t+i < minm)
				{
					p = make_pair(t/4,i);
					minm = t+i;
				}
				else
				{
					if(make_pair(t,i)<p)
					{
						p = make_pair(t/4,i);
					}
				}
			}
		}
	}

	if(minm == INT_MAX)
		cout<<"-1"<<endl;
	else
	{
		for(int i=0;i<p.first;i++)
		{
			cout<<"4";
		}
		for(int i=0;i<p.second;i++)
		{
			cout<<"7";
		}
		cout<<endl;
	}

	return 0;
}
