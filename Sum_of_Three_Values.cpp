#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
   vector<pair< int,int>>v(n);
   for(int i=0;i<n;i++){
    cin>> v[i].first;
    v[i].second=i+1;
   }
   sort(v.begin(),v.end());
    int flag=0;
   for(int l=0;l<n-2;l++){
    int firstnum=v[l].first;
    int j=l+1;
    int k=n-1;
    while(j<k){
      int sum= firstnum+ v[j].first+ v[k].first;
      if(sum==x){
        cout<<v[l].second<<" "<<v[j].second<<" "<<v[k].second;
         flag=1;
         break;
      }
      else if(sum<x){
        j++;
      }
      else{
        k--;
      }
    }
   }
   if(flag==0){
   cout<<"IMPOSSIBLE";
   }
   return 0;
}