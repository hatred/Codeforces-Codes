#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int a[1000];


int findNext(int c)
{
	for(int i=c+1;i<1000;i++){
		if(!a[i])
			return i;
	}

	return c;
}

int main()
{
	a[0]=1;
	a[1]=1;
	int n = (int)sqrt(1000);
		          for(int i=2;i<=n;i++) 
				           if (!a[i]) 
						              for(int j=i;j*i<990;j++) a[i*j] = 1; 

	
	int c,d;
	cin>>c>>d;

	int t = findNext(c);
	//cout<<t<<endl;
	if(t==d)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}