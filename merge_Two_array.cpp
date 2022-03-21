#include<bits/stdc++.h>
using namespace std;

void solution(int* arr1,int siz1,int* arr2,int siz2,int* arr3,int siz3){
	bool finish=siz1==0 || siz2==0 ? 1:0;
	for(int i=0,j=0,k=0;k<siz3;k++){
		if(finish!=1){
			if(arr1[i] < arr2[j]){
				arr3[k]=arr1[i++];	
				i<siz1?i:finish=1;
			}else{
				arr3[k]=arr2[j++];	
				j<siz2?j:finish=1;
			}
		}else	arr3[k]= (i>=siz1?arr2[j++]:arr1[i++]);
	}
	
}
int main(){
	int arr1[]={1,9,10,12};
	int arr2[]={2,5,6,20,40};
	int arr3[9];
	solution(arr1,4,arr2,5,arr3,9);
	for(int i:arr3) cout<<i<<" ";
	return 0;
}
