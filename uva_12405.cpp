#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("inputw.txt","r",stdin);
    freopen("outputw.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int j=1;j<=t;j++)
    {
        int n;
        scanf("%d", &n);
        char str[n];
        scanf("%s", str);
        int tot=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum!=0) sum++;
            else if(str[i]=='.') sum++;
            if(sum==3)
            {
                tot++;
                sum=0;
            }

        }
        if(sum!=0) tot++;
        cout<<"Case "<<j<<": "<<tot<<"\n";
    }
}
