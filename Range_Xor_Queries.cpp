#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int xor_prefix[n];
xor_prefix[0]=arr[0];
    for(int i=1;i<n;i++){
       xor_prefix[i] = xor_prefix[i-1]^arr[i];
    }
     while(q--){
        int a,b;
        cin >>a>>b;
       if(a>1){
         int xorsum = xor_prefix[b-1]^xor_prefix[a-2];
            cout << xorsum <<"\n";
        }
        else{
            cout<<xor_prefix[b-1]<<"\n";
        }
     }
     return 0;
}