/**
 * 0 : o
 * 1 : x
 */
#include<bits/stdc++.h>
#define gridSize 3
using namespace std;
char grid[gridSize][gridSize];
char turn;
void print(){
  for(int i=0;i<gridSize;i++){
    for(int j=0;j<gridSize;j++){
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }
}
bool checkwin(char player,int x,int y){
  //x,y current position of player
  bool right_left=1,top_bottom=1,diagonal=1;
  for(int i=0;i<gridSize;i++){
    if(grid[i][y]!=player){
      top_bottom=0;
      break;
    }
  }
  for(int j=0;j<gridSize;j++){
    if(grid[x][j]!=player){
      right_left = 0;
      break;
    }
  }
  for(int i=x,j=y;i<gridSize && j<gridSize;i++,j++){
    if(grid[i][j]!=player){
      diagonal = 0;
      return right_left | top_bottom | diagonal;
    } 
  }

  for(int i=x,j=y;i>-1 && j>-1;i--,j--){
    if(grid[i][j]!=player){
      diagonal = 0;
      return right_left | top_bottom | diagonal;
    }
  }
  return right_left | top_bottom | diagonal;
}
void solution(){
  //~turn
  turn = turn=='x'?'o':'x';
  cout<<"==============================================="<<endl;
  //print();
  for(int i=0;i<gridSize;i++){
    for(int j=0;j<gridSize;j++){
      if(grid[i][j] == '_'){
        grid[i][j] = turn;
        print();
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<turn<<"====> "<<checkwin(turn,i,j)<<endl;
        solution();
        grid[i][j] = '_';
      }
    }
  }
}

int main(){
  memset(grid,'_',sizeof(grid));
  int steps;cin>>steps;
  while(steps--){
    int x;cin>>x;
    int y;cin>>y;
    char player;cin>>player;
    turn = player;
    grid[x][y] = turn;
  }
  print();
  solution();
  return 0;
}
