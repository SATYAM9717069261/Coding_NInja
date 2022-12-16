#include<bits/stdc++.h>
using namespace std;
class edge{
  public: 
    int start;
    int end;
    int weight;
};
bool compare(edge e1, edge e2){
  return e1.weight < e2.weight; 
}
int getparent(int num, int* arr){
  if(num == arr[num])
    return num;
  return getparent(arr[num],arr);
}
int main(){
  int test; cin>>test;
  while(test--){
    int num_v; cin>>num_v;
    int num_e; cin>>num_e;
    edge* inp = new edge[num_e];
    for(int i=0;i<num_e;i++){
      int start; cin>>start;
      int end; cin>>end;
      int weight; cin>>weight;
      inp[i].start = start;
      inp[i].end = end;
      inp[i].weight = weight;
    }
    sort(inp,inp+num_e,compare);
    
    //for(int i=0;i<num_e;i++)
    //  cout<<" Sorting => "<<inp[i].start<<" ---- "<<inp[i].end<<" => "<<inp[i].weight<<endl;



    int parent[num_v];
    for(int i=0;i<num_v;i++)
      parent[i] = i;
    int total_Weight = 0;
    for(int i=0;i<num_v-1;i++){
      int v1_parent = getparent(inp[i].start,parent);
      int v2_parent = getparent(inp[i].end,parent);
      if(v1_parent != v2_parent){
      //cout<<"Parent => "<<inp[i].start<<" => "<< v1_parent<<endl;
      //cout<<"Parent => "<<inp[i].end<<" => "<< v2_parent<<endl;
      //cout<<"Weight Add => "<<inp[i].weight<<endl; 
        total_Weight+=inp[i].weight;
        parent[v2_parent] = v1_parent;
      }
    }
    //cout<<"<================== Array ========================> "<<endl;
    //for(int i=0;i<num_v;i++){
    //  cout<<parent[i]<<endl;
    //}
    cout<<total_Weight<<endl;
  }
  return 0;
}
