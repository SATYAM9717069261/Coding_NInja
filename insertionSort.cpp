#include<bits/stdc++.h>
using namespace std;

void solution(int* arr, int size){
	for(int i=1;i<size;i++){
		int j;
		int current=arr[i];
		for(j=i-1;i>=0;j--){
			if(current>arr[j])	arr[j+1]=arr[j];
			else	break;
		}
		arr[j+1]=current;
	}
}

int main(){
	int arr[6]={10,5,1,4,3,9};
	solution(arr,6);
	for(int i:arr)
		cout<<i<<" ";
	return 0;
}
