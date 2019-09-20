#include<bits/stdc++.h>
using namespace std;
long long int arr[1000006];
int main()
{
    long long int x;
    while(scanf("%lld", &x))
    {
        if(x<0) break;
        int j=0;
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {
                while(x%i==0)
                {
                    arr[j]=i;
                    j++;
                    x/=i;
                }
            }
        }
        if(x!=1) arr[j++]=x;
        for(int i=0;i<j;i++)
        {
            cout<<"    "<<arr[i]<<"\n";
        }
        cout<<"\n";


    }
}
