#include<bits/stdc++.h>
using namespace std;
long solution(long** arr, long stu_can,long current,long status,long* dp){
  if(current == stu_can)
    return 1;
  long count=0;
  if(dp[status]!=-1){
    return dp[status];
  }
  for(int i=0;i<stu_can;i++){
    if( arr[current][i] == 1 && (status&(1<<i)) == 0 )
        count+=solution(arr,stu_can,current+1,status|(1<<i),dp);
  }
  dp[status]=count;
  return count;
}

int main(){
  int test;cin>>test;
  while(test--){
    long stu_can; cin>>stu_can;
    long** arr = new long*[stu_can];
    long* dp=new long[1<<stu_can];
    for(int i=0;i<stu_can;i++){
      arr[i]=new long[stu_can];
      for(int j=0;j<stu_can;j++)
        cin>>arr[i][j];
    }
    for(int i=0;i<(1<<stu_can);i++){
      dp[i]=-1;
    }
    cout<<solution(arr,stu_can,0,0,dp)<<endl;
    delete(dp);
  }
  return 0;
}
