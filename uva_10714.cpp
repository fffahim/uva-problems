#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int d,n,x;
        scanf("%d %d", &d, &n);
        int arr[n+1];
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            arr[i]=min(x,d-x);
        }
        sort(arr,arr+n);
        cout<<arr[n-1]<<" "<<d-arr[0]<<"\n";
    }
}
