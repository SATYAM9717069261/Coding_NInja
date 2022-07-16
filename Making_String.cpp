//Add sp[aN][bN][cN]
#include<bits/stdc++.h>
using namespace std;
int solution(char* a,char* b,char* c,int aN,int bN,int cN){
  if(cN==0 && (c[cN]==a[aN] || c[cN] == b[bN]))
    return 1;
  if(aN==-1||bN==-1)
    return 0;
  int count =0;
  for(int i=0;a[i]!='\0';i++){
    if(a[i] == c[0])
      count += solution(a+i+1,b,c+1,aN-i-1,bN,cN-1);
  }
  for(int i=0;b[i]!='\0';i++){
    if(b[i]==c[0])
      count += solution(a,b+i+1,c+1,aN,bN-i-1,cN-1);
  }
  return count;
}
int main(){
 char A[50],B[50],C[50];
 cin>>A>>B>>C;
 cout<<solution(A,B,C,strlen(A),strlen(B),strlen(C));
 return 0;
}
