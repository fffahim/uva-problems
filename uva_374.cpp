#include<bits/stdc++.h>
using namespace std;

unsigned long long bigmod(  int  b, int  p,int  m)
{
    if(p==0)
        return 1%m;
 unsigned long long x=bigmod(b,p/2,m);
    x=(x*x)%m;
    if(p%2==1)
        x=(x*b)%m;
    return x;


}

int main()
{
   int  b,p;
   int m;
    while(cin>>b>>p>>m)
    {
                printf("%llu\n", bigmod(b,p,m));
    }
}
