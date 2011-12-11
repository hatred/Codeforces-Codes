#include<iostream>
#include<cmath>
#include<sstream>

using namespace std;

int main()
{
	string s;
	cin>>s;

	string hr = s.substr(0,2);
	string min = s.substr(3,2);

	int h,m;
	stringstream s1,s2;
	s1<<hr;
	s1>>h;
	s2<<min;
	s2>>m;

	if(h>=12)
	{
		h = h-12;
	}

	double toth = (360.0/12.0)*h + (360.0)/(12.0*60.0)*m;
	double minh = (6.0)*m;

	cout<<toth<<" "<<minh<<endl;
	return 0;
}
