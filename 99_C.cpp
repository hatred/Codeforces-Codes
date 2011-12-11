#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

string toStr(char c)
{
	string t;
	t+=c;
	return t;
}


const int arr[24][6] =
{
  {1, 2, 3, 4, 5, 6},
    {1, 2, 5, 6, 4, 3},
	  {1, 2, 4, 3, 6, 5},
	    {1, 2, 6, 5, 3, 4},
		  {2, 1, 4, 3, 5, 6},
		    {2, 1, 5, 6, 3, 4},
			  {2, 1, 3, 4, 6, 5},
			    {2, 1, 6, 5, 4, 3},
				  {3, 4, 2, 1, 5, 6},
				    {3, 4, 5, 6, 1, 2},
					  {3, 4, 1, 2, 6, 5},
					    {3, 4, 6, 5, 2, 1},
						  {4, 3, 1, 2, 5, 6},
						    {4, 3, 5, 6, 2, 1},
							  {4, 3, 2, 1, 6, 5},
							    {4, 3, 6, 5, 1, 2},
								  {5, 6, 1, 2, 3, 4},
								    {5, 6, 3, 4, 2, 1},
									  {5, 6, 2, 1, 4, 3},
									    {5, 6, 4, 3, 1, 2},
										  {6, 5, 2, 1, 3, 4},
										    {6, 5, 3, 4, 1, 2},
											  {6, 5, 1, 2, 4, 3},
											    {6, 5, 4, 3, 2, 1}
												};
												
int main()
{
	string s;
	cin>>s;
	vector<char>a;
	for(int i=0;i<(int)s.length();i++)
	{
		a.push_back(s[i]);
	}
	sort(a.begin(),a.end());

	set<string>p;
	int count = 0;
	int anand=0;
	do
	{
		string t;
		for(int i=0;i<(int)a.size();i++)
		{
			t+=a[i];
		}
		if(p.find(t)==p.end())
		{
			count++;
			for(int i=0;i<24;i++)
			{
				string n;
				for(int j=0;j<6;j++)
				{
					n+=t[arr[i][j]-1];
				}
				p.insert(n);
			}
		}
	}while(next_permutation(a.begin(),a.end()));

	cout<<(count)<<endl;
	return 0;
}
		

		