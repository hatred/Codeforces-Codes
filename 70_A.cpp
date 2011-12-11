#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<climits>

using namespace std;

bool isV(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;

	return false;
}

int main()
{
	string s1,s2,s3;
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);

	int c1=0,c2=0,c3=0;

	for(int i=0;i<s1.length();i++){
		if(isV(s1[i]))
			c1++;
	}

	    for(int i=0;i<s2.length();i++){
		        if(isV(s2[i]))
				            c2++;
							    }

    for(int i=0;i<s3.length();i++){
	        if(isV(s3[i]))
			            c3++;
						    }

	if(c1==5 && c2==7 && c3==5)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}