#include<bits/stdc++.h>
using namespace std;
void print(int size, int** arr){
  for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
  }
}

void solution(int size,int** arr){
  int maxProfit = 0;
  pair<int,int>* selection = new pair<int,int>[size*size];
  int count = 0;
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      int top_left = INT_MAX;
      int top= INT_MAX;
      int top_right = INT_MAX;
      int bottom_left = INT_MAX;
      int bottom = INT_MAX;
      int bottom_right = INT_MAX;
      int right = INT_MAX;
      int left = INT_MAX;
      
      if( (i-1)>=0 && (j-1)>=0 )
        top_left = arr[i-1][j-1];
      if( (j-1)>=0 )
        top = arr[i][j-1];
      if( (i+1)<size && (j-1) >=0 )
        top_right = arr[i+1][j-1];
      if((i-1)>=0 && (j+1)<size)
        bottom_left = arr[i-1][j+1];
      if( (j+1)<size )
        bottom = arr[i][j+1];
      if( (i+1)<size && (j+1)< size)
        bottom_right = arr[i+1][j+1];
      if( (i-1) >= 0)
        right = arr[i-1][j];
      if( (i+1) < size)
        left = arr[i+1][j];

      int compute = min({top_right,top,top_left,bottom_right,bottom,bottom_left,right,left});
      if(maxProfit < compute ){
        maxProfit = compute;
        count = 0;
        selection[count++] = make_pair(i,j);
      }else{
        if(maxProfit == compute){
          selection[count++] = make_pair(i,j);
        }
      }
    }
    //cout<<"Output => "<<selection;
  }
  
  for(int i=0;i<count;i++)
    cout<<selection[i].first<<"#"<<selection[i].second;

}

void splitStore(string inp,int* arr){
  string num="";
  int index=0;
  for(int i=0; i<inp.length();i++){
    if(inp[i] == '#'){
      arr[index++] = stoi(num);
      num="";
    }else{
      num+=inp[i];
    }
  }
  arr[index] = stoi(num);
}
int main(){
  int size; cin>>size;
  int **arr= new int*[size];
  for(int i=0;i<size;i++){
    arr[i] = new int[size];
    string inp; cin>>inp;
    splitStore(inp,arr[i]);
  }
  print(size,arr);
  solution(size,arr);
  return 0;
}
