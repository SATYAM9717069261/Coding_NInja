#include<bits/stdc++.h>
using namespace std;

void solution(vector<vector<int>>&arr,vector<int>&visited,vector<int>&p,int start){
    p.push_back(start);
    visited[start]=1;
    for(int curr :arr[start]){
        if(visited[curr]==0){
            visited[curr]=1;
            
            solution(arr,visited,p,curr);
        }
    }
}

int main() {
  int test;
  cin >> test;
  while (test--) {
    int size;
    cin >> size;
    size+=1;
    int query;
    cin >> query;
    vector<vector<int>>arr(size+1);
    vector<int>visited(size+1);
    for (long long i = 0; i < query; i++) {
      int x; cin >> x;
      int y; cin >> y;
      arr[x].push_back(y);
      arr[y].push_back(x);
    }

       vector<vector<int>>ans;
        for(int i=1;i<size;i++){
         if(visited[i]==0){
             vector<int>p;
             solution(arr,visited,p,i);
             sort(p.begin(),p.end());
        ans.push_back(p); 
         }
          
    }
        for(int j=0;j<ans.size();j++){
        for(int k=0;k<ans[j].size();k++){
            cout<<ans[j][k]<<" ";
        }
        cout<<endl;
    
  }
  }
  return 0;
}
