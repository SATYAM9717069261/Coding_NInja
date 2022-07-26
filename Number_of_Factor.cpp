#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int temp[MAX+1];
void preCompute(){
  for(int i=2;i<=MAX;i++){
    if(temp[i] == 0){
        for(int j=1;(j*i)<=MAX;j++)
          temp[i*j]+=1;
    }
  }
}

int main(){
  memset(temp,0,sizeof(temp));
  preCompute();
  int test;cin>>test;
  while(test--){
    int a,b,n;cin>>a>>b>>n;
    int count=0;
    for(int i=a;i<=b;i++){
        if(temp[i] == n)
          count++;
    }
    cout<<count<<endl;
  }
  //for(int i=2;i<=MAX;i++){
  //  cout<<i<<" => "<<temp[i]<<endl;
  //}
  return 0;
}
