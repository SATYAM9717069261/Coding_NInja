#include<bits/stdc++.h>
using namespace std;
bool comp(int a,int b){
  if(a>b)
    return true;
  return false;
}
int main(){
  int test;cin>>test;
  while(test--){
   int size;cin>>size;
   int arr[size];
   for(int i=0;i<size;i++)
     cin>>arr[i];
   sort(arr,arr+size,comp);
   long long result = 0;
   for(int i=0;i<size;i++)
      result+=(pow(2,i)*arr[i]);
   cout<<result<<endl;
  }
  return 0;
}
