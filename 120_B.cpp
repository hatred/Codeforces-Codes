#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	ifstream fin("input.txt");
	int n;
	fin>>n;
	int k;
	fin>>k;

	int a[n];

	for(int i=0;i<n;i++)
	{
		fin>>a[i];
	}

	int ans = 0;
	for(int i=k-1;;i++)
	{
		int t = i%n;
		if(a[t]==1)
		{
			ans = t+1;
			break;
		}
	}

	fin.close();
	ofstream fout("output.txt");
	fout<<ans<<endl;
	fout.close();

	return 0;
}