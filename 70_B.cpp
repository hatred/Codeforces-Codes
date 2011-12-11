#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<climits>

using namespace std;

bool found = false;
string s = "ROYGBIV";
string ans;
int n;
bool check(string s1)
{
	int a[26]={0};
	for(int i=0;i<s1.length();i++){
		a[s1[i]-65]=1;
	}
	for(int i=0;i<s.length();i++){
		if(a[s[i]-65]==0)
		{
	//		cout<<s1<<" "<<(char)(s[i])<<endl;
			return false;
		}
	}
//	cout<<s1<<" ffef "<<endl;
	for(int i=0;i<s1.length();i++){
		int p[26]={0};
		p[(s1[i])-65]++;
		p[(s1[(i+1)%n])-65]++;
		p[(s1[(i+2)%n])-65]++;
		p[(s1[(i+3)%n])-65]++;
		for(int j=0;j<26;j++){
			if(p[j]>1)
			{
	//			cout<<s1<<" eee "<<(char)(j+65)<<endl;
				return false;
			}
		}
	}
	//ncout<<s1<<" ddd "<<s1<<endl;
	return true;
}
void solve(char c1,char c2,char c3,string t)
{
//	cout<<t<<endl;
	if((int)t.length()>n || found)
		return;

	if((int)t.length()==n)
	{
		if(check(t) && !found)
		{
			ans = t;
			found = true;
			//cout<<ans<<endl;
			return;
		}
	}

	for(int i=0;i<s.length();i++){
		if(s[i]!=c1 && s[i]!=c2 && s[i]!=c3)
		{
			solve(c2,c3,s[i],t+s[i]);
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<s.length();i++){
		for(int j=i+1;j<s.length();j++){
			for(int k=j+1;k<s.length();k++){
					if(found)
						break;
					string t;
					t+=s[i];
					t+=s[j];
					t+=s[k];
					solve(s[i],s[j],s[k],t);
				}
			}
		}

	cout<<ans<<endl;
	return 0;
}