#include<bits/stdc++.h>
using namespace std;
set<int> ans;

void solution(int** arr, int size, bool* visited,int start){
  visited[start]=true;
  ans.insert(start);
  for(int j=0;j<=size;j++){
    if(arr[start][j] == 1 && visited[j] == false){
        solution(arr,size,visited,j);
    }
  }
}

int main(){
  int test;cin>>test;
  while(test--){
    int size;cin>>size;
    int query;cin>>query;
    int** arr = new int*[size+1];
    for(int i=0;i<=size;i++){
      arr[i] = new int[size+1];
      for(int j=0;j<=size;j++)
        arr[i][j]=0;
    }
    bool visited[size+1];
    memset(visited,false,sizeof visited);
  
    for(int i=0;i<query;i++){
      int x;cin>>x;
      int y;cin>>y;
      arr[x][y]=1;
      arr[y][x]=1;
      
    }
    for(int i=1;i<=size;i++){
      if(visited[i]==false){
        solution(arr,size,visited,i);
          for (auto ir = ans.begin(); ir != ans.end(); ++ir)
            cout << *ir << " ";
          cout<<endl;
       ans.clear();
     }
    }
  }
  return 0;
}
