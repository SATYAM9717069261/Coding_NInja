#include<bits/stdc++.h>
using namespace std;
void shift(int* arr,int start,int end){
    int val=arr[start];
    for(int i=start;i<end-1;i++){
        arr[i]=arr[i+1];
    }
    arr[end-1]=val;
}
void pushZeroesEnd(int *input, int size)
{
    int no_of_zero=0;
    for(int i=0;i<size-no_of_zero;){
        if(input[i]==0){
	    //cout<<"found=> "<< i<< size <<"";
            shift(input,i,size);
            no_of_zero++;
        }else i++;
    }
}
int main(){
	int arr[]={2,6,0,0,1,9,0,8,0};
	pushZeroesEnd(arr,9);
	//shift(arr,4,7);
	for(int i:arr) cout << i<<" ";
}
