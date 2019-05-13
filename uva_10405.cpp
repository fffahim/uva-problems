#include<bits/stdc++.h>
using namespace std;
char str1[1005];
char str2[1005];
int visit[1005][1005];
int x, y;
int dp(int i, int j)
{
    if( str1[i] == '\0' || str2[j] == '\0' ) return 0;
    if( visit[i][j]!= -1) return visit[i][j];
    int countn =0;
    if(str1[i]== str2[j]) countn =1 + dp(i+1, j+1);
    else
    {
        countn = max(dp(i, j+1),dp(i+1,j));
    }
    visit[i][j] = countn;
    return visit[i][j];


}
int main()
{
    while(gets(str1))
    {   gets(str2);
        memset(visit, -1, sizeof(visit));
        x= strlen(str1);
        y=strlen(str2);
        printf("%d\n", dp(0,0));

    }
}
