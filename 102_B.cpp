#include<vector>
#include<iostream>
#include<climits>
using namespace std;

struct laptop
{
	int s;
	int r;
	int h;
	int c;
};
int main()
{
	int n;
	cin>>n;
	vector<laptop>a;

	for(int i=0;i<n;i++)
	{
		int s,r,h,c;
		cin>>s>>r>>h>>c;
		laptop l;
		l.s = s;
		l.r = r;
		l.h = h;
		l.c = c;
		a.push_back(l);
	}

	vector<bool>b(n,1);

	for(int i=0;i<n;i++)
	{
		if(b[i])
		{
			bool good = true;
			for(int j=0;j<n;j++)
			{
				if(a[i].s<a[j].s && a[i].r<a[j].r && a[i].h<a[j].h)
				{
					good = false;
					break;
				}
			}
			if(!good)
				b[i] = 0;
		}
	}

	int minm = INT_MAX;
	int index = 0;
	for(int i=0;i<n;i++)
	{
		if(b[i])
		{
			if(a[i].c < minm)
			{
				minm = a[i].c;
				index = i;
			}
		}
	}
	cout<<(index+1)<<endl;
	return 0;	
}