#include<bits/stdc++.h>
using namespace std;
int solution(int *input, int n)
{
    int max=input[0];
    int second=-2147483648;
    for(int i=0;i<n;i++){
        if(second<input[i] && max !=input[i]){   
            second=input[i];
            if(second>max){
                int temp=second;
                second=max;
                max=temp;
            }
        }
    }
    return second;
}

int main(){
	int arr[]={2,13,4,1,3,28};
	cout<<solution(arr,6);
	return 0;
}
