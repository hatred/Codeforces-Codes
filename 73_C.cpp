#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;

	long long lcm = (a/__gcd(a,b))*b;
	long long mul1 = lcm/a;
	long long mul2 = lcm/b;
	if(a<b)
		mul1--;
	else
		mul2--;
	if(mul1==mul2)
		cout<<"Equal"<<endl;
	if(mul1>mul2)
		cout<<"Dasha"<<endl;
	if(mul1<mul2)
		cout<<"Masha"<<endl;
	return 0;
}