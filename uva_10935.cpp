#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        int j=0;
        if(n==0) break;
        deque<int>de;
        int arr[n];
        for(int i=1;i<=n;i++) de.push_back(i);
        cout<<"Discarded cards: ";
        while((de.size())!=1)
            {
            cout<<de.front();
            if(de.size()!=2) cout<<", ";
            de.pop_front();
            de.push_back(de.front());
            de.pop_front();
            }
        cout<<endl;
        cout<<"Remaining card: "<<de.front()<<endl;
        de.pop_front();

        }





}

