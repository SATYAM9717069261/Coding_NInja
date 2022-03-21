#include<bits/stdc++.h>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    for(int i=1;i<size;i++){
        if(input[i-1]>input[i]){
            return i;
        }
    }
    return 0;
}

int main(){
	int arr[]={10,20,30,1}
	cout<<arrayRotateCheck(arr,4);
	return 0;
}
