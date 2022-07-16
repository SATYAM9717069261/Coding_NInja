#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int solution(int arr[],int diff,int current, int start, int end){
  if(start == end )
    return 0;
  if(dp[start][diff]!=-1)
    return dp[start][diff];
  int count =0;
  if(arr[current]+diff == arr[start]){
      count+=1;
      current=start;
  }
  count += solution(arr,diff,current,start+1,end);
  
  dp[start][diff] = count;
  return count;
} 
int main(){
  int size;cin>>size;
  int arr[size];
  for(int i=0;i<size;i++)
    cin>>arr[i];
  memset(dp,-1,sizeof(dp));
  cout<<solution(arr,2,0,0,size)+1;
  return 0;
}
