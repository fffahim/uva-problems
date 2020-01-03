#include<bits/stdc++.h>
using namespace std;
string str;
int dparray[1050][1050];
int dp(int i,int j)
{
    if(i==j) return 1;
    if(j-i==1)
    {
        if(str[i]==str[j]) return 2;
        else return 1;
    }
    if(dparray[i][j]!=-1) return dparray[i][j];
    int ans=0;
    if(str[i]==str[j]) ans = 2 + dp(i+1,j-1);
    else 
    {
        int temp2 = dp(i,j-1);
        int temp1 = dp(i+1,j);
        ans = max(temp1,temp2);
    }
    return dparray[i][j]=ans;

}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
      memset(dparray,-1,sizeof(dparray));
      getline(cin,str);
      int l= str.size();
      cout<<dp(0,l-1)<<endl;
    }
}