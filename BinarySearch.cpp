#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int start,int end , int find){
  int mid = (end-start)/2 + start;
  cout<<"Start => "<< start <<" End => "<< end<<" Mid => "<<mid<<endl;
  if(start == mid)
    return start;
  if(arr[mid] <= find)
    return binarySearch(arr,mid,end,find);
  else
    return binarySearch(arr,start,mid,find);
}

int main(){
  int size;cin>>size;
  int arr[size];
  for(int i=0;i<=size;i++)
    cin>>arr[i];
  int find;cin>>find;
  int start;cin>>start;
  int end;cin>>end;
  cout<<binarySearch(arr,start,end,find);
  return 0;
}
