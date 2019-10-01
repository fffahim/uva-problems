#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    int arr[10];
    while(t--)
    {
        int n,flag=0,k=0;
        scanf("%d", &n);
        int temp;
        while(n>=10 && flag==0)
        {
            temp=n;
            for(int i=9;i>=2;i--)
            {
                if(n%i==0)
                {
                    arr[k]=i;
                    k++;
                    n/=i;
                    break;
                }
            }
            if(temp==n) flag=1;
        }
        if(temp==1){arr[k]=1; k++;}
        else if(n<10) {arr[k]=n; k++;}
        sort(arr,arr+k);
        if(flag==1) cout<<"-1";
        else
            for(int i=0;i<k;i++) cout<<arr[i];
        cout<<"\n";
    }
}
