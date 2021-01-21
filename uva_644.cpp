
#include<bits/stdc++.h>
using namespace std;
struct trienode{
	int countn,flag;
	trienode * child[3];
	trienode()
	{
		countn=0;
		flag=0;
		for(int i=0;i<3;i++) child[i]=NULL;
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
    for (int i = 0; i < 3; i++)
        if (cur->child[i])
            del(cur->child[i]);

    delete (cur);
}
int main()
{
    int t=1;
    string str;
    vector<string>vec;
    while(cin>>str)
    {
        if(str[0]=='9')
        {
            root = new trienode();
            bool flag =true;
            for(int i=0;i<vec.size();i++)
            {
                flag=insert(vec[i]);
                if(flag==false) 
                {
                    cout<<"Set "<<t<<" is not immediately decodable\n";
                    break;
                }
            }
            if(flag==true) cout<<"Set "<<t<<" is immediately decodable\n";
            //del(root);
            t++;
            vec.clear();
        }
        else
        {
            vec.push_back(str);
        }
    }
}