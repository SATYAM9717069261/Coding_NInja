#include<bits/stdc++.h>
using namespace std;
struct Job{ int start,finish,profit;};
bool compare(Job a, Job b){
  return a.finish < b.finish;
}

int upper_bound(Job arr[], int low, int high, int X){
    if (low > high) {
        return low;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid].finish <= X)
        return upper_bound(arr, mid+1,high, X);
    return upper_bound(arr,low, mid - 1, X);
}
int findProfit(Job arr[],int n){
  sort(arr,arr+n,compare);
  int *dp = new int[n];
  dp[0] = arr[0].profit;
  for(int i=1;i<n;i++){
    int including= arr[i].profit;
    int lNConflict = upper_bound(arr,0,i-1,arr[i].start);
    /**for(int j = i-1;j>=0;j--){
      if(arr[j].finish <= arr[i].start){
        lNConflict = j;
        break;
      }
    }**/
    cout<<"lower Bound => "<< lNConflict<<endl;
    if(lNConflict != 0){
      including +=dp[lNConflict];
    }
    /**else{
      if(arr[lNConflict].finish <= arr[i].start)
        including +=dp[lNConflict];
    }**/
    dp[i] = max(including,dp[i-1]);
  }
  int ans =dp[n-1];
  delete[] dp;
  return ans;
}

int main(){
  Job arr[] = {{1,2,200},{1,3,50},{3,10,20},{6,19,100},{4,100,200}};
  cout<<"max Profit => "<<findProfit(arr,5);
  return 0;
}
