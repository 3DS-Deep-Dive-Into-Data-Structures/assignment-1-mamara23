#include<bits/stdc++.h>
using namespace std;
#define ll long long
void maxsum(int n,int a,int b,ll arr[]){
ll prefix_sum[n];
prefix_sum[0]=arr[0];
for(int i=1;i<n;i++){
    prefix_sum[i]=arr[i]+prefix_sum[i-1];
}
multiset<pair<ll, int>>x;
    for (int i = a-1; i < b;i++) {
        x.insert({prefix_sum[i], i});
    }
    long long max1=LLONG_MIN;
    for (int i = 0; i+a-1 <= n-1; ++i) {
        if(i==0){
       max1 = max(max1, x.rbegin()->first);
       }
       else{
        max1 = max(max1, x.rbegin()->first-prefix_sum[i-1]);
       }
        x.erase({prefix_sum[i+a-1], i+a-1});
        if(i+b<=n-1){
            x.insert({prefix_sum[i+b], i+b});
        }
    }
    cout << max1;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxsum(n,a,b,arr);
return 0;
}
