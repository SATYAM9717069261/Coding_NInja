#include<bits/stdc++.h>
using namespace std;
struct arr{
  char x;
  int last_occur;
};
void print(arr* string, int datalen){
  for(int i=0;i<datalen;i++){
    cout<<"Char => "<<string[i].x<<" Position => "<<string[i].last_occur<<endl;
  }
}
void solution(string str1,arr* stringPreprocess, int str1len){
  int i=1; int j=0;
  while(j)
}

void preprocess(string data, arr* stringPreprocess , int datalen){
  int i=1;
  int j=0;
  stringPreprocess[0].x=' ';
  stringPreprocess[0].last_occur = 0;
  stringPreprocess[j+1].x = data[j];
  stringPreprocess[j+1].last_occur = j;
  while(i<datalen){
    stringPreprocess[i+1].x = data[i]; 
    if(data[j] == data[i]){
      stringPreprocess[i+1].last_occur= j+1;
      j++;
    }else{
      j=(stringPreprocess[j].last_occur+1);
      while(j >= 0){
        if(j == 0){
          stringPreprocess[i+1].last_occur = stringPreprocess[j].last_occur;
          break;
        }
        if(stringPreprocess[j].x == data[i]){
          stringPreprocess[i+1].last_occur = j;
          break;
        }else{
          j--;
        }
      }
    }
    i++;
  };
  //print(stringPreprocess,datalen);
}

int main(){
  int test;cin>>test;
  while(test--){
    string pattern;cin>>pattern;
    string str;cin>>str;
    arr stringPreprocess[pattern.length()+1];
    preprocess(pattern,stringPreprocess,pattern.length()+1);
  }
  return 0;
}
