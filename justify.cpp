#include<iostream>

using namespace std;


int main()
{
	string s;
	getline(cin,s);
	int n;
	cin>>n;

	string buf;

	for(int i=0;i<(int)s.length();i++)
	{
		buf+=s[i];
		if((int)buf.length()>n)
		{
			int j = (int)buf.length()-1;
			while(j>=0)
			{
				if(buf[j]!=' ')
					break;
				j--;
			}
			string m;
			if(i+1<(int)s.length() && s[i+1]!=' ')
			{
				while(j>=0)
				{
					if(buf[j]==' ')
					{
						j--;
						break;
					}
					m= buf[j] + m;
					j--;
				}
			}
			for(int k=0;k<=j;k++)
			{
				cout<<buf[k];
			}
			cout<<endl;
			buf = m;
		}
	}

	if((int)buf.length()>0)
		cout<<buf<<endl;

	return 0;
}