#include<bits/stdc++.h>
using namespace std;

bool fun(pair<int,int> first,pair<int,int> sec){
  if(first.second < sec.second)
    return true;
  return false;
}
int solution(pair<int,int> arr[],int size){
  int count=1;
  int start=arr[0].second;
  for(int i=1;i<size;i++){
    if(start <= arr[i].first){
      start = arr[i].second;
      count++;
    }
  }
  cout<<"Count => "<<count<<endl;
  return 1;
}
int main(){
  int size;cin>>size;
  pair<int,int> arr[size];
  for(int i=0;i<size;i++){
    cin>>arr[i].first;
    cin>>arr[i].second;
  }
  sort(arr,arr+size,fun);
  solution(arr,size);
  for(int i=0;i<size;i++){
    cout<<arr[i].first<<" "<<arr[i].second<<endl;
  }
  return 0;
}
