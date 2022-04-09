#include<bits/stdc++.h>
using namespace std;

long long merge(long long* arr,long long start,long long mid,long long end){
        long long temp[end-start+1];
        int i=start;
        int j=mid;
        int k=0;
    	long long result=0;
        while(i<mid && j<=end){
            	//cout<<arr[i] << " "<<arr[j]<<endl;
                if(arr[i] >= arr[j]){
                    	temp[k++]=arr[j++];
                }else{
                    	result+=(end-j+1)*arr[i];
                    	//cout<<" arr=>"<<((end-j+1))<< " "<<arr[i]<<endl;
                    	temp[k++]=arr[i++];
                }
        }
        while(j<=end){
                temp[k++]=arr[j++];
        }
        while(i<=mid){
                temp[k++]=arr[i++];
        }
        for(long long x=0,y=start;y<=end;x++,y++){
        arr[y]=temp[x];
    }
    	
    	return result;
}

long long mergesort(long long *arr,long long start,long long end){
    	long long result=0;
        if(start<end){
            long long mid=(start+end)/2;            
                long long right=mergesort(arr,start,mid);
                long long left=mergesort(arr,mid+1,end);
                long long ans=merge(arr,start,mid+1,end);
        		return right+left+ans;
        }
    return result;
}
int main(){
    	int test;
    cin>>test;
    	while(test--){
        	long long num;cin>>num;
        	long long arr[num];
        	for(long long i=0;i<num;i++)
            	    cin>>arr[i];
        	long long ans=mergesort(arr,0,num-1);
            cout<<ans<<endl;
        }
        return 0;
}
