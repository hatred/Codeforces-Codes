#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct DIV{
	DIV(int s,int t)
	{
		speed = s;
		time = t;
	}
	int speed;
	int time;
};

int n;
int s;
vector< vector<DIV> >a(101);
int overTake(int c1,int c2)
{
	int d1 = 0;
	int d2 = 0;

	//d1 = (a[c1][0].speed)*(a[c1][0].time);
	//d2 = (a[c2][0].speed)*(a[c2][0].time);
	
	int index1 = 0;
	int index2 = 0;
	int totTime = 0;
	int count = 0;
	while(index1<a[c1].size() && index2<a[c2].size())
	{
		int intLen = min((a[c1][index1]).time,(a[c2][index2].time))-totTime ;
		if(d1!=d2)
		{
			int v1 = a[c1][index1].speed;
			int v2 = a[c2][index2].speed;
			if(v1!=v2)
			{
				if(v1>v2)
				{
					if(d1<d2)
					{
						double t = (double)(d2-d1)/(double)(v1-v2);
						if(t<=intLen && (totTime+t) != s)
							count++;
					}
				}
				else
				{
					if(d1>d2)
					{
						double t = (double)(d1-d2)/(double)(v2-v1);
						if(t<=intLen && (totTime+t) != s)
							count++;
					}
				}
			}
		}
		totTime+=intLen;
		d1+=((a[c1][index1].speed)*intLen);
		d2+=((a[c2][index2].speed)*intLen);
		//cout<<d1<<" "<<d2<<" "<<totTime<<" "<<intLen<<endl;
		if(totTime>=a[c1][index1].time+intLen )
			index1++;
		if(totTime>=a[c2][index2].time+intLen)
			index2++;
	}

	//cout<<c1<<" "<<c2<<" "<<count<<endl;
	return count;
}

int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			int speed,time;
			cin>>speed>>time;
			DIV D(speed,time);
			a[i].push_back(D);
		}
	}
	
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=0;j<a[i].size();j++){
			sum+=a[i][j].time;
			a[i][j].time = sum;
		}
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++){
			count += overTake(i,j);
		}
	}
	cout<<count<<endl;
	return 0;
}
