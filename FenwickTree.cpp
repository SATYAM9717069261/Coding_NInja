#include<bits/stdc++.h>
using namespace std;
void create(int* arr, int* fenwickTree,int start, int end){
}
int main(){
  int size;cin>>size;
  int arr[size];
  int fenwickTree[size+1];
  memset(fenwickTree,0,sizeof(fenwickTree));
  for(int i=0;i<size;i++)
    cin>>arr[i];
  create(arr,fenwickTree,1,,size);
  return 0;
}
