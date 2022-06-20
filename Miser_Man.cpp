#include<bits/stdc++.h>
using namespace std;

int solution(int** arr,int r,int c, int m_c,int** res){
  if(r == 0)
    return arr[r][c];
  if(res[r][c]!=-1)
    return res[r][c];
  int up_l=999;
  int up_r=999;
  if( (c-1) >= 0)
      up_l= solution(arr,r-1,c-1,m_c,res);
  if((c+1)<= m_c)
      up_r= solution(arr,r-1,c+1,m_c,res);
  int up = solution(arr,r-1,c,m_c,res);
  res[r][c] = arr[r][c]+min({ up_l,up_r,up });
  return res[r][c];
}

int main(){
 int m,n;
 cin>>m>>n;
 int** arr = new int*[m];
 int** res = new int*[m];
 for(int i=0;i<m;i++){
   arr[i] = new int[n];
   res[i] = new int[n];
   for(int j=0;j<n;j++){
     cin>>arr[i][j];
     res[i][j]=-1;
   }
 }
 int min=999;
 for(int i=n-1;i>=0;i--){
   int resp = solution(arr,m-1,i,n-1,res);
   if(resp < min)
     min=resp;
 }
 cout<<min;
 return 0;
}
