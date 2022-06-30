#include<bits/stdc++.h>
using namespace std;
int helper(int len){
  if(len == 0)
    return 0;
  return (helper(len-1)*2)+1;
}
int solution(string inp){
    int word[26];
    memset(word,-1,sizeof(word));
    int count=0;
    for(char i : inp){
      if(word[(int)i - 65] == -1) 
        count++;
      word[(int)i - 97] = 1;
    }
    return helper(count);
}
int main(){
  int test;cin>>test;
  while(test--){
    string inp;cin>>inp;
    cout<<solution(inp)+1<<endl;
  }
}
