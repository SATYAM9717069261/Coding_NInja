#include<bits/stdc++.h>
using namespace std;
struct data{
  int start;
  int end;
  int value;
  int profit;
};
bool fun(data a, data b){
  return a.end < b.end;
}

int solution(data arr[],int current, int end){
  if(arr[current].profit != -1)
    return arr[current].profit;

  if(current  == end){
    arr[current].profit=max(arr[current].value,arr[current].profit);
    return arr[current].value;
  }

  int f_end = arr[current].end;
  int Currentprofit = 0;
  for(int i=current;i<=end;i++){
    if(f_end <= arr[i].start){
        Currentprofit  = solution(arr,i,end);
      if(arr[current].value + Currentprofit > arr[current].profit) 
        arr[current].profit = arr[current].value + Currentprofit;
      return max(arr[current].value,arr[current].profit);
    }
  }
  arr[current].profit=max(arr[current].value,arr[current].profit);
  return arr[current].profit;
}

int main(){
  int size;cin>>size;
  data arr[size];
  for(int i=0;i<size;i++){
    cin>>arr[i].start;
    cin>>arr[i].end;
    cin>>arr[i].value;
    arr[i].profit = -1;
  }
  sort(arr,arr+size,fun);
  int maxProfit = 0;
  for(int i=0;i<size;i++){
    if(arr[i].profit == -1){
      int temp =solution(arr,i,size-1);
      if(temp>maxProfit){
        maxProfit = temp;
      }
    }else{ 
      if(arr[i].profit>maxProfit)
        maxProfit = arr[i].profit;
    }
  }
  cout<<"Max profit => "<<maxProfit;
  return 0;
}
