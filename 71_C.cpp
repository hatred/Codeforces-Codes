#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool good(int k,vector<int>&a)
{
	int n = (int)a.size();
	int c = n/k;
	for(int j=1;j<=(int)a.size();j++)
	{
		bool good = true;
		int count = 0;
		int temp = j;
		//cout<<" Separator "<<endl;
		while(count<c)
		{
		//	cout<<temp<<" "<<k<<" "<<n<<" "<<j<<endl;
			if(a[temp] == 0)
			{
				good = false;
				break;
			}
			temp = temp + k;
			if(temp>=n)
			{
				temp = temp%(n-1);
			}
			count++;
		}
		if(good)
		{
			//cout<<k<<" gg  "<<j<<endl;
			return true;
		}
	
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n+1);

	for(int i=1;i<n+1;i++)
	{
		cin>>a[i];
	}

	bool found = false;
	for(int i=1;i<=sqrt(n);i++)
	{
		if(found)
		{
			break;
		}
		if(n%i==0)
		{
			//cout<<"dwdw"<<endl;
			int k = n/i;
			if(k>=3 && good(i,a))
				found = true;
			k = i;
			if(k>=3 && good(n/i,a))
				found = true;
		}
	}
	if(!found)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}

		
