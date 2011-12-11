#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>

using namespace std;

struct node
{
	node* a[1002];
	char* s[100];
};

node* makeTree(node* root,string& s)
{
	cout<<s<<endl;
	if(!root)
	{
		root = (node*)malloc(sizeof(node));
		memset(root->a,0,sizeof(root->a));
	}

	int t = 0;
	while(s!="")
	{
		if(s[0]==',')
			s.erase(0,1);
		string m;
		bool sawDot = false;
		bool sawColon = false;
		int dot = 0;
		int colon = 0;
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]=='.')
			{
				sawDot = true;
				dot = i;
				break;
			}
			if(s[i]==':')
			{
				sawColon = true;
				colon = i;
				break;
			}
		}
		if(sawDot)
		{
			//root->s = (s.substr(0,dot));
			s.erase(0,dot+1);
			return root;
		}
		else
		{
			cout<<colon<<endl;
			cout<<"dw"<<" "<<s.substr(0,colon)<<endl;
			//root->s = s.substr(0,colon);
			s.erase(0,colon+1);
			cout<<" "<<s<<endl;
			root->a[t] = makeTree(root->a[t],s);
		}
		t++;
	}
	return root;
}
			
int main()
{
	string s;
	cin>>s;

	node* root = NULL;
	root = makeTree(root,s);

	//cout<<solve(root)<<endl;
	return 0;
}