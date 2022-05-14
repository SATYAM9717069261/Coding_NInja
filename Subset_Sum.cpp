#include<bits/stdc++.h>
using namespace std;
int solution(int arr[],int num,int arr_size,int sum=0){
	if (arr_size == 0) {
        if (sum == num) {
	        return 1;
        } else return 0;
	}
    int left = solution(arr+1,num,arr_size-1,sum+arr[0]);
	int right = solution(arr+1,num,arr_size-1,sum);
	return left+right;
}
int main(){
    int test;cin>>test;
    while(test--){
        int arr_size;cin>>arr_size;
        int num;cin>>num;
        int arr[arr_size];
        for(int i=0;i<arr_size;i++)
            cin>>arr[i];
        cout<<solution(arr,num,arr_size)<<endl;
    }
	return 0;
}
