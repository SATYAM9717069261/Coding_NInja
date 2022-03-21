#include<bits/stdc++.h>
using namespace std;

void solution(int* arr, int size){
	int start =0;
	int end =size-1;
	for(int i=0;i<=end;i++){
		if(arr[i] == 0){
			int temp=arr[start];
			arr[start]=arr[i];
			arr[i]=temp;
			start++;
			if(arr[i] == 2){
                        	int temp=arr[end];
                        	arr[end]=arr[i];
                        	arr[i]=temp;
                        	end--;
			}
		}
		if(arr[i] == 2){
			int temp=arr[end];
			arr[end]=arr[i];
			arr[i]=temp;
			end--;
			if(arr[i] == 0){
                        	int temp=arr[start];
                        	arr[start]=arr[i];
                        	arr[i]=temp;
                        	start++;
                	}
		}
	}
}

int main(){
	int arr[]={2,2,1,1,2,1,0,0,1,2,2};
	solution(arr, 11);
	for(int i: arr)
		cout << i<<" ";
	return 0;
}
