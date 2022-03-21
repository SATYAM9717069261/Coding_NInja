#include<bits/stdc++.h>
using namespace std;

int solution(int arr[],int size,int num,int result[],int m=0){
	if(size==0)	return 0;
	m=solution(arr,size-1,num,result,m);
	if(arr[size-1]==num){
		result[m]=size-1;
		return m+1;
	}else{
		return m;
	}
}

int main(){
	int arraySize=10;
	int result[10];
	int arry[10]={1,2,1,2,1,2,1,2,1,2};
	//for(int i=0;i<arraySize;i++)
	//	cout<<arry[i]<<endl;
	for(int i=0;i<solution(arry,arraySize,2,result);i++)
		cout<<result[i]<<endl;
	return 0;
}
