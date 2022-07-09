#include<bits/stdc++.h>
using namespace std;
int main(){
  int num;cin>>num;
  int position;cin>>position;
  int n= pow(2,position);
  cout<< (num&(~n));
}
