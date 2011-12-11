#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>ans;

	for(int i=0;i<n;i++)
	{
		int si,fi,ti;
		cin>>si>>fi>>ti;
		if(si==fi)
		{
			ans.push_back(ti);
			continue;
		}

		if(si<fi)
		{
			int k = (ti-si+1)/(2*m-2);
			if(((ti-si+1)%(2*m-2)) != 0)
				k++;
			if((si-1) >= ti)
				k = 0;
			//cout<<"Dwdwwd "<<(ti-i+1)%(2*m-2)<<endl;
			//cout<<"dd "<<k<<" "<<(i-1) + k*(2*m-2)<<" "<<(2*m-2)<<endl;
			ans.push_back((si-1) + k*(2*m-2) + fi - si);
		}
		else
		{
			int k = (ti+si-1)/(2*m-2);
			if(((ti+si-1)%(2*m-2))!=0)
				k++;
			//cout<<"sd "<<k<<endl;
			ans.push_back((m-si) + (2*k-1)*(m-1) + abs(fi-si));
		}
	}

	for(int i=0;i<(int)ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}