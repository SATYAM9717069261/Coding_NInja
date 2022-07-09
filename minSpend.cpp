#include<bits/stdc++.h>
using namespace std;
int solution(int** arr,int jobs,int person, int currentPerson,int dp[]){
  if(currentPerson == person)
    return 0;
  if(dp[currentPerson] != -1)
    return dp[currentPerson];
  int min=INT_MAX;
  for(int i=0;i<jobs;i++){
    int sum = arr[currentPerson][i] + solution(arr,jobs,person,currentPerson+1,dp);
    if(min > sum)
      min=sum;
  }
  dp[currentPerson]=min;
  return min;
}
int main(){
  int jobs;cin>>jobs;
  int person;cin>>person;
  int** arr=new int*[jobs];
  for(int i=0;i<jobs;i++){
    arr[i] =new int[person];
      for(int j=0;j<person;j++)
        cin>>arr[i][j];
  }
  int dp[person];
  for(int i=0;i<person;i++)
    dp[i]=-1;
  cout<<solution(arr,jobs,person,0,dp);
  return 0;
}
