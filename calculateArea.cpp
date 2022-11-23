#include<bits/stdc++.h>
using namespace std;
class cordinate{ public : int x; int y; };
int solution(cordinate* arr, int size){
  int area = 0;
  for(int i=0;i<size-1;i++){
    area += (arr[i].x * arr[i+1].y) - (arr[i].y*arr[i+1].x) ;
  }
  area += (arr[size-1].x * arr[0].y) - (arr[size-1].y*arr[0].x);
  return abs(area/2);
}
int main(){
  int test;cin>>test;
  while(test--){
    int size;cin>>size;
    cordinate arr[size];
    for(int i=0;i<size;i++){
      int x; cin>>x;
      arr[i].x=x;
      int y; cin>>y;
      arr[i].y=y;
    }
    cout<<solution(arr,size)<<endl;
  }
 return 0;
}
