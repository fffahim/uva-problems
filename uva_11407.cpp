#include<bits/stdc++.h>
using namespace std;
int dparr[10005];
int dp(int n,int i)
{
    if(i*i>n) return n;
    if(dparr[n]!=-1) return dparr[n];
    int temp1 = 1 + dp(n-(i*i),i);
    int temp2 = 1 + dp(n-i*i,i+1);
    int temp3 = dp(n,i+1);
    dparr[n]= min(temp1,min(temp2,temp3));
    return dparr[n];
}
int main()
{
    //  freopen("fahimin.txt","r",stdin);
    //  freopen("fahimout.txt","w",stdout);
    int t;
    cin>>t;
     memset(dparr,-1,sizeof(dparr));
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp(n,1)<<endl;
    }
}
