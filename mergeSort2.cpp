#include<bits/stdc++.h>
using namespace std;

void merge(int* arr,int start,int mid,int end){
	int* temp = new int[end-start+1];
	int i=start;
	int j=mid;
	int k=0;
	while(i<mid && j<=end){
		if(arr[i] < arr[j])
			temp[k++]=arr[j++];
		else
			temp[k++]=arr[i++];
	}
	while(j<=end)
		temp[k++]=arr[j++];
	while(i<mid)
		temp[k++]=arr[i++];
	for(int i=start,k=0;i<=end;i++) 
		arr[i]=temp[k++];
}

void mergesort(int*arr,int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid+1,end);
	}
}

int main(){
	int num;cin>>num;
	int *arr=new int(num);
	for(int i=0;i<num;i++)
		cin>>arr[i];
	mergesort(arr,0,num-1);
	for(int i=0;i<num;i++)
		cout<<arr[i]<<" ";
	return 0;
}
