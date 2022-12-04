#include<bits/stdc++.h>
using namespace std;
void solution(bool** arr, int size, bool* visited,int start){
  visited[start]=true;
  for(int j=0;j<size;j++){
    if(arr[start][j] == true && visited[j] == false)
      solution(arr,size,visited,j);
  }
}
int main(){
  int test; cin>>test;
  while(test--){
    int size; cin>>size;
    int quee;cin>>quee;
    bool visited[size];
    bool** arr = new bool*[size];
    for(int i=0;i<size;i++){
      arr[i] = new bool[size];
      memset(arr[i],false,sizeof arr[i]);
    }
    memset(visited,false,sizeof visited);
    for(int i=0; i<quee;i++){
      int x; cin>>x;
      int y; cin>>y;
      arr[x][y] = true;
      arr[y][x] = true;
    }
    int count =0;
    for(int i=0;i<size;i++){
      if(visited[i] == false){
        solution(arr,size,visited,i);
        count++;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
