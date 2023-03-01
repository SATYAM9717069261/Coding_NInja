#include<bits/stdc++.h>
using namespace std;
class cust{
  public : int position,num;
};
bool fun(cust i, cust j){
  return i.num < j.num;
}

int main(){
  int test; cin>>test;
  while(test--){
    int size; cin>>size;
    int arr[2*size];
    cust so[2*size];
    for(int i=0;i<2*size;i++){
      int num; cin>>num;
      arr[i]= num;
      so[i].position = i;
      so[i].num = num;
    }
    sort(so,so+2*size,fun);
    //for(cust& i: so)
    //  cout<<"Postion => "<<i.position << " "<<i.num<<endl;
    int shift = 0;
    for(int i=0;i<size;i++){
      shift+=so[i].position - i;
    }
    cout<<shift<<endl;
  }
  return 0;
}
