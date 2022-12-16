#include<bits/stdc++.h>
using namespace std;
string finddata ="ACDGIIJNNNO";
int main(){
  int test;cin>>test;
  while(test--){
    int stringCount; cin>>stringCount;
    int stringLen;cin>>stringLen;
    string data="";
    while(stringCount--){
      string temp;cin>>temp;
      data+=temp;
    }
    sort(data.begin(), data.end());
    bool found=false;
    int j=0;
    for(int i=0;i<data.length();i++){
      cout<<data[i]<<" "<<finddata[j]<<" "<<i<<" "<<j<<" "<<finddata.length()-1<<endl;
        if( data[i] == finddata[j] && j==finddata.length()-1){
          found=true;
          break;
        }
      if(data[i] == finddata[j]){
        j++;
      }
    }
      if( found == true) 
        cout<<"1"<<endl;
      else
        cout<<"0"<<endl;
  }
  return 0;
}
