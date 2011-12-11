#include<iostream>
#include<cstring>
using namespace std;

int findOneChar(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(!a[i])
			return i;
	}

	return 0;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	memset(a,0,sizeof(a));

	string s;
	cin>>s;

	if((int)s.length()==1)
	{
		if(s[0]=='?')
			s[0] = 'a';
	}
	int countQ = 0;
	for(int i=0;i<(int)s.length()/2;i++)
	{
		if(s[i]=='?' && s[(int)s.length()-1-i]=='?')
		{
			countQ++;
			continue;
		}
		if(s[i]!='?' && s[(int)s.length()-i-1]=='?')
		{
			s[(int)s.length()-i-1]=s[i];
		}
		else if(s[i]=='?' && s[(int)s.length()-i-1]!='?')
		{
			s[i] = s[(int)s.length()-i-1];
		}
	}

	if(((int)s.length()%2)!=0 && s[(int)s.length()/2]=='?')
		countQ++;
	
	for(int i=0;i<(int)s.length();i++)
	{
		if(isalpha(s[i]))
		{
			if(((s[i]-'a')<=(n-1)))
			{
				a[s[i]-'a']++;
			}
		}
	}

	int left = 0;
	for(int i=0;i<n;i++)
	{
		if(!a[i])
			left++;
	}
	//cout<<countQ<<" "<<left<<endl;
	bool good = true;

//	if(countQ<left)
//		good = false;
	
	for(int i=0;i<=(int)s.length()/2;i++)
	{
		//cout<<i<<" "<<countQ<<" "<<left<<endl;
		if(s[i]=='?' && s[(int)s.length()-i-1]=='?')
		{
			if((countQ-1) >=left)
			{
				s[i]='a';
				s[(int)s.length()-i-1]='a';
				countQ--;
				if(!a[0])
				{
					a[0]++;
					left--;
				}
			}
			else
			{
				int t = findOneChar(a,n);
				s[i] = (t+'a');
				s[(int)s.length()-i-1]=(t+'a');
				left--;
				countQ--;
				a[t]++;
			}
		}
	}
	//cout<<s<<" "<<left<<" "<<good<<endl;
	for(int i=0;i<(int)s.length()/2;i++)
	{
		//if(s[i]=='?')
		//	cout<<i<<" fff "<<endl;
		if(s[i]!=s[(int)s.length()-i-1])
		{
			//cout<<s[i]<<" "<<s[(int)s.length()-i-1]<<endl;
			good = false;
			break;
		}
	}

	if(good && left==0)
		cout<<s<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
