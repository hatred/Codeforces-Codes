#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
#include<climits>
using namespace std;

map<string,int>p;
map<int,string>rev;
int  minm = INT_MAX;
int like = 0;
int a1,b1,c1;
vector< vector<int> >rel(7, vector<int>(7));

int findDiff(vector< vector<int> > team);
void solve(int a, int b, int c)
{
	vector<int>t1(7,1);
	for(int i=0;i<a;i++){
		t1[i]=0;
	}
	vector< vector<int> > team(3);
	do{
		vector<int>taken(7);
		for(int i=0;i<7;i++){
			if(t1[i]==0)
				taken[i] = 1;
		}
		
		vector<int>rem;
		for(int i=0;i<taken.size();i++){
			if(taken[i]==0)
				rem.push_back(i);
		}

		vector<int>rem1((int)rem.size(),1);
		for(int i=0;i<b;i++){
			rem1[i] = 0;
		}
		do{
				vector< vector<int> > team(3);
				for(int i=0;i<t1.size();i++){
				            if(t1[i]==0)
							   team[0].push_back(i);
				}
				for(int i=0;i<rem1.size();i++){
					if(rem1[i]==0)
					{
						team[1].push_back(rem[i]);
					}
					else
					{
						team[2].push_back(rem[i]);
					}
				}
				//cout<<"amand"<<endl;
				findDiff(team);
			}while(next_permutation(rem1.begin(),rem1.end()));
		}while(next_permutation(t1.begin(),t1.end()));
}
					
int findLike(vector< vector<int> > team)
{
//	for(int i=0;i<team.size();i++){
//		for(int j=0;j<team[i].size();j++){
//			cout<<team[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	int count = 0;
	for(int i=0;i<team.size();i++){
		for(int j=0;j<team[i].size();j++){
			for(int k=j+1;k<team[i].size();k++){
				if(rel[team[i][j]][team[i][k]]==1)
				{
					count++;
				}
				if(rel[team[i][k]][team[i][j]]==1)
				{
					count++;
				}
			}
		}
	}
	return count;
}

int findDiff(vector< vector<int> > team)
{
	//cout<<"start"<<endl;
	vector<int>t(3);
	vector<int>exp(3);
	
	for(int i=0;i<t.size();i++){
		t[i]=i;
	}
	exp[0] = a1;
	exp[1] = b1;
	exp[2] = c1;

	do{
		int team1 = exp[t[0]];
		int team2 = exp[t[1]];
		int team3 = exp[t[2]];

		team1/=(int)team[0].size();
		team2/=(int)team[1].size();
		team3/=(int)team[2].size();
		//cout<<team1<<" "<<team2<<" "<<team3<<" "<<team[0].size()<<endl;
		int maxE = 0;
		maxE = max(team1,maxE);
		maxE = max(team2,maxE);
		maxE = max(team3,maxE);
		int minE = INT_MAX;
		minE = min(team1,minE);
		minE = min(team2,minE);
		minE = min(team3,minE);
		//cout<<maxE<<" "<<minE<<endl;
		if(maxE-minE < minm)
		{
			//cout<<maxE-minE<<endl;
			minm = min(minm,maxE-minE);
			like = findLike(team);
		}
		else if(maxE-minE == minm)
		{
			int thisLike = findLike(team);
			if(thisLike>like)
			{
				like = thisLike;
			}
		}
	}while(next_permutation(t.begin(),t.end()));
	//cout<<"end"<<endl;
}

int main()
{
	int n;
	vector<string>a;
	cin>>n;
	string s;
	getline(cin,s);
	for(int i=0;i<n;i++){
		getline(cin,s);
		a.push_back(s);
	}

	cin>>a1>>b1>>c1;
	p["Anka"] = 0;
	p["Chapay"]= 1;
	p["Cleo"]=2;
	p["Troll"]=3;
	p["Dracul"]=4;
	p["Snowy"]=5;
	p["Hexadecimal"]=6;

	rev[0] = "Anka";
	rev[1] = "Chapay";
	rev[2] = "Cleo";
	rev[3] = "Troll";
	rev[4] = "Dracul";
	rev[5] = "Snowy";
	rev[6] = "Hexadecimal";

	for(int i=0;i<a.size();i++){
		stringstream s1;
		s1<<a[i];
		string t1,t2,t3;
		s1>>t1>>t2>>t3;
		rel[p[t1]][p[t3]]=1;
	}
	for(int i=1;i<7;i++){
		for(int j=1;j<7;j++){
			for(int k=1;k<7;k++){
				if(i+j+k!=7)
					continue;
				solve(i,j,k);
				}
			}
		}

	cout<<minm<<" "<<like<<endl;
	return 0;
}

