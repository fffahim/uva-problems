#include<bits/stdc++.h>
using namespace std;
struct trienode{
	int countn,flag;
	trienode * child[10];
	trienode()
	{
		countn=0;
		flag=0;
		for(int i=0;i<10;i++) child[i]=NULL;
	}
}* root;
bool insert(const string &str)
{
	trienode* curr = root;
	int len= (int)str.size(),check=0;
	for(int i=0;i<len;i++)
	{
		int temp= str[i]-'0';
		if(curr->child[temp]== NULL)
		{
			curr->child[temp]=new trienode();
		}
		if(curr->flag==1) return false;
		curr->child[temp]->countn++;
		check= curr->child[temp]->countn;
		curr= curr->child[temp];
	}
	curr->flag=1;
	if(check==1) return true;
	else return false;
}
void del(trienode* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->child[i])
            del(cur->child[i]);

    delete (cur);
}
int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		root = new trienode();
		int n;
		cin>>n;
		char str[n+1][15];
		for(int i=0;i<n;i++) cin>>str[i];
		bool flag =true;
		for(int i=0;i<n;i++)
		{
			flag=insert(str[i]);
			if(flag==false) 
			{
				cout<<"NO\n";
				break;
			}
		}
		if(flag==true) cout<<"YES\n";
		del(root);
	}
}
