#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n,x,y;
    string s="";

    while(1)
    {
        cout<<s;
        deque<int>res,zero;
        int flag=0;
        scanf("%d", &n);
        if(n==0) break;
        y=n;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            if(x==0 && !res.empty())
            {
                zero.push_back(x);
            }
            else if(x!=0)
            {
                while(!zero.empty())
                {
                    res.push_back(zero.front());
                    zero.pop_front();
                }
                res.push_back(x);
            }
        }
        if(res.empty())
        {
            flag=1;
            cout<<"0";
        }
        while(res.size()>1 && flag==0)
        {
            if(res.front()!=0) cout<<res.front()<<" ";
            res.pop_front();
        }
        if(flag==0) cout<<res.front();
        s="\n";
    }
}
