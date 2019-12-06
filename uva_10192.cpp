#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int dp[150][150];
int lcs(int i, int j)
{   
    if(i==str1.size() || j==str2.size()) return 0;
    if( dp[i][j]!= -1) return dp[i][j];
    int countn =0;
    if(str1[i]== str2[j]) countn =1 + lcs(i+1, j+1);
    else
    {
        countn = max(lcs(i, j+1),lcs(i+1,j));
    }
    dp[i][j] = countn;
    return dp[i][j];
}
int main()
{  
    int i=0;
   while(getline(cin,str1))
   {
       if(str1[0]=='#') break;
       i++;
       getline(cin,str2);
       memset(dp,-1,sizeof(dp));
       printf("Case #%d: you can visit at most %d cities.\n",i,lcs(0,0));
       //cout<<"Case #"<<i<<": "<<"you can visit at most "<<lcs(0,0)<<" "<<"cities."<<endl;
   }
}