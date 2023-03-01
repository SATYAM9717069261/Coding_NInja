#include<bits/stdc++.h>
using namespace std;
int sol(int a[], int b[], int size, int min){
  int temp[size];
  for(int i=0;i<size;i++){
    int a_sub = a[i]-min;
    int b_sub = b[i]-min;
    if(b_sub < a_sub && b_sub > -1){
      temp[i] = b[i];
    }else{
      temp[i] = a[i];
    } 
  }
  return *max_element(temp, temp + size) - *min_element(temp, temp + size);
}
int solution(int a[], int b[], int size, int max){
  int temp[size];
  for(int i=0;i<size;i++){
    int a_sub = max - a[i];
    int b_sub = max - b[i];
    if(b_sub < a_sub && b_sub > -1){
      temp[i] = b[i];
    }else{
      temp[i] = a[i];
    }
  }
  return *max_element(temp, temp + size) - *min_element(temp, temp + size);
}
int main(){
  int test; cin>>test;
  while(test--){
    int size; cin>>size;
    int a[size];
    int b[size];
    for(int& i: a)
      cin>>i;
    for(int& i: b)
      cin>>i;
    int max_a = *max_element(a, a + size);
    int max_b = *max_element(b, b + size);
    int min_a = *min_element(a, a+size);
    int min_b = *min_element(b, b+size);
    int first,second;
    if(max_a < max_b){
      first = solution(a,b,size,max_a);
    }else{
      first = solution(b,a,size,max_b);
    }
    
    if(min_a < min_b){
      second = sol(a,b,size,min_a);
    }else{
      second = sol(b,a,size,min_b);
    }
    cout<<"Max => "<< min({first,second});
  }
  return 0;
}
