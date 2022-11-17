#include<bits/stdc++.h>
using namespace std;
class tree{
  public:
    tree* left;
    tree* right;
};
void print(tree* head,int num=0){
  if(head->right){
    cout<<"right => 1 => "<<num<<endl;
    print(head->right,num+1);
  }
  if(head->left){
    cout<<"left => 0 => "<<num <<endl;
    print(head->left,num+1);
  }
    return;
}
void build(int num, tree* head){
  for(int i=31;i>=0;i--){
    int data = (num>>i)&1;
    if(data == 0){
      if(!(head->left))
        head->left = new tree();
      head = head->left;
    }else{
      if(!(head->right))
        head->right = new tree();
      head = head->right; 
    }
  }
}
int find(int size,int* arr,tree* parentHead){
  int max=INT_MIN;
  for(int i=0;i<size;i++){
    int opNum = 0;
    tree* head= parentHead;
    for(int j=31;j>=0;j--){
      int num = (arr[i]>>j)&1;
      if(num==0){
        if(head->right){
            opNum += pow(2,j);
            head = head->right;
        }else{
          head = head->left;
        }
      }else{
        if(head->left){
          head= head->left;
        }else{
          head=head->right;
          opNum += pow(2,j);
        }
      }
    }
    int cal = arr[i]^opNum;
    cout<<opNum<<" ^ "<<arr[i]<<" => "<<cal<<endl;
    if(max<cal)
      max=cal;
  }
  return max;
}
int main(){
  int size;cin>>size;
  int arr[size];
  tree* head = new tree();
  for(int i=0;i<size;i++){
    cin>>arr[i];
    build(arr[i],head);
  }
  cout<<find(size,arr,head);
  return 0;
}
