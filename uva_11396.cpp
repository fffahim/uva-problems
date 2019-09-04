#include<bits/stdc++.h>
using namespace std;
vector<int>vec[350];
int color[350];
int bfs(int x)
{
    deque<int>de;
    de.push_back(x);
    color[x]=1;

    while(!de.empty())
    {
        int u = de.front();
        de.pop_front();
        for(int i=0;i<vec[u].size();i++)
        {
            if(color[vec[u][i]]==2)
            {
                //cout<<"NNN";
                color[vec[u][i]]= 1- color[u];
                de.push_back(vec[u][i]);
            }
            else if(color[u]==color[vec[u][i]])
            {

                return -1;
            }
        }
    }
    return 1;
}
int main()
{
    int v;
    while(1)
    {
        scanf("%d", &v);
        if(v==0) break;
        for(int i=1;i<=v;i++)
        {
            color[i]=2;
            vec[i].clear();
        }
        int x,y,flag=0;
        while(1)
        {
         scanf("%d %d", &x, &y);
         if(x==0 && y==0) break;
         vec[x].push_back(y);
         vec[y].push_back(x);
        }
        for(int i=1;i<=v;i++)
        {
            if(color[i]==2)
            {

                if(bfs(i)==1) flag=0;
                else flag=1;

            }

        }
        if(flag==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
