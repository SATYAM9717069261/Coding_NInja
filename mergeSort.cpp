#include<bits/stdc++.h>
using namespace std;

long long merge(long long A[],int left,int mid,int right){
        int i=left,j=mid,k=0;
        int temp[right-left+1];
        long long count = 0;
        while(i<mid && j<=right){
                if(A[i] <= A[j]){
                        temp[k++] = A[i++];
                }else{
                        temp[k++] = A[j++];
                        count += (mid - i);
                }
        }
        while(i<mid){
                temp[k++] = A[i++];
        }
        while(j<=right){
                temp[k++] = A[j++];
        }
        for(int i=left,k=0;i<=right;i++,k++){
                A[i] = temp[k];
        }
        return count;
}

long long merge_sort(long long A[],int left,int right){
        long long count = 0;
        if(right > left){ 
                int mid = (left + right)/2;
                count = merge_sort(A,left,mid);
                count += merge_sort(A,mid+1,right);
                count += merge(A,left,mid+1,right);
        }
        return count;
}
int main(){
    int test;cin>>test;
        while(test--){
        	int num;cin>>num;
        	long long arr[num];
        	for(int i=0;i<num;i++)
            	    cin>>arr[i];
        	merge_sort(arr,0,num-1);
        	for(int i=0;i<num;i++)
            	    cout<<arr[i]<<" ";
        	cout<<endl;
        }
        return 0;
}
