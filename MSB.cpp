#include<bits/stdc++.h>
using namespace std;
int main(){
  int num;cin>>num;
  int pos;cin>>pos;
  int temp = (1<<pos);
  temp=temp-1;
  cout<<(num&temp);
  return 0;
}
