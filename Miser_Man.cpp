#include<bits/stdc++.h>
using namespace std;
void print(int** arr,int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }
}
void solve(){
  int h,k;
  cin>>h>>k;
  int mat[h][k];
  for(int i=0;i<h;i++){
    for(int j=0;j<k;j++)
      cin>>mat[i][j];
  }
  for(int i=1;i<h;i++){
    for(int j=0;j<k;j++){
      if(j==0)
          mat[i][j]+=min(mat[i-1][j],mat[i-1][j+1]);
      else if(j== k-1)
          mat[i][j] += min(mat[i-1][j],mat[i-1][j-1]);
      else
          mat[i][j]+=min(min(mat[i-1][j-1],mat[i-1][j+1]),mat[i-1][j]);
    }
  }
  int ans = INT_MAX;
  for(int j=0;j<k;j++)
    ans=min(ans,mat[h-1][j]);
  
  for(int i=0;i<h;i++){
    for(int j=0;j<k;j++)
      cout<<mat[i][j]<<" ";
    cout<<endl;
  }

  //cout<<ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
