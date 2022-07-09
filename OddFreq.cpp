#include<bits/stdc++.h>
using namespace std;
int main(){
  int num;cin>>num;
  int res=0;
  while(num--){
    int temp;cin>>temp;
    res= res^temp;
  }
  cout<<res;
  return 0;
}
