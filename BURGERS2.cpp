#include<bits/stdc++.h>
using namespace std;
int main(){
  int test;cin>>test;
  while(test--){
    int x;cin>>x;
    int y;cin>>y;
    int n;cin>>n;
    int r;cin>>r;
    if((r/y)>=n)
      cout<<0<<" "<<n<<endl;
    else{
      if((r/x) < n)
        cout<<-1<<endl;
      else{
        int g=(y*n);
        int f=(x-y);
        int m=(r-g)/f;
        if((r-(g))%f !=0)
          m++;
        cout<<m<<" "<<n-m<<endl;
      }
    }
  }
  return 0;
}
