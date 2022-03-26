// x+y = find - z use this equation and try t find x and y 
#include<bits/stdc++.h>
using namespace std;

void solution(int* arr,int num,int find){
	sort(arr,arr+num);
	int a,b,c;
	int count=0;
	for(int i=0;i<num-1;i++){
		int z=find-arr[i];
		int front=1;
		int end=num-1;
		int x=arr[front],y=arr[end];
		while(front!=end){
			if(x>z)	
				break;
			if( (x+y) == z){
				if(i!=front && i!=end)
					count++;
				cout<<"Found +> "<<x<<" "<<" "<<y <<" i=>"<<i<<" front=>"<<front<<" End=> "<<end <<endl;
				front++;
			}
			if( (x+y) > z)
				end--;
			if( (x+y) < z)
				front++;
			x=arr[front];
			y=arr[end];
		}
	}
	cout<<"Count ======================> "<<count;
}

int main(){
	int num ;
	cin>>num;
	int* arr =new int[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	int find;cin>>find;
	solution(arr,num,find);		
	return 0;
}
