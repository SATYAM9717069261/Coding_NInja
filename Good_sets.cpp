#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int solution(int* temp){
  int sum=0;
  for(int i=0;i<MAX;i++){
    if(temp[i]!=0){
      sum+=temp[i];
      for(int j=2*i;j<MAX;j+=i){
        if( temp[j]!=0 && j%i == 0) 
          temp[j]+=temp[i];
      }
    }
  }
  return sum;
}

void print(int* temp){
  for(int i=0;i<MAX;i++){
    cout<<i<<" => "<<temp[i]<<endl;
  }
}

int main(){
  int test;cin>>test;
  while(test--){
    int size;cin>>size;
    int temp[MAX];
    memset(temp,0,sizeof(temp));
    for(int i=0;i<size;i++){
        int num;cin>>num;
        temp[num]=1;
    }
    cout<<solution(temp)<<endl;
 //   print(temp);
  }
  return 0;
}
