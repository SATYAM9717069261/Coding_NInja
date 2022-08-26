#include<bits/stdc++.h>
using namespace std;
void buildTree(int* arr, int start, int end, int* tree, int treeNode){
  if(start==end){
    tree[treeNode]=arr[start];
    return ;
  }
  int mid = (end+start)/2;
  buildTree(arr,start,mid,tree,2*treeNode);
  buildTree(arr,mid+1,end,tree,(2*treeNode)+1);
  tree[treeNode]=min(tree[2*treeNode], tree[(2*treeNode)+1]);
}

void update(int* tree,int start,int end, int treeNode, int index, int value){
  if(start == end && start == index){
    tree[treeNode] = value;
    return ;
  }
  int mid = (start+end)/2;
  if(index > mid)
    update(tree,mid+1,end,(2*treeNode)+1,index,value);
  else
    update(tree,start,mid,(2*treeNode),index,value);
  tree[treeNode]=min(tree[2*treeNode], tree[(2*treeNode)+1]);
}
void print(int* tree, int size){
  for(int i=1;i<size;i++)
    cout<<i<<" => "<<tree[i]<<endl;
}

int findmin(int* tree,int start,int end, int treeNode, int left, int right){
  if(start>right || end < left)
    return INT_MAX;
  if(start>=left && end <= right) 
    return tree[treeNode];
   
  int mid = (start+end)/2;
  int ans1 = findmin(tree,start,mid,2*treeNode,left,right);
  int ans2 = findmin(tree,mid+1,end,(2*treeNode)+1,left,right);
  return min(ans1,ans2);
}

int main(){
 int size;cin>>size;
 int qSize;cin>>qSize;
 int arr[size];
 for(int i=0;i<size;i++){
   cin>>arr[i];
 }
 int tree[size*4];
 memset(tree,INT_MAX,sizeof(tree));
 buildTree(arr,0,size-1,tree,1);
 while(qSize--){
  char q;cin>>q;
  int a;cin>>a;
  int b;cin>>b;
  if(q=='u'){
    update(tree,0,size-1,1,a-1,b); //index, value
  }if(q=='q'){
    cout<<findmin(tree,0,size-1,1,a-1,b-1)<<endl; //start,end
  }
 }
 return 0;
}
