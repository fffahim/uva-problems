#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int>vec[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d", &x);
        for(int j=0;j<x;j++)
        {
            scanf("%d", &y);
            vec[i].push_back(y);
        }
    }
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        deque<int>de;
        int vis[n],i=1,temp=1;
        memset(vis,-1,sizeof(vis));
        int a,maxx=0,maxxd;
        scanf("%d",&a);
        de.push_back(a);
        vis[a]=0;
        while(!de.empty())
        {

            int t=temp;
            temp=0;
            while(t!=0)
            {

                int u = de.front();
                de.pop_front();
                for(int j=0;j<vec[u].size();j++)
                {
                    if(vis[vec[u][j]]!=0)
                    {
                       temp++;
                       vis[vec[u][j]]=0;
                       de.push_back(vec[u][j]);
                    }
                }
                t--;

            }

            if(temp>maxx)
            {
                maxx=temp;
                maxxd=i;
            }
            i++;
        }
        if(maxx==0) cout<<maxx<<"\n";
        else cout<<maxx<<" "<<maxxd<<"\n";
    }
}
