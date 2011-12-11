#include<iostream>

using namespace std;


int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;

	bool aStart = ( a - 1 ) % m == 0 ? true : false;
	bool bEnd = ( b - m ) % m ==0 || b == n ? true : false;
	bool aEnd = ( a - m)  % m == 0 && a-m >=1 ? true : false;
	int bStart = ( b - 1 )% m == 0 ? true : false;
	int aRow = 0, bRow = 0;
	aRow = a%m == 0 ? a/m : a/m+1;
	bRow = b%m == 0 ? b/m : b/m+1;
	bool checkB = ( b - m ) % m ==0;
	if(aStart && bEnd)
	{
			cout<<"1"<<endl;
	}
	else if(!aStart && bEnd)
	{
		//check for same row
		if(aRow == bRow)
			cout<<"1"<<endl;
		else
			cout<<"2"<<endl;
	}
	else if(aStart && !bEnd)
	{
		if(aRow == bRow)
			cout<<"1"<<endl;
		else
			cout<<"2"<<endl;
	}
	else
	{
		int bTrail = b - 1 - (bRow-1)*m;
		int aTrail = a - 1 -  (aRow-1)*m;
		if(!bStart)
			bTrail++;
		aTrail++;
		if(aRow == bRow)
			cout<<"1"<<endl;
		else if((bRow == aRow + 1) || (aTrail + bTrail == m && bTrail<aTrail && !aEnd))
			cout<<"2"<<endl;
		else if(aEnd && bTrail == m-1)
			cout<<"2"<<endl;
		else	
			cout<<"3"<<endl;
	}
	return 0;
}