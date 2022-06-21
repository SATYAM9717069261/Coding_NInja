#include<bits/stdc++.h>
using namespace std;

int solution(int* arr, int start,int end,bool status , int trans,int** result){
  if(start > end || trans < 0) 
    return 0;
  /**if(result[status][start]!=-1  ){
    return result[status][start];
  }**/
  int skip = solution(arr+1,start+1,end,status,trans,result);
  int profit= 0;
  if(status == 0){
    if(trans > 0){
      profit = solution(arr+1,start+1,end,1,trans,result) - arr[0];
        result[status][start]=max(skip,profit);
      return result[status][start];
    }
  }else{
    profit = solution(arr+1,start+1,end,0,trans-1,result)+arr[0];
    result[status][start]=max(skip,profit);
    return result[status][start];
  }
  result[status][start]=max(skip,profit);
  return result[status][start];
}


int main(){
  int maxtrade;cin>>maxtrade;
  int size;cin>>size;
  int arr[size];
  for(int i=0;i<size;i++)
    cin>>arr[i];
  int** result=new int*[2];
  result[0] = new int[size];
  result[1] = new int[size];

  for(int i=0;i<=size;i++){
    result[0][i]=-1;
    result[1][i]=-1;
  }
  
  cout<<solution(arr,0,size-1,0,maxtrade,result);
  return 0;
}
