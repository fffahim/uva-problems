#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        deque<int>left,right;
        int dup,l,m,x,countn =0,flag=0;
        char st[50];
        scanf("%d %d", &l,&m);
        l=l*100;
        while(m--)
        {

            scanf("%d %s",&x, st);
            if(st[0]=='r') right.push_back(x);
            else left.push_back(x);

        }
        while(!left.empty() || !right.empty())
        {
            countn++;


            if(flag==0)
            {
                dup=l;

            while(!left.empty())
            {

                 if(left.front()<=dup)
                {
                    dup-=left.front();
                    left.pop_front();
                }
                else
                {
                    break;
                }
            }
            flag=1;
            }
            else
            {
                dup=l;
            while(!right.empty())
            {

                if(right.front()<=dup)
                {
                    dup-=right.front();
                    right.pop_front();
                }
                else
                {
                    break;
                }
            }
            flag=0;
            }
        }
        cout<<countn<<"\n";
    }
}
