#include<bits/stdc++.h>
using namespace std;
bool check(int arr[], int p,int size){
  for(int i=size-1;i<=0;i--){
    if( arr[i] > p)
      arr[i-1] += arr[i] - p;
  }
  if(arr[0] > p)
    return false;
  return true;
}
int main(){
  int test; cin>>test;
  while(test--){
    int size;  cin>>size;
    int arr[size];
    for(int& i:arr)
      cin>>i;
    int low =0;
    int ans = 0;
    int high = *max_element(arr, arr + size);
    while(low <= high){
      int mid = (low+high)/2;
      if(check(arr,mid,size)){
        high = mid-1;
        ans = mid;
      }else{
        low=mid+1;
      }
    }
    cout<<ans;
  }
  return 0;
}
