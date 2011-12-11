#include<iostream>
#include<map>

using namespace std;

string getB(int number) {
	if(number==0)
		return "0";
	string s;

	while(number!=0)
	{
		int t = number%2;
		char res = t + '0';
		s = res + s;
		number/=2;
	}

	for(int i=0;i<8-(int)s.length();i++)
	{
		s = '0' + s;
	}
	return s;
}

int getN(string bin)
{
	int index =0;
	int sum = 0;
	for(int i=(int)bin.length()-1;i>=0;i--)
	{
		if(bin[i]=='1')
		{
			sum+=(1<<index);
		}
		index++;
	}
	return sum;
}

int main()
{
	string s;
	getline(cin,s);

	char prev = '\0';

	for(int i=0;i<(int)s.length();i++)
	{
		char c = s[i];
		string bin = getB(c);
		reverse(bin.begin(),bin.end());
		int num = getN(bin);
		string bin2 = prev =='\0' ? "00000000" : getB(s[i-1]);
		cout<<bin2<<" "<<prev<<endl;
		reverse(bin2.begin(),bin2.end());
		int x = prev == '\0' ? 0 : getN(bin2);
		cout<<x<<endl;
		prev = s[i];
		int rem = 0;
		if(x==num)
			rem = 0;
		else if(x>num)
			rem = x - num;
		else
			rem = x - num + 256;

		cout<<rem<<endl;
	}

	return 0;
}
