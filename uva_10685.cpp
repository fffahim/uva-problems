#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int pos[6000],cost[6000],maxx;
int findfunc(int x)
{
    if(pos[x]==x) return x;

       return pos[x]=findfunc(pos[x]);

}
void unionfunc(int x, int y)
{
    int u = findfunc(x);
    int v = findfunc(y);
    if(cost[u]>=cost[v] && u!=v)
    {
        pos[v]=u;
        cost[u]+=cost[v];
        maxx=max(maxx,cost[u]);
    }
    else if(cost[v]>cost[u] && u!=v)
    {
        pos[u]=v;
        cost[v]+=cost[u];
        maxx=max(maxx,cost[v]);
    }
    return ;

}
int main()
{
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int c,r,flag=1;
    char s[50],s1[50],s2[50];
    scanf("%d %d", &c, &r);
    while(1)
    {
        scanf("%d %d", &c, &r);
        if(c==0 && r==0) break;
        maxx=1;
        memset(pos,0,sizeof(pos));
        memset(cost,0,sizeof(cost));

    for(int i=0;i<c;i++)
    {
        scanf("%s", s);
        cost[i]=1;
        m[s]=i;
        pos[i]=i;
    }
    for(int i=0;i<r;i++)
    {
        scanf("%s %s",s1, s2);
        unionfunc(m[s1],m[s2]);

    }
    printf("%d\n", maxx);



}
}
