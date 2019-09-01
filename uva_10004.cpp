#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;
        int l,x,y,flag=0;;
        vector<int>vec[10000];
        deque<int>d;
        int vis[n],col[10000];
        memset(vis,-1,sizeof(vis));
        scanf("%d", &l);
        for(int i=0;i<l;i++)
        {
            scanf("%d %d", &x, &y);
            vec[x].push_back(y);
            vec[y].push_back(x);

        }
        d.push_back(0);
        vis[0]=1;
        col[0]=0;
        while(!d.empty() && flag==0)
        {

            int x = d.front();
            d.pop_front();
            for(int j=0;j<vec[x].size();j++)
            {
                if(vis[vec[x][j]]==-1)
                {

                    d.push_back(vec[x][j]);
                    vis[vec[x][j]]=1;
                    if(col[x]==1)
                        col[vec[x][j]]=0;
                    else if(col[x]==0)
                        col[vec[x][j]]=1;
                }
                else
                {
                    if( col[x] == col[vec[x][j]])
                    {

                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==0) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");

    }
}
