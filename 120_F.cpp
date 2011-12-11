#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

int a[101][101];

vector<int> findLeafNodes(int beads)
{
	vector<int>leaf;

	for(int i=0;i<beads;i++)
	{
		int count = 0;

		for(int j=0;j<beads;j++)
		{
			if(a[i][j])
				count++;
		}

		if(count==1)
			leaf.push_back(i);
	}

	return leaf;
}

int maxPathHelper(int*c, int nodeN, int beads)
{
	int maxm = 0;
	c[nodeN]=1;
	for(int i=0;i<beads;i++)
	{
		if(a[nodeN][i] && !c[i])
		{
			c[i] = 1;
			maxm = max(maxm,1 + maxPathHelper(c,i,beads));
		}
	}

	return maxm;
}

int maxPath(int nodeN, int beads)
{
	int c[beads];
	memset(c,0,sizeof(c));

	int maxL = maxPathHelper(c,nodeN,beads);

	return maxL;
}


int main()
{
	int n;
	ifstream fin("input.txt");
	fin>>n;

	int tot = 0;
	for(int i=0;i<n;i++)
	{
		int beads;
		fin>>beads;
		memset(a,0,sizeof(a));
		for(int j=0;j<beads-1;j++)
		{
			int t1,t2;
			fin>>t1>>t2;
			a[t1-1][t2-1] = 1;
			a[t2-1][t1-1] = 1;
		}

		vector<int> leafNodes = findLeafNodes(beads);
		int maxm = 0;
		for(int j=0;j<(int)leafNodes.size();j++)
		{
			maxm  = max(maxm,maxPath(leafNodes[j],beads));
		}

		tot +=maxm;
	}

	fin.close();

	ofstream fout("output.txt");

	fout<<tot<<endl;
	fout.close();
	return 0;
}