/**
IN Coding ninjas try this test case
Test Case +> 1
	1 0
	0
Expected Ouput => 2
Actual Output => 1
**/
#include<bits/stdc++.h>
using namespace std;
int solution(int arr[],int num,int arr_size,int sum=0){
	if(sum > num)
		return 0;
	if(sum == num )
		return 1;
	int left=0;
	int right =0;
	if(arr_size!=0){
		left = solution(arr+1,num,arr_size-1,sum+arr[0]);
		right = solution(arr+1,num,arr_size-1,sum);
	}else
		return 0;
	return left+right;
}
int main(){
	int arr_size;cin>>arr_size;
	int num;cin>>num;
	int arr[arr_size];
	for(int i=0;i<arr_size;i++)
		cin>>arr[i];
	cout<<solution(arr,num,arr_size);
	return 0;
}
