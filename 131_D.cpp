#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int n;
vector< vector<int> >a(3001,vector<int>(3001));;

bool checkCycle()
{
	queue<int>q;
	q.push(0);
	int c[n];
	memset(c,0,sizeof(c));
	while(!q.empty())
	{
		int u = (int)q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(a[u][i] && !c[i])
			{
				q.push(i);
				c[i] = 1;
			}
		}
		c[u] = 1;
	}

	for(int i=0;i<n;i++)
	{
		if(!c[i])
			return false;
	}

	return true;
}

vector<int>getPath(int s,int t)
{
	queue<int>q;
	q.push(s);
	int p[n];
	int c[n];
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
	p[s] = -1;
	while(!q.empty())
	{
		int u = (int)q.front();
		q.pop();
		if(u==t)
			break;

		for(int i=0;i<n;i++)
		{
			if(a[u][i] && !c[i])
			{
				c[i] = 1;
				q.push(i);
				p[i] = u;
			}
		}
		c[u] = 1;
	}

	vector<int>path;
	path.push_back(t);
	int temp = t;
	while(p[temp]!=-1)
	{
		temp = p[temp];
		path.push_back(temp);
	}

	return path;
}
int getDist(int index,vector<int>path)
{
	queue<int>q;
	q.push(index);
	int d[n];
	int c[n];
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	while(!q.empty())
	{
		int u = (int)q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(a[u][i] && !c[i])
			{
				c[i] = 1;
				d[i] = d[u] + 1;
				q.push(i);
			}
		}
	}
	int minm = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(binary_search(path.begin(),path.end(),i))
		{
			minm = min(minm,d[i]);
		}
	}
	return minm;
}


int main()
{

	cin>>n;
	vector< pair<int,int> >edges;
	for(int i=0;i<n;i++)
	{
		int c,d;
		cin>>c>>d;
		a[c-1][d-1] = 1;
		a[d-1][c-1] = 1;
		edges.push_back(make_pair(c-1,d-1));
	}

	vector<int> path;

	for(int i=0;i<(int)edges.size();i++)
	{
		pair<int,int> temp = edges[i];
		a[temp.first][temp.second] = 0;
		a[temp.second][temp.first] = 0;

		if(checkCycle())
		{
			path = getPath(temp.first,temp.second);
			break;
		}
		a[temp.first][temp.second] = 1;
		a[temp.second][temp.first] = 1;
	}

//	for(int i=0;i<(int)path.size();i++)
//	{
//		cout<<path[i]<<" ";
//	}
//	cout<<endl;
	
	// if path is emty push the entire node array in !
	if((int)path.size()==0)
	{
		for(int i=0;i<n;i++)
		{
			path.push_back(i);
		}
	}
	sort(path.begin(),path.end());
	vector<int>d;
	for(int i=0;i<n;i++)
	{
		if(binary_search(path.begin(),path.end(),i))
			d.push_back(0);
		else
		{
			d.push_back(getDist(i,path));
		}
	}
	
	
	for(int i=0;i<(int)d.size()-1;i++)
	{
		cout<<d[i]<<" ";
	}
	cout<<d[(int)d.size()-1]<<endl;

	return 0;
}
	
	