#include<bits/stdc++.h>
using namespace std;
int color[100000];
vector<int>vec[250];
int bfs(int s)
{
    int countn=0,total=0;
   deque<int>de;
   de.push_back(s);
   color[s]=1;

   while(!de.empty())
   {
       total++;
       int u = de.front();
       de.pop_front();

       if(color[u]==1) countn++;
       for(int i=0;i<vec[u].size();i++)
       {
           if(color[vec[u][i]]==2)
           {
               color[vec[u][i]]=1-color[u];
               de.push_back(vec[u][i]);
           }
           else if(color[u]==color[vec[u][i]])
           {
               return -1;
           }

       }
   }
   if(total==1) return 1;
   else return min(countn, total-countn);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int v,e,x,y,finaln=0,flag=0;
        scanf("%d %d", &v, &e);

        for(int i=0;i<v;i++)
        {
            color[i]=2;
            vec[i].clear();
        }
        for(int i=0;i<e;i++)
        {
            scanf("%d %d", &x, &y);
            vec[x].push_back(y);
            vec[y].push_back(x);

        }

        for(int i=0;i<v && flag==0;i++)
        {

            if(color[i]==2)
            {

                int ans = bfs(i);
                if(ans==-1)
                {
                    flag=1;
                }
                else finaln+=ans;
            }
        }
        if(flag==1) printf("-1\n");
        else printf("%d\n", finaln);
    }
}
