#include<bits/stdc++.h>
using namespace std;

pair<int,bool> solution(pair<int,bool>** arr,int r,int c, int m_c){
  if(r == 0)
    return arr[r][c];
  if(arr[r][c].second == 1)
    return arr[r][c];
  int up_l=999;
  int up_r=999;
  if( (c-1) >= 0)
      up_l= solution(arr,r-1,c-1,m_c).first;
  if((c+1)<= m_c)
      up_r= solution(arr,r-1,c+1,m_c).first;
  int up = solution(arr,r-1,c,m_c).first;
  arr[r][c] = make_pair( arr[r][c].first+min({ up_l,up_r,up }) , 1);
  return arr[r][c];
}

int main(){
 int m,n;
 cin>>m>>n;
 pair<int,bool>** arr = new pair<int,bool>*[m];
 for(int i=0;i<m;i++){
   arr[i] = new pair<int,bool>[n];
   for(int j=0;j<n;j++){
     int a;cin>>a; 
     arr[i][j]=make_pair(a,0);
   }
 }
 int min=999;
 for(int i=n-1;i>=0;i--){
   pair<int,bool> resp = solution(arr,m-1,i,n-1);
   if(resp.first < min)
     min=resp.first;
 }
 cout<<min;
 return 0;
}
