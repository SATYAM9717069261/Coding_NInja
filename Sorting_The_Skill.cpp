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
}
bool solution(int* arr,int num){
	//sort(temp,temp+num);
	int i=0;
	while(i<num){
		cout<<"Inside => "<<arr[i];
		if(arr[i] > arr[i+1]){
			
			if(arr[i+1] - arr[i] == 1){
				swap(arr,i+1,i);
				print(arr,num);
				i+=2;
			}else
				return false;
		}else{
			i+=1;
		}
	}
	return true;
}

int main(){
	int num;cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	cout<<solution(arr,num);
	return 0;
}
