#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long>a;

void solve(long long n)
{
	if(n>5000000000LL)
		return;
//	cout<<n<<endl;	
	a.push_back(n);

	solve(n*10+4);
	solve(n*10+7);
}

int main()
{
	int l,r;
	cin>>l>>r;
	solve(4);
	solve(7);
	sort(a.begin(),a.end());

	long long ans = 0;
	int prev = l;
	for(int i=0;i<(int)a.size();i++)
	{
		if(a[i]<l)
		{
			continue;
		}
		if(a[i]>=r)
		{
			ans+=(r-prev+1)*a[i];
			break;
		}

		ans += (a[i]-prev+1)*a[i];
		prev = a[i]+1;
	}
	cout<<ans<<endl;
	return 0;
}

