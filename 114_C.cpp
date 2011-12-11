#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

//Added comment 
bool isValidWord(string&s)
{
	string a[] = {"lios","liala","etr","etra","initis","inites"};

	for(int i=0;i<6;i++)
	{
		if((int)s.length()<(int)a[i].length())
			continue;
		if(s.substr((int)s.length()-(int)a[i].length(),a[i].length()) == a[i])
		{
			return true;
		}
	}
	return false;
}

bool isVerb(string& s)
{
	if((int)s.length()<6)
		return false;
	
	string m = s.substr((int)s.length()-6,6);
	if(m == "initis" || m=="inites")
		return true;
	
	return false;
}

bool isNoun(string&s)
{
	if((int)s.length()<3)
		return false;
	
	string m = s.substr((int)s.length()-3,3);
	if(m == "etr")
		return true;
	
	if((int)s.length()<4)
		return false;
	
	m = s.substr((int)s.length()-4,4);

	if(m == "etra")
		return true;

	return false;
}

bool isAdjective(string& s)
{
	if((int)s.length()<4)
		return false;
	
	string m = s.substr((int)s.length()-4,4);

	if(m == "lios")
		return true;
	if((int)s.length()<5)
		return false;
	
	m = s.substr((int)s.length()-5,5);

	if(m=="liala")
		return true;
	
	return false;
}

bool isMale(string&s)
{
	string a[] = { "lios", "etr", "initis" };

	for(int i=0;i<(int)3;i++)
	{
		if((int)s.length()<a[i].length())
			continue;
		if(s.substr((int)s.length()-a[i].length(),a[i].length()) == a[i])
			return true;
	}

	return false;
}

int main()
{
	string s;
	bool male = false;
	bool female = false;
	bool good = true;
	int nounC = 0;
	int verbC = 0;
	int adjC  = 0;
	while(cin>>s)
	{
		// handle word not been there
		if(!isValidWord(s))
		{
			good = false;
			break;
		}

		//set gender
		if(isMale(s))
			male = true;
		else	
			female = true;
		//cout<<male<<" "<<female<<endl;	
		if(male && female)
		{
			good = false;
			break;
		}
		if(isAdjective(s))
		{
			if(verbC || nounC)
			{
				good = false;
				break;
			}
			adjC++;
		}
		if(isNoun(s))
		{
			if(verbC || nounC>=1)
			{
				good = false;
				break;
			}
			adjC = 0;
			nounC++;
		}
		if(isVerb(s))
		{
			if(nounC == 0 || adjC>0)
			{
				good = false;
				break;
			}
			verbC++;
		}
	}
	
	//cout<<good<<endl;
	if(good)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}

