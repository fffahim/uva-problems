#include<bits/stdc++.h>
using namespace std;
struct trienode{
	int countn,si;
	trienode * child[3];
	trienode()
	{
		countn=0;
		si=0;
		for(int i=0;i<3;i++) child[i]=NULL;
	}
}* root;
int insert(const string &str)
{
	trienode* curr = root;
	int len= (int)str.size(),maxx=0,xx=1;
	for(int i=0;i<len;i++)
	{
		int temp= str[i]-'0';
		if(curr->child[temp]== NULL)
		{
			curr->child[temp]=new trienode();
		}
		curr->child[temp]->countn++;
		curr->child[temp]->si=xx;
		xx++;
		curr= curr->child[temp];
		maxx=max(maxx,(curr->countn * curr->si));
	}
	return maxx;;
}
void del(trienode* cur)
{
    for (int i = 0; i < 3; i++)
        if (cur->child[i])
            del(cur->child[i]);

    delete (cur);
}
int main()
{

	int t;
	cin>>t;
	while(t--)   
	{
		root=new trienode();
		int n;
		cin>>n;
		string str;
		int maxx=0;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			int len= str.size();
			maxx=max(maxx,max(insert(str),len));
		}
		cout<<maxx<<endl;
	}
}
