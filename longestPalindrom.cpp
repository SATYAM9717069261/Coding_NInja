#include<bits/stdc++.h>
using namespace std;
int longestPalindrom(string str, int strlen){
  int start = 0;
  int end = strlen;
  int max = 0;
  for(int i=0;i<end;i++){
    int left = i;
    int right = i;
    int count = 0;
    while( left >= start && right <= strlen && str[left] == str[right]){
        if(left == right)  
          count++;
        else
          count+=2;
        left--; right++; 
    } 
    
    if(max<count)
      max = count;
   
    left = i;
    right = i+1;
    count = 0;
    while(left >= start && right <= strlen && str[left] == str[right]){
        if(left == right)  
          count++;
        else
          count+=2;
        left--; right++;
    }
    
    if(max<count)
      max = count;
  }
  return max;
}
int main(){
    string str;cin>>str;
    int strLen = str.length();
    cout<<longestPalindrom(str,strLen)<<endl;
  return 0;
} 
