#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	getline(cin,s);

	bool print = false;

	for(int i=0;i<(int)s.length();i++)
	{
		if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
		{
			print = true;
			break;
		}
	}

	if(print)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


	return 0;
}