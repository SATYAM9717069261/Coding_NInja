#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a]=arr[b];
	arr[b]=temp; 
}
void print(int arr[],int num){
	for(int i=0;i<num;i++)
		cout<<arr[i]<<" ";;
	cout<<endl;
}
int length(int arr[]){
	if(arr[0]=='\0')
		return 0;
	int len=length(arr+1);
	return 1+len;
}
void quickSort(int arr[],int num){
	if(length(arr) > 1){
		int x=arr[0];
		int countLesser=0;
		for(int i=1;i<num;i++){
			if(arr[0]>arr[i])
				countLesser++;
		}
		cout<<"countLesser= >"<<countLesser << "arr=> "<<arr[countLesser]<<endl;
		//swap
		swap(arr,0,countLesser);
		print(arr,num);
		cout<<"after Swap= >"<<arr[0]<<" "<<arr[countLesser]<<endl;
		int start=0;int end=num-1;
		do{
			cout<<" Before start=> "<<arr[start]<<"selected=> "<<arr[countLesser] <<"End=> "<<arr[end]<<endl;
			if(arr[start]>arr[countLesser] &&  arr[countLesser]>arr[end]){
				swap(arr,start,end);
				print(arr,num);
				start++;
				end--;
			}else{
				if(arr[start] < arr[countLesser])
					start++;
				if(arr[end] > arr[countLesser])
					end--;
			}
			cout<<" After start=> "<<arr[start]<<"selected=> "<<arr[countLesser] <<"End=> "<<arr[end]<<"Start=> "<<start<<"end=> "<<end<<"Cunt=> "<<countLesser<<endl;
		}while(start<countLesser && countLesser < end);
		quickSort(arr,countLesser-1); //rightSide
		quickSort(arr+countLesser+1,num); //left side
	}
}

int main(){
	int num;cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	quickSort(arr,num);
	//swap(arr[0],arr[1]);
	return 0;
}
