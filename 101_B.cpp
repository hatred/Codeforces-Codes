#include<iostream>
#include<climits>
#include<vector>
#include<map>
#include<cstring>

using namespace std;


int main()
{
	vector< vector<int> > a(13);
	a[0].push_back(1);
	a[0].push_back(11);
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(4);
	a[4].push_back(5);
	a[5].push_back(6);
	a[6].push_back(7);
	a[7].push_back(8);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(10);
	a[11].push_back(10);
	a[12].push_back(10);

	int n;
	cin>>n;
	int sum = 10;
	vector<int>b(13,4);
	b[11]--;
	int c = 0;
	for(int i=0;i<(int)a.size();i++)
	{
		for(int j=0;j<(int)a[i].size();j++)
		{
				if(sum + a[i][j] == n)
					c += b[i];
		}
	}
	cout<<c<<endl;

return 0;
}