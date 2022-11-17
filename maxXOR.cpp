#include<bits/stdc++.h>
using namespace std;
class tree{
  public:
  tree* left;
  tree* right;
};

int findMax(tree* head, int* arr, int n){
  int min_xor=INT_MIN;
  for(int i=0;i<n;i++){
    tree* curr = head;
    int value = arr[i];
    int current_xor = 0;

    for(int j=31;j>=0;j--){
      int b=(value>>j)&1;
      if(b==0){
        if(curr->right){
          current_xor+=pow(2,j);
          curr=curr->right;
        }else
          curr=curr->left;
      }else{
        if(curr->left){
          current_xor+=pow(2,j);
          curr=curr->left;
        }else
          curr=curr->right;
      }
    }
    if(current_xor>min_xor)
      min_xor=current_xor;
  }
  return min_xor;
}

void insert(int num, tree* head){
  tree* cur = head;
  for(int i=31;i>=0;i--){
    int b=(num>>i)&1;
    if(b==0){
      if(!cur->left )
        cur->left = new tree();
      cur= cur->left;
    }else{
      if( !cur->right )
        cur->right=new tree();
      cur=cur->right;
    }
  }
}


int main(){
  int size;cin>>size;
  tree* current= new tree();
  int arr[size];
  for(int i=0;i<size;i++){
    int num;
    cin>>num;
    arr[i] = num;
    insert(num,current);
  }
  cout<<findMax(current,arr,size);
  return 0;
}
