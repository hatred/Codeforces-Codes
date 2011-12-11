#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string toString(int sum)
{
	stringstream s1;
	s1<<sum;
	return s1.str();
}
int main()
{
	string s;
	cin>>s;
	int count = 0;
	while((int)s.length()>1)
	{
		int sum = 0;
		for(int i=0;i<(int)s.length();i++)
		{
			sum += (s[i]-'0');
		}
		s = toString(sum);
		count++;
	}
	
	cout<<count<<endl;
	return 0;
}