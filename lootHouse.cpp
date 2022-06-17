#include<bits/stdc++.h>
using namespace std;
int solution(int* arr, int size,int* maxa){
	if(size < 0 )
		return 0;
	if(maxa[size]!=-1)
		return maxa[size];
	int last = solution(arr,size-2,maxa) + arr[size];
	int lastSec = solution(arr,size-1,maxa);
	maxa[size]= max(last,lastSec);
	return maxa[size];	
}
int main(){
	int size;cin>>size;
	int arr[size];
	int maxa[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];
	for(int i=0;i<size;i++)
		maxa[i]=-1;
	cout<<solution(arr,size-1,maxa);
	return 0;
}
