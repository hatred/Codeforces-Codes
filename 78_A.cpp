#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

string toString(int n)
{
	stringstream s1;
	s1<<n;
	return s1.str();
}
string solve(string s1)
{
	string ans;
	int carry = 0;
	int sum = s1[(int)s1.length()-1] - 48 + 1;
	ans = toString((sum)%10) + ans;
	carry = sum/10;

	for(int i=(int)s1.length()-2;i>=0;i--)
	{
		sum = s1[i] - 48 + carry;
		carry = sum/10;
		ans = toString((sum%10)) + ans;
	}
	return ans;
}

int main()
{
		string s;
		cin>>s;
		
		string intPart;
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]=='.')
				break;
			intPart+=s[i];
		}

		string doublePart;
		bool startAdding = false;

		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]=='.')
			{
				startAdding = true;
				continue;
			}
			if(startAdding)
			{
				doublePart+=s[i];
			}
		}
		if((intPart[(int)intPart.length()-1]-'0')%10==9)
		{
			cout<<"GOTO Vasilisa."<<endl;
		}
		else
		{
			int t = doublePart[0] - '0';
			if(t<5)
			{
				cout<<intPart<<endl;
			}
			else
			{
				cout<<solve(intPart)<<endl;
			}
		}
	return 0;
}
