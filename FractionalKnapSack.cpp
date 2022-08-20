#include<bits/stdc++.h>
using namespace std;
struct custom{
  int value;
  int weight;
};
bool fun(custom a,custom b){
  float w1=(float)a.value/a.weight;
  float w2=(float)b.value/b.weight;
  return w1>w2;
}
float solution(custom arr[],int size,int cap){
  sort(arr,arr+size,fun);
  float currW=0;
  float value=0;
  for(int i=0;i<size;i++){
    if(currW+arr[i].weight <= cap){
      value+=arr[i].value;
      currW+=arr[i].weight;
    }else{
      float rWe= cap - currW;
      value+=arr[i].value * (rWe/arr[i].weight);
      break;
    }
  }
  return value;
}
int main(){
 int size;cin>>size;
 int cap;cin>>cap;
 custom arr[size];
 for(int i=0;i<size;i++){
   cin>>arr[i].value>>arr[i].weight; 
 }
 cout<<"Solution => "<<solution(arr,size,cap);
 return 0;
}
