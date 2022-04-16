#include<bits/stdc++.h>
using namespace std;

void swap(int* arr, int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=arr[i];
}
void print(int* arr, int num){
	for(int i=0;i<num;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
bool solution(int* arr,int num){
	int i=0;
	int max=0;
	while(i<(num-1)){
		if(arr[i] > arr[i+1]){
			if(arr[i]-arr[i+1] == 1){
				swap(arr[i],arr[i+1]);
				print(arr,num);
				max=arr[i+1];		
			}else
				return false;
		}
		i++;
	}
	if(max<=arr[i])
		return true;
	else
		return false;
}

int main(){
	int num;cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	if(solution(arr,num)==1)
		cout<<"True";
	else
		cout<<"False";
	return 0;
}
