#include<bits/stdc++.h>
using namespace std;
int solution(int a,int b){
  if(a<b)
    return solution(b,a);
  if(b==0)
    return a;
  return solution(b,a%b);
}
int main(){
  int a,b; cin>>a>>b;
    cout<<solution(a,b);
}
