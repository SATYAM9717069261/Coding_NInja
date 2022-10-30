#include<bits/stdc++.h>
using namespace std;

bool chk(string str, int start , int end){
  cout<< "Start => "<<start <<"End => "<<end<<endl;
  if(start == end && str[start] == '0')
    return true;
  int rem=0;
  for(int i=start;i<= end ;i++){
    int num = str[i]-'0' + 10 * rem;
    rem = num % 3;
  }
  if(rem == 0)
    return true;
  return false;
}


int solution(string str,int strlen){
 int start =0; int end = strlen; int max=0;
 for(int i=start; i<end; i++){
  int right = i; int left = i; int count = 0;
  
  if(str[right] == '0'){
    max++;
    continue;
  } 
  while(left >= start && right <= strlen && str[left] == str[right]){
    count++;
    left--;
    right++;
  }
  
  if( count>0 && chk(str,left+1,right-1)){
    max++;
  }

  int s_right=i; int s_left=i+1; int s_count =0;
  
  while(s_left >= start && s_right <= strlen && str[s_left] == str[s_right]){
    s_count++; s_left--; s_right++;
  }
  if(s_count > 0 && chk(str,s_left+1,s_right-1)){
    max++;
  }

 }
 return max;
}
int main(){
  //cout<<int('9'-'0');
  string str; cin>>str;
  int strlen = str.length();
  cout<<solution(str,strlen);
  return 0;
}
