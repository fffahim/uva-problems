#include<bits/stdc++.h>
using namespace std;
int arr[110];
vector<int>vec;
void seive(int v)
{

    for(int i=4;i<=v;i+=2 ) arr[i]=1;

    for(int i=3;i*i<=v;i++)
    {

        if(arr[i]==0)
        {
            for(int j=i*i;j<=v;j+= 2*i) arr[j]=1;
        }
    }



    for(int i=2;i<=v;i++)
    {

        if(arr[i]==0) vec.push_back(i);

    }


}
int main()
{
   freopen("intp.txt","r",stdin);
   freopen("ooo.txt","w",stdout);
    int n,d;
    seive(105);
    while(scanf("%d %d", &n, &d))
    {
        if(n==0 && d==0) break;
        d=abs(d);
        long long int tot=1;
        int countn[110];
       memset(countn,0,sizeof(countn));
        for(int i=0;i<vec.size() && vec[i]<=n;i++)
        {
            int x=n;
            int res=0;
            while(x/vec[i])
            {
                res+= x/vec[i];
                x/=vec[i];
            }
            countn[vec[i]]=res;

        }
        for(int i=0;i<vec.size() && vec[i]<=n;i++)
        {
            int r =0;
            if(d%vec[i]==0)
            {
                while(d%vec[i]==0)
                {
                    r++;
                    d/=vec[i];
                }
                countn[vec[i]]-=r;


            }
        }
        if(d!=1) tot=0;
        else
        {
         tot=1;
        for(int i=0;i<vec.size();i++)
        {
            if(countn[vec[i]]>0) tot*=(countn[vec[i]]+1);
            else if(countn[vec[i]]<0)
            {
                tot=0;
                break;
            }

        }
        }
        cout<<tot<<endl;
    }
}
