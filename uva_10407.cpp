#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int arr[1005];
    int x;
    while(scanf("%d", &x))
    {
        if(x==0) break;
        arr[0]=x;
        int i=1,y,g=0;
        while(scanf("%d", &y))
        {
            if(y==0) break;
            else
            {
                arr[i]=y;
                i++;
            }
        }
        //for(int j=0;j<i;j++) cout<<arr[j]
        for(int j=1;j<i;j++)
        {
            int diff=arr[j]-arr[j-1];
            g= __gcd(g,diff);
        }
        if(g<0) g*=1;
        cout<<g<<endl;
    }
}
