#include<bits/stdc++.h>
using namespace std;
void solution(vector<int>& a,int size ){
  int min_ans = INT_MAX;
  for(int i=0;i<=size;i++){
     min_ans = min({min_ans, max(a[i],a[i+size-1]) - min(a[i],a[i+size-1]) });
  }
  cout<<min_ans;
}
bool fun(int x, int y){
  return x>y;
}
int main(){
  int test; cin>>test;
  while(test--){
    int size; cin>>size;
    vector<int> a(2*size);
    for(int& i: a)
      cin>>i;
    sort(a.begin(), a.end());
    solution(a,size);
    cout<<endl;
  }
  return 0;
}
