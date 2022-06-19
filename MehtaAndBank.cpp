#include<bits/stdc++.h>
using namespace std;
void print(int* arr,int size){
	for(int i=0;i<size;i++)
		cout<<arr[i]<<endl;
}
bool cond(int a ,int b){
  if(a>b) 
    return true;
  else
    return false;
}
pair<int,int> solution(pair<int,int>* arr, int size, int MaxWeight,int* selection){
	if(size < 0 || (MaxWeight - arr[size].second ) < 0 ){
		return make_pair(0,0);	
  }
  if( (MaxWeight - arr[size].second ) == 0 )
      return arr[size];
	pair<int,int> with = solution(arr,size-1,MaxWeight-arr[size].second,selection);
  with.first += arr[size].first;
  with.second += arr[size].second;
	pair<int,int> without =  solution(arr,size-1,MaxWeight,selection);
	if(with.first > without.first){
    selection[size]=arr[size].first;
		return with;
  }
	else
		return without;
}

int main(){
	int size;cin>>size;
	int maxWeight;cin>>maxWeight;
	pair<int,int> arr[size]; //<profit,weight>
	for(int i=0;i<size;i++){
		int in;cin>>in;
		arr[i] = make_pair(in,0);
	}
	for(int i=0;i<size;i++){
		int in;cin>>in;
		arr[i] = make_pair(arr[i].first,in);
	}
	//print(arr, size);
	int selection[size];
  for(int i=0;i<size;i++)
    selection[i]=-1;
  pair<int,int> result = solution(arr,size-1,maxWeight,selection);
	cout<<result.first << " " << result.second<<endl; 
	print(selection, size);
  sort(selection,selection + size,cond);
	print(selection, size);
  return 0;
}
