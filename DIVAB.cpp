#include<bits/stdc++.h>
#define long long int
using namespace std;
int solution(int like,int unlike,int limit){
  if(like%unlike == 0 )
    return -1;
  int start = (limit/like)*like;
  while(true){
    if( (start%like == 0) && (start%unlike !=0) && limit<=start)
      return start;
    if(start >= 1000000009)
      return -1;
    start+=like;
  }
}
int main(){
  int test;cin>>test;
  while(test--){
    int like;cin>>like;
    int unlike;cin>>unlike;
    int limit;cin>>limit;
    cout<<solution(like,unlike,limit)<<endl;
  }
}
