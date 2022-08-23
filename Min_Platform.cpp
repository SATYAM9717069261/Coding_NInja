#include<bits/stdc++.h>
using namespace std;
struct data{
  int start,end;
};
bool fun(data a, data b){
  return a.end < b.end;
}
void print(data arr[],int size){
  for(int i=0;i<size;i++)
    cout<<" => "<<arr[i].start<<" "<<arr[i].end<<endl;
}
int solution(int arival[],int depat[],int size){
  data arr[size];
  for(int i=0;i<size;i++){
    arr[i].start = arival[i];
    arr[i].end = depat[i];
  }
  sort(arr,arr+size,fun);
  int station = 1;
  //print(arr,size);
  int i=0, j=1;
  while(i<size && j<size){
    if(arr[i].end <  arr[j].start){
      i++;j++;
    }else{
      j++;
      station++;
    }
  }

  cout<<" =========== End ==============="<<endl;
  return station;
}

int main(){
 int test;cin>>test;
 while(test--){
  int size;cin>>size;
  int arival[size];
  int depat[size];
  for(int i=0;i<size;i++)
    cin>>arival[i];
  for(int i=0;i<size;i++)
    cin>>depat[i];
  cout<<solution(arival,depat,size)<<endl;
 }
}
