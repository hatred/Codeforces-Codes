#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n,m;
int a[102][102];
int mark[102];
bool good = true;
void bfs(int root,int*c);
pair<int, vector<int> > findCycle(int n1,int n2)
{
	int c[n];
	memset(c,0,sizeof(c));
	int p[n];
	memset(p,-1,sizeof(p));
	queue<int>q;
	int b[102][102];
	memcpy(b,a,sizeof(a));
	q.push(n2);
	bool made = false;
	int tNode = 0;
	int pNode = 0;
	vector<int>ans;
	while(!q.empty())
	{
		if(made)
			break;
		int u = (int)q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(b[u][i] && !c[i])
			{
				c[i] = 1;
				b[i][u] = 0;
				q.push(i);
				p[i] = u;
			}
			else if(b[u][i] && c[i])
			{
				made = true;
				tNode = i;
				pNode = u;
				break;
			}
		}
		c[u] = 1;
	}
	
	if(made)
		return make_pair(true,ans);
	
	ans.push_back(n1);
	while(p[n1] != -1)
	{
		int t = p[n1];
		ans.push_back(t);
		n1 = t;
	}
	return make_pair(made,ans);
}

void bfs(int root,int*c)
{
	int b[102][102];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][j] = a[i][j];
		}
	}
	queue<int>q;
	q.push(root);
	while(!q.empty())
	{
		int u = (int)q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(b[u][i] && !c[i])
			{
				q.push(i);
				c[i] = 1;
				b[i][u] = 0;
			}
			else if(b[u][i] && c[i])
			{
				good = false;
			}
		}
		c[u] = 1;
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		a[t1-1][t2-1] = 1;
		a[t2-1][t1-1] = 1;
	}

	if(!findCycle(0,1).first)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	bool found = false;
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(found)
				break;
			if(a[i][j])
			{
				a[i][j] = 0;
				a[j][i] = 0;
				vector<int>b;
				pair< bool, vector<int> >p = findCycle(i,j);
				if(!p.first && p.second.size()>=3)
				{
					ans = p.second;
					found = true;
					break;
				}
				a[i][j] = 1;
				a[j][i] = 1;
			}
		}
	}
	if(!found)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<ans.size();i++)
	{	
		for(int j=i+1;j<ans.size();j++)
		{
			a[ans[i]][ans[j]] = 0;
			a[ans[j]][ans[i]] = 0;
		}
	}
	int c[n];
	memset(c,0,sizeof(c));
	for(int i=0;i<(int)ans.size();i++)
	{
		bfs(ans[i],c);
	}

	for(int i=0;i<n;i++)
	{
		if(!c[i])
			good = false;
	}
	if(good)
		cout<<"FHTAGN!"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}