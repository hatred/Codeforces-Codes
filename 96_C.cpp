#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>

using namespace std;

string toLower(string& t)
{
	string ret;
	for(int i=0;i<t.length();i++){
		ret+=tolower(t[i]);
	}
	return ret;
}

char convert(char ans, bool isUpper, char c)
{
	char cand;
	if(isUpper)
		cand = 'A';
	else
		cand = 'a';
	
	while(tolower(cand) == tolower(c))
	{
		cand++;
	}
	return cand;
}

char process(char ans, char c)
{
		if(tolower(ans) != tolower(c))
		{
			return islower(ans) ? tolower(c) : toupper(c);
		}
		return convert(ans, isupper(ans), c);
}

void mark(vector<bool>&b,int finder ,int l)
{
	for(int i=finder;i<finder+l;i++){
		b[i] = 1;
	}
}

int main()
{
	int n;
	cin>>n;
	vector<string>a(n);
	vector<string>l(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		l[i] = toLower(a[i]);
	}

	string s;
	cin>>s;
	string LC;
	LC = toLower(s);
	char c;
	cin>>c;

	sort(l.begin(),l.end());
	sort(a.begin(),a.end());

	//for(int i=0;i<a.size();i++){
	//	cout<<l[i]<<" "<<a[i]<<endl;
//	}
	int index = 0;
	string ans = s;
	vector<bool>b((int)ans.length());
	for(int i=0;i<l.size();i++){
		int index = 0;
		while(true)
		{
			int finder = LC.find(l[i],index++);
			if(finder == string::npos)
				break;
			mark(b,finder,(int)l[i].length());
		}
	}
	
	for(int i=0;i<(int)b.size();i++){
		if(b[i])
		{
			ans[i] = process(ans[i],c);
		}
	}
	cout<<ans<<endl;
	return 0;
}

