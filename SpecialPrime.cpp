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
  int first =2;
  for(int i=3;i<=num;i++){
    //cout<<i<<" => "<<dp[i]<<endl;
    if(dp[i]==false){
      int sum=first+i+1;
     // cout<<"Sum => "<<first <<" "<<i<<" +1 => "<<sum<<endl;
      if(sum > num)
        break;
      if(dp[sum]==false)
        count++;
      first=i;
    }
  }
  cout<<count;
}
int main(){
 int num;cin>>num;
 solution(num);
}
