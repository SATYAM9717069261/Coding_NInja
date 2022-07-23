#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}
int main(){
    int test;cin>>test;
    while(test--){
      int a;cin>>a;
      string s;cin>>s;
      if(a==0){
        cout<<s<<endl;
        continue;
      }
      int b=0;
      int n = s.size();
      for(int i=0;i<n;i++){
        b=(10*b + s[i]-'0')%a;
      }
      cout<<gcd(a,b)<<endl;
    }
  return 0;
}

