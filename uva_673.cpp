#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;

    scanf("%d", &t);
    while(t--)
    {   int flag=0;
     char str[150];
        scanf("%s", str);
        stack<char>st;
        int l= strlen(str);
        for(int i=0;i<l;i++)
        {

            if(str[i]== '(' || str[i]== '[')
                st.push(str[i]);
            else if(str[i]==')')
            {
                if(st.empty())
                {
                    flag=1;
                    break;
                }
                else if(st.top()!= '(')
                {
                    flag=1;
                    break;
                }
                else st.pop();
            }
            else if(str[i]==']')
            {
                if(st.empty())
                {
                    flag=1;
                    break;
                }
                else if(st.top()!='[')
                {
                    flag=1;
                    break;
                }
                else st.pop();
            }


        }


        if(flag==0 && st.empty()) printf("Yes\n");
        else printf("No\n");

    }
}
