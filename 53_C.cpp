#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int>a;

	int jump = n-1;
	int present = 1;
	a.push_back(present);
	for(int i=0;i<n-1;i++)
	{
		int newP;
		if(i%2==0)
		{
			newP = present + jump;
			a.push_back(newP);
		}
		else
		{
			newP = present - jump;
			a.push_back(newP);
		}
		jump--;
		present = newP;
	}

	for(int i=0;i<(int)a.size()-1;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[(int)a.size()-1]<<endl;

	return 0;
}
			

		