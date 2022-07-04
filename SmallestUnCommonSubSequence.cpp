#include<bits/stdc++.h>
using namespace std;

int solution(char* s1,char* s2,int s1Len, int s2Len){
  if(s1Len<0 || s2Len <0)
    return 0;
  int k=0;
  for(k=0;k<s2Len;k++){
    if(s1[0] == s2[k])
      break;
  }
  bool find = true;
  if(k==s2Len)
    find = false; //s1[0] is not in s2

  int selected = solution(s1+1,s2+k,s1Len-1,s2Len-k)+1;
  int notselected =solution(s1+1,s2+k,s1Len-1,s2Len-k);
  int resp = find ? min(selected,notselected) : min(selected,notselected)+1;
  return resp;
}

int main(){
  string s1; cin>>s1;
  string s2; cin>>s2;
  solution(&s1[0],&s2[0],s1.length(),s2.length());
  return 0;
}
