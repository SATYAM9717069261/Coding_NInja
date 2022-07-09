#include<bits/stdc++.h>
using namespace std;
int computeXOR(int n){
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}
int main(){
    int test;cin>>test;
    while(test--){
        int num;cin>>num;
        cout<<computeXOR(num)<<endl;
    }
    return 0;
}
