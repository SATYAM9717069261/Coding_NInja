#include<iostream>
using namespace std;
string solution(int s, int d){
  char ans[d+1];
  ans[d]='\0';
  ans[0]='1';
  int pending = s-1;
  for(int i=d-1;i>=1;i--){
    if(pending >= 9){
      ans[i]='9';
      pending -=9;
    }else{
      ans[i] = (char)(pending+1);
      pending = 0;
      ans[i]+=48;
    }
  }
  return ans;
}
int main(){
  int test; cin>>test;
  while(test--){
    int s;cin>>s;
    int d;cin>>d;
    cout<<solution(s,d)<<endl;
  }
}
