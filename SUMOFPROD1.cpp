#include<bits/stdc++.h>
using namespace std;
int main(){
  int test;cin>>test;
  while(test--){
    int arrsize;cin>>arrsize;
    int arr[arrsize];
    int count = 0;
    int ans=0;
    for(int i=0;i<arrsize;i++){
      cin>>arr[i];
      if(arr[i]==1){
        count++;
      }else{
    //    cout<<"Count => "<<count<<endl;
        ans += (count*(count+1))/2;
        count=0;
      }
    }
    ans += (count*(count+1))/2;
    cout<<ans<<endl;
  }
  return 0;
}
