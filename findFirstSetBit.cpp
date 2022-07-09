#include<bits/stdc++.h>
using namespace std;
int main(){
  int num;cin>>num;
  for(int i=0;i<16;i++){
    int temp= pow(2,i);
    if( (num&temp) != 0){
      cout<<"Found=>"<<temp <<endl;
      break;
    }else{
      cout<<"Not "<<endl;
    }
  }
  return 0;
}
