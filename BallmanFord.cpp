#include<bits/stdc++.h>
using namespace std;
class Edge{
  public:
    int v1;
    int v2;
    int weight;
};
void ballmanFord(int n, int e, Edge** edges,int end){
  int dist[n];
  memset(dist,INT_MAX,sizeof(dist));

  for(int i=0;i<n;i++){
    for(int j=0;j<e;j++){
      int u = edges[j]->v1;
      int v = edges[j]->v2;
      int weight = edges[j]->weight;
      if(dist[u]!=INT_MAX && (dist[v] > dist[u]+weight))
        dist[v] = dist[u]+weight;
    }
  }
  for(int i=0;i<n;i++)
  cout<<dist[i]<<endl;
}
void print(int n,int e,Edge** edges){
  for(int i=0;i<e;i++)
    cout<<edges[i]->v1 <<" "<< edges[i]->v2 <<" "<<edges[i]->weight <<endl;
}
int main(){
  int test; cin>>test;
  while(test--){
  int n; cin>>n;
  int e; cin>>e;
  int start;cin>>start;
  int end;cin>>end;
  Edge** edges = new Edge*[e+1];
  bool temp = true;
  for(int i=0;i<e;i++){
    edges[i] = new Edge();
    int v1;cin>>v1;
    int v2;cin>>v2;
    int weight;cin>>weight;
    if(start == v1 && temp){
      edges[i]->v1 = edges[0]->v1;
      edges[i]->v2 = edges[0]->v2;
      edges[i]->weight = edges[0]->weight;
      edges[0]->v1 = v1;
      edges[0]->v2 = v2;
      edges[0]->weight = weight;
      temp = false;
    }else{
      edges[i]->v1 = v1;
      edges[i]->v2 = v2;
      edges[i]->weight = weight;
    }
  }

  //print(n,e,edges);
  cout<<"==========================="<<endl;
  ballmanFord(n,e,edges,end);
  }
  return 0;
}
