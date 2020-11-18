#include<bits/stdc++.h>
using namespace std;
char str[1000006];
int main()
{
    while(1)
    {
        cin>>str;
        if(str[0]=='.') break;
        int arr[100];
        for(int i=0;i<=100;i++) arr[i]=0;
        int len= strlen(str);
        set<char>s;
        for(int i=0;i<len;i++)
        {
            s.insert(str[i]);
            arr[str[i]-'a']++;
        }
        int brr[100],j=0;
        set<char>::iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            brr[j]= arr[*it-'a'];
            j++;
        }
        sort(brr,brr+j);
        if(j==1)
        {
            cout<<len<<endl;
            continue;
        }
        int flag=0;
        int temp=__gcd(brr[0],brr[1]);
        for(int i=0;i<j;i++)
        {
            if(brr[i]%temp!=0)
            {
                flag=1;
                break;
            }
            
        }
        if(flag==1) 
        {
            cout<<"1\n";
            continue;
        }
        for(it=s.begin();it!=s.end();it++)
        {
            arr[*it-'a']= arr[*it-'a']/temp;
        }
        string fin;
        for(int i=0;i<len;i++)
        {
            if(arr[str[i]-'a']<=0) break;
            else
            {
                fin+=(str[i]);
                arr[str[i]-'a']--;
            }
        }
        int ll= fin.length();
        j=0;
        flag=0;
        for(int i=0;i<len;i++)
        {
            if(j>=ll) j=0;
            if(str[i]!=fin[j])
            {
                flag=1;
                break;
            }
            j++;
        }
        if(flag==1)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<temp<<endl;
        }
        
    }
}