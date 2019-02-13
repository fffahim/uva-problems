#include<bits/stdc++.h>
using namespace std;
int price[1001];
int weight[1001];
int pro[1001][1001];
int n;
int solve(int i, int g)
{
    if(i==n)
        return 0;
    if(pro[i][g]!=-1)
        return pro[i][g];
    int profit1,profit2;
    if(g>=weight[i])
    profit1=price[i]+solve(i+1,g-weight[i]);
    else
        profit1=0;
    profit2=solve(i+1,g);
    pro[i][g]=max(profit1,profit2);
    return pro[i][g];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(pro, -1, sizeof(pro));
        int g,q;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>price[i]>>weight[i];

        }
        cin>>g;
        int ans=0;
        for(int i=0;i<g;i++)
        {
            cin>>q;
            ans+=solve(0,q);
        }
        printf("%d\n", ans);
    }
}
