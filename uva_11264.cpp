#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll Array[n];
        for(int i=0;i<n;i++) cin>>Array[i];
        ll Biggest=Array[0];
        int coin=1;
        for(int i=1;i<n-1;i++){
            if (Biggest+Array[i]<Array[i+1]){
                Biggest+=Array[i];
                coin++;
            }
        }
        coin++;
        cout<<coin<<endl;
    }
    return 0;
    }
