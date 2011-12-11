#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000000000

vector<int>a;

void solve(long long n)
{
	if(n>MAX)
		return;
	a.push_back(n);	
	solve(n*10+4);
	solve(n*10+7);
}

int main()
{
	solve(4);
	solve(7);
	cout<<(int)a.size()<<endl;	
	return 0;
}