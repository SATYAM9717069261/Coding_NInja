#include<bits/stdc++.h>
using namespace std;
vector<int> ans;

bool solution(int size_, int** arr,int start, int end,int* tra_ele){
  tra_ele[start]=1;
  if(start == end)
    return true;

 for(int j=0;j<size_;j++){
   if(arr[start][j] == 1 && tra_ele[j]==0){
     if( solution(size_,arr,j,end,tra_ele)){
       ans.push_back(j);
       return true;
     }
   }
 }

 return false;
}
int main(){
  int test;cin>>test;
  while(test--){
  int size_; cin>>size_;
  int query; cin>>query;
  int** arr= new int*[size_];
  for(int i=0;i<size_;i++){
    arr[i] = new int[size_];
    for(int j=0;j<size_;j++){
      arr[i][j]=0;
    }
  }

  for(int i=0;i<query;i++){
    int x; cin>>x;
    int y; cin>>y;
    arr[x][y]=1;
    arr[y][x]=1;
  }
  int start,end; 
  cin>>start;
  cin>>end;
  int trav_ele[size_];
  memset(trav_ele,0,sizeof trav_ele);
  if(solution(size_,arr,start,end,trav_ele))
    ans.push_back(start);
  for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
  ans.clear();
  cout<<endl;
  }
  return 0;
}
