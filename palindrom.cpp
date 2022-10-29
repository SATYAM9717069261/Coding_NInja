#include<bits/stdc++.h>
using namespace std;
void longestPalindrom(int* arr, string str, int strlen){
  int start = 0;
  int end = strlen;
  for(int i=0;i<end;i++){
    int left = i;
    int right = i;
    int count = 0;
    int max = 0;
    while( left >= start && right <= strlen && str[left] == str[right]){
        if(left == right)
          count++;
        else
          count+=2;
        left--; right++; 
    }
    if(max < count) 
      max=count;
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
    if(max < count)
      max=count;
    arr[i] = max;
  }
}
int main(){
  string str;cin>>str;
  int strLen = str.length();
  int* arr = new int[strLen];
  longestPalindrom(arr,str,strLen);
  for(int i = 0;i<strLen;i++)
    cout<<" = >"<<arr[i]<<endl;
  return 0;
} 
