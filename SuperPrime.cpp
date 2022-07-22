#include<bits/stdc++.h>
using namespace std;
long solution(long num, long* dp){
 dp[0]=1;
 dp[1]=1;
 long count =0;
 for(long i=2;i<=num;i++){
  if(dp[i] == 0){
    for(long j=i*2;j<=num;j+=i){
      dp[j] += 1;
      if(dp[j]==2){
        count+=1;   
      }
      if(dp[j]==3){
        count-=1;
      }
    }
  }
 }
 return count;
}
int main(){
  long num; cin>>num;
  long dp[num+1];
  memset(dp,0,sizeof(dp));
  cout << solution(num,dp);
  return 0;
}

