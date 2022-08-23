#include<bits/stdc++.h>
using namespace std;
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) {
  int arr[n];
  int totalcost = 0;
  for(int i=0;i<n;i++ ){
    arr[i] = gas[i] - cost[i];
    totalcost +=arr[i];
  }
  if(totalcost<0)
    return -1;
  else{
    int pos=-1;
    int temp=-1;
    for(int i=0;i<n;i++){
      if(pos!=-1){
        temp+=arr[i];
        if(temp<0)
          pos=-1;
      }else{
        if(arr[i]>=0){
          pos=i;
          temp=arr[i];
        }
      }
    }
    return pos;
  }
}
int main(){
  int test ;cin>>test;
  while(test--){
    int size;cin>>size;
    vector<int> gas;
    vector<int> cost;
    for(int i=0;i<size;i++){
      int a;cin>>a;
      gas.push_back(a);
    }
    for(int i=0;i<size;i++){
      int b;cin>>b;
      cost.push_back(b);
    }
    cout<<minimumStartingIndex(gas,cost,size)<<endl;
  }
}
