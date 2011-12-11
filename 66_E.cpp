#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>f(n);
	vector<int>d(n);
	for(int i=0;i<n;i++){
		cin>>f[i];
	}

	for(int i=0;i<n;i++){
		cin>>d[i];
	}

	int sum = 0;
	int count = 0;
	int ans = 0;
	int index=0;
	while(index<n)
	{
		if(sum+f[index]-d[index]<0)
		{
			sum = 0;
			ans = ++index;
			continue;
		}
		sum = sum+f[index]-d[index];
		index++;
	}
	cout<<(index+1)<<endl;
	return 0;
}
		
