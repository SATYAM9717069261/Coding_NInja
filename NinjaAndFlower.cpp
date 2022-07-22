#include<bits/stdc++.h>
using namespace std;
void solution(int num){
  bool dp[num+1];
  int count=0;
  memset(dp,false,sizeof(dp));
  for(int i=2;i*i<=num;i++){
    if(dp[i] == false){
      for(int j=i*2;j<=num;j+=i){
        dp[j] = true;
      }
    }
  }
  for(int i=2;i<=num;i++){
    if(dp[i]==false)
      count++;
  }

  cout<<2<<endl;
  cout<< min(count,abs(num-count-1))<<" "<<max(count,abs(num-count-1));
}
int main(){
  int num;
  cin>>num;
  solution(num+1);
  return 0;
}
