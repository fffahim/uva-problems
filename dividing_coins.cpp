#include<bits/stdc++.h>
using namespace std;
int arr[110];
int w[110][510];
int knap(int m,int s)
{
   for(int i=0;i<=m;i++)
   {
       for(int j=0;j<=s;j++)
        w[i][j]=0;
   }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(arr[i]<=j)
                w[i][j]=max(w[i-1][j], arr[i]+w[i-1][j-arr[i]]);
            else
                w[i][j]=w[i-1][j];
        }

    }
    return w[m][s];

}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int m,sum=0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            {
                scanf("%d", &arr[i]);
                sum+=arr[i];
            }
            printf("%d\n", sum- 2*knap(m,sum/2));
    }
}


