#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d", &t);
    string s="";
    while(t--)
    {
        cout<<s;
        s="\n";
        deque<int>left,right,leftr,rightr;
        int n,t,m,x,flag=0,sum=0,temp,i=0;
        char str[50],res[100000];
        scanf("%d %d %d", &n, &t, &m);
        int z =m;
        while(z--)
        {
            scanf("%d %s", &x, &str);
            res[i]=str[0];
            i++;
            if(str[0]=='r') right.push_back(x);
            else left.push_back(x);
        }

        while(!right.empty() || !left.empty())
        {

            temp = n;
            if(flag==0)
            {
                while(temp!=0 && flag==0 )
                {
                    if(left.front()<=sum&& !left.empty())
                    {
                        leftr.push_back(sum+t);
                        left.pop_front();
                        temp--;
                    }


                    else if(temp<n)
                    {
                        flag=1;
                        sum+=t;

                    }
                    else if(left.front()<=right.front() && !left.empty() && !right.empty())
                    {
                        sum=left.front();
                        leftr.push_back(sum+t);
                        left.pop_front();
                        temp--;

                    }
                    else if(left.front()>=right.front() && !left.empty() && !right.empty())
                    {
                        sum=max(sum,right.front());
                        sum+=t;
                        flag=1;
                    }
                    else if(!left.empty() && right.empty())
                    {
                        sum=left.front();
                        leftr.push_back(sum+t);
                        left.pop_front();
                        temp--;
                    }
                    else if(left.empty() && !right.empty())
                    {
                        sum=max(sum,right.front());
                        sum+=t;
                        flag=1;
                    }


                }
                if(temp==0)
                {
                    flag=1;
                    sum+=t;
                }

            }
            else
            {
                while(temp!=0 && flag==1)
                {
                    if(right.front()<=sum && !right.empty())
                    {
                        rightr.push_back(sum+t);
                        right.pop_front();
                        temp--;
                    }


                    else if(temp<n)
                    {
                        flag=0;
                        sum+=t;
                    }
                    else if(right.front()<=left.front() && !right.empty() && !left.empty())
                    {
                        sum= right.front();
                        rightr.push_back(sum+t);
                        right.pop_front();
                        temp--;

                    }
                    else if(right.front()>left.front() && !right.empty() && !left.empty())
                    {
                        sum= max(sum,left.front());
                        sum+=t;
                        flag=0;
                    }
                    else if(!right.empty() && left.empty())
                    {
                         sum= right.front();
                        rightr.push_back(sum+t);
                        right.pop_front();
                        temp--;
                    }
                    else if(right.empty() && !left.empty())
                    {
                        sum=max(sum,left.front());
                        sum+=t;
                        flag=0;
                    }



            }
            if(temp==0)
            {
                sum+=t;
                flag=0;
            }
        }
        }

        for(int j=0;j<m;j++)
        {
            if(res[j]=='r')
            {
                cout<<rightr.front()<<endl;
                rightr.pop_front();
        }
        else
        {
            cout<<leftr.front()<<endl;
            leftr.pop_front();
        }

    }


}
}
