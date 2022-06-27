#include<bits/stdc++.h>
using namespace std;
int solution(int* arr, int arrStart, int arrEnd, int start, int end, int open, int close,int** dp){
  if(start == end){
    if(open == close+1 && arr[0] != end )
        return 1;
      else
        return 0;
  }
  if(dp[open][close] !=-1){
    return dp[open][close];
  }
  int result = 0;
  if(start == arr[0] && arrStart < arrEnd){
      result += solution(arr+1,arrStart+1,arrEnd,start+1,end,open+1,close,dp);
  }else{
    if(open == close){
        result+= solution(arr,arrStart,arrEnd,start+1,end,open+1,close,dp);
    }else{
        result+= solution(arr,arrStart,arrEnd,start+1,end,open,close+1,dp);
        result+= solution(arr,arrStart,arrEnd,start+1,end,open+1,close,dp);
    }
  }
  dp[open][close] = result;
  return result;
}
int main(){
    int test;cin>>test;
    while(test--){
      int size;cin>>size;
      int arrsize;cin>>arrsize;
      int arr[arrsize];
      for(int i=0;i<arrsize;i++)
        cin>>arr[i];
      int arrStart = 0;
      int arrEnd = arrsize;
      int start = 0;
      int end = (size*2);
      int open=0;
      int close =0;
      int **dp=new int* [2*size];
	    for(int i=0; i<(2*size); i++){
          dp[i]=new int [2*size];
          for(int j=0; j< (2*size); j++){
				  dp[i][j]=-1;
			  }
	    }
      cout<<solution(arr,arrStart,arrEnd,start+1,end,open,close,dp)<<endl;
    }
}

