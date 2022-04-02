/**
 *	Merge Sort Require Extra Space 7 8 9	4 5  sort and store Result in Temp array  
 * **/
#include<bits/stdc++.h>
using namespace std;

void print(int* arr,int start, int num){
	for(int i=start;i<=num;i++){
		cout<<arr[i]<<" ";
	}
}

int merge(int* arr, int start, int mid , int end){
	int i=start, j= mid+1 , k=0;
	int* temp = new int[end-start];
	int count= 0;
	while(i <= mid && j <= end){
		if(arr[i] > arr[j]){
			temp[k++]=arr[j++];
			count+=mid-i+1;
		}else{
			temp[k++]=arr[i++];
		}
	}
	if(j > end){
		while(i<=mid)
			temp[k++]=arr[i++];
	}else{
		while(j<=end)
			temp[k++]=arr[j++];
	}
	for(int i= start,j=0;i<=end;i++)
		arr[i]=temp[j++];
	return count;
}
int solution(int* arr,int start,int end){
	int count=0;
	if(start < end){
		int mid=(end-start)/2;
		int left=solution(arr,start,start+mid);
		int right=solution(arr,start+mid+1,end);
		count= merge (arr,start,start+mid,end);
		return left+right+count;
	}
	return count;
}

int main(){
	int num;
	cin>>num;
	int* arr = new int[num];
	for(int i=0;i<num;i++)	
		cin>> arr[i];
	cout<< solution(arr,0,num-1);
	//print(arr,0,num-1);
	return 0;
}
