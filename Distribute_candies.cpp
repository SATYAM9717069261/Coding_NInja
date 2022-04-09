#include<bits/stdc++.h>
using namespace std;

bool distribution(int* arr, int num,int current,int stu){
	for(int i=0;i<num;i++){
		int res = arr[i] / current;
		stu-=res;
		if(stu<=0){
			return true;
		}
	}
	return false;
}


int solution(int* arr, int num,int stu){
	int max=arr[num-1];
	int current=max;
	int ans=0;
	while(ans< current){
		cout<<"Check=> "<<distribution(arr,num,current,stu)<< " check=> "<<current<<endl;
		if(distribution(arr,num,current,stu)){
			ans=current;
			cout<<"max=> "<<max<<" current=> "<<current<<" ans=> "<<ans<<endl;
			current=(max+current)/2;
		}else{
			max=current;
			current=(current+ans)/2;
		}
	}
	return ans;
}

int main(){
	int num;cin>>num;
	int stu;cin>>stu;
	int arr[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	sort(arr,arr+num);
	cout<<solution(arr,num,stu);	
	return 0;
}
