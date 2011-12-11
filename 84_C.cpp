#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct circle
{
	int r;
	int c;
	int in;
	int hit;
};

circle make_circle(int c,int r,int in,int hit)
{
	circle t;
	t.c = c;
	t.r = r;
	t.in=in;
	t.hit=-1;
	return t;
}

bool comp (circle i,circle j) { return (i.c<j.c); }
bool comp2 (circle i,circle j) { return (i.in<j.in);}
int compute(vector<circle>& a,int x,int y)
{
	// find an appropriate circle by doing a binary search
	int low = 0, high = (int)a.size();
	while(true)
	{
		int mid = (low + high)/2;
//		cout<<mid<<" "<<low<<" "<<high<<endl;
		if(low>=high)
		{
			return -1;
		}
		//cout<<x<<" "<<a[mid].c+a[mid].r<<endl;
		if(x<=a[mid].c+a[mid].r && x>=a[mid].c-a[mid].r)
		{
			return mid;
		}
		
		if(x>a[mid].c+a[mid].r)
		{
			low = mid+1;
		}
		else
		{
			high = mid;
		}
	}
	return -1;
}

bool inside(circle& c, int x1,int y1)
{
	if((c.c-x1)*(c.c-x1) + y1*y1 - c.r*c.r <= 0)
		return true;

	return false;
}

int main()
{
	int n;
	cin>>n;
	vector<circle>a(n);
	for(int i=0;i<n;i++){
		int c,r1;
		cin>>c>>r1;
		circle c1 = make_circle(c,r1,i,-1);
		a[i] = c1;
	}

	sort(a.begin(),a.end(),comp);

	vector<int>fhit(n,-1);
	int t;
	cin>>t;
	int count = 0;
	for(int i=0;i<t;i++){
		int x1,y1;
		cin>>x1>>y1;
		int hit = compute(a,x1,y1);
		//cout<<hit<<endl;
		if( hit!=-1 && inside(a[hit],x1,y1))
		{
			if(fhit[hit]==-1)
			{
				count++;
				fhit[hit] = i+1;
			}
		}
		if(hit!=-1 && hit-1>=0 && inside(a[hit-1],x1,y1))
		{
			if(fhit[hit-1]==-1)
			{
				count++;
				fhit[hit-1]= i+1;
			}
		}
		if(hit!=-1 && hit+1<(int)a.size() && inside(a[hit+1],x1,y1))
		{
			if(fhit[hit+1] ==-1)
			{
				count++;
				fhit[hit+1] = i+1;
			}
		}
	}
	cout<<count<<endl;
	for(int i=0;i<a.size();i++){
		a[i].hit = fhit[i];
	}
	sort(a.begin(),a.end(),comp2);
	for(int i=0;i<a.size();i++){
		if(i==(int)a.size()-1)
		{
			cout<<a[i].hit<<endl;
			break;
		}
		cout<<a[i].hit<<" ";
	}
	return 0;
}