#include<iostream>
#include<fstream>

using namespace std;


int main()
{
	int t;
	ifstream fin("input.txt");
	fin>>t;
	ofstream fout("output.txt");
	while(t>0)
	{
		int n;
		fin>>n;
		
		if(n%2==0)
			fout<<"1"<<endl;
		else
			fout<<"0"<<endl;
		t--;
	}
	fin.close();
	fout.close();

	return 0;
}