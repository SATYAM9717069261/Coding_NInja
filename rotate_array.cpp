#include<bits/stdc++.h>
using namespace std;

void rotate(int *input, int d, int n)
{
    int temp[d];
    int i=0;
    for(int j=n;j<d;j++){
        temp[i++]=input[j];
    }
    for(int k=0;k<n;k++){
        temp[i++]=input[k];
    }
    int k=0;
    for(int i:temp)
        input[k++]=i; 
}


int main()
{
	int input[]={1,2,3,4,5,6,7};
	int shift=2;
	rotate(input,7,shift);
	for(int i:input) cout<<i<<" ";
	return 0;
}
