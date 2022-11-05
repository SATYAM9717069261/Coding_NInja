/**
 * Working Only string coontain one center like aba, aabaa not working for two center = > abba
 * **/
#include<bits/stdc++.h>
using namespace std;
void printArr(int* arr, int size){
  cout<<"======================================================"<<endl;
  for(int i=0;i<size;i++){
    cout<<arr[i]<<"\t";
  }
  cout<<"======================================================"<<endl;
}
string manchaster(string str,int strlen){
  int num[strlen+1];
  memset(num,0,sizeof num);
  int center = 0;
  int left = -1;
  int right = 1;
  int count = 1;
  int index=0; int max=0;
  string ans="";
  // printArr(num,strlen+1);
  for(int i=0;i<=strlen;){
    center = i;
    while(left>=0 && right<=strlen && str[left] == str[right]){
      num[right]=num[left];
      left-- ;
      right++;
      count++;
    }
    num[center] = count;
    if(max<count){
      index=center;
      max=count;
    }
    int j=center +1;
    while(j<center+count+1 && (center+count+1)<=strlen){
      if(str[center] == str[j+num[j]]){
        i = j;
        break;
      }else{j++;}
    }
    //printArr(num,strlen+1);
    if(i == center){
      i=right;
      left= right-1;
      right++;
      count=1;
    }else{
      right = j+num[j]+1;
      left = j - (num[j]+1);
      count = num[j]+1;
    }
  }
  for(int i=(index-(max-1));i< (index+max);i++){
    ans+=str[i];
  }
  return ans;
}
int main(){
  string str;cin>>str;
  cout<<manchaster(str,str.length()-1);
  return 0;
}
