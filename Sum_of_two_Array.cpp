#include<bits/stdc++.h>
using namespace std;

void solution(int* num1, int s1,int* num2, int s2, int* res, int s3){
	int carry=0;
	for(int i=(s1-1),j=(s2-1),k=s3-1;k>=0;k--){
		int result=num1[i]+num2[j]+carry;
		res[k]=result%10;
		carry=result/10;
		i--;j--;
		if(i<0){
			i=0;
			num1[0]=0;
		}
		if(j<0){
			j=0;
			num2[0]=0;
		}
	}
}
int main(){
	int num1[]={9,7,1,6};
	int num2[]={4,5,9};
	int output[5]={0};
	solution(num1,4,num2,3,output,5);
	for(int i: output) 
		cout<<i<<" ";
	return 0;
}	
