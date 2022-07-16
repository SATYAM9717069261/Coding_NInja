#include<bits/stdc++.h>
using namespace std;
int solution(int num){
  bool prime[num];
  memset(prime,true,sizeof(prime));
  prime[0]=false;
  prime[1]=false;
  for(int i=2;i*i<num;i++){
    if(prime[i] == true){
      for(int j=i*i;j<=num;j+=i){
        prime[j] = false;
      }
    }
  }
  int count = 0;
  for(int i=0;i<=num;i++){
    if(prime[i])
      count++;
  }
  return count;
}
int main(){
  int num; cin>>num;
  cout<<solution(num);
  return 0;
}
