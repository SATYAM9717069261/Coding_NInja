#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int solution(pair<int,int>* arr, int start,int end,int cap,int ass){
  if(start == end)
    return arr[0].first;
  if(dp[cap][ass] != -1)
      return dp[cap][ass];
  int cost = INT_MAX;
  if( cap <= end/2 && ass > cap)
     cost = min(cost, arr[0].first+ solution(arr+1,start+1,end,cap+1,ass));
  if(ass <= end/2)
      cost = min(cost,arr[0].second+solution(arr+1,start+1,end,cap,ass+1));
  dp[cap][ass] = cost;
  return cost;
}

int main(){
	int test;cin>>test;
    while(test--){
        int size;cin>>size;
        pair<int,int> arr[size];
        memset(dp,-1,sizeof(dp));
		for(int i=0;i<size;i++)
            cin>>arr[i].first>>arr[i].second;
        cout<<solution(arr,0,size-1,0,0)<<endl;
    }
  return 0;
}

