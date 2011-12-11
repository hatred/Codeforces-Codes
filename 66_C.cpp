#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;

map<string, vector<string> >p;

int countFolders(string root)
{
	//cout<<root<<" dwdw "<<endl;
	vector<string> t = p[root];
	int count = 0;

	for(int i=0;i<t.size();i++){
		string m = t[i];
		int finder = t[i].find(".");
		if(finder == string::npos)
		{
			count+=countFolders(root+ t[i] +"/");
			count++;
		}
	}

	return count;
}

int countFiles(string root)
{
	vector<string>t = p[root];
	int count = 0;

	for(int i=0;i<t.size();i++){
		string m = t[i];
		int finder = t[i].find(".");
		if(finder==string::npos)
		{
			count+=countFiles(root+ t[i] + "/");
		}
		else
		{
			count++;
		}
	}
	return count;
}

string replaceAll(string s)
{
	for(int i=0;i<s.length();i++){
		if(s[i]=='\\')
		{
			s[i]=' ';
		}
	}
	return s;
}

int main()
{
	string s;
	vector<string>a;
	while(cin>>s)
	{
		a.push_back(s);
	}

	vector<int>ans(2);
	vector<string>root;
	for(int i=0;i<a.size();i++){
		string temp = a[i].substr(0,1) + a[i].substr(3,(int)a[i].length()-3);
		//cout<<" one done"<<temp<<endl;
		string s2 = replaceAll(temp);
		//cout<<s2<<endl;
		stringstream s1;
		s1<<s2;
		string m;
		vector<string>b;
		while(s1>>m)
		{
			b.push_back(m);
		}

		temp = b[0]+"/";
		string rootS = temp;
		for(int j=0;j<b.size()-1;j++){
			//cout<<temp<<endl;
			if(!binary_search(p[temp].begin(),p[temp].end(),b[j+1]))
				p[temp].push_back(b[j+1]);
			temp = temp + b[j+1] + "/";
			sort(p[temp].begin(),p[temp].end());
		}
		root.push_back(rootS);
	}
//	map<string, vector<string> >::iterator it;
//	for(it= p.begin();it!=p.end();it++){
		//string t1 = (*it).first;
//		for(int i=0;i<(*it).second.size();i++)
//		{
			//cout<<(*it).second[i]<<" dwwdwwdwwdw "<<(*it).first<<endl;
//		}
//	}
	for(int i=0;i<root.size();i++){
		ans[0] = max(ans[0],countFolders(root[i]));
		ans[1] = max(ans[1],countFiles(root[i]));
	}
	cout<<ans[0]<<" "<<ans[1]<<endl;

}


