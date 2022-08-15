#include<bits/stdc++.h>
using namespace std;
int main(){
  int test;cin>>test;
  while(test--){
    int size;cin>>size;
    int arr[size];
    for(int i=0;i< size;i++)
      cin>>arr[i];
    sort(arr,arr+size);

    int min=1000007;
    for(int i=1;i<size;i++){
      if(min > (arr[i]-arr[i-1])) 
          min =arr[i]-arr[i-1];
    }
      cout<<min<<endl;
  }
  return 1;
}
