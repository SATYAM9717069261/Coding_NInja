#include<bits/stdc++.h>
using namespace  std;
int solution(int* arr,int start,int end , int find){
	int mid=(start+end)/2;
	if(start == end) 	return -1;
	if(arr[mid]==find) 	return mid;
	if(arr[mid]>find)	return solution (arr,start,mid,find);
	if(arr[mid]<find)	return solution(arr,mid+1,end,find);

	return -1;
}
int main(){
	int arr[10]={1,2,3,4,5,6,7};
	int find=7;
	cout<<solution(arr,0,7,find);
	return 0;
}
