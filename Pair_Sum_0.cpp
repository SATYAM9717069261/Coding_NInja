#include<bits/stdc++.h>
using namespace std;
int per(int num){
	int temp=0;
	for(int i=num-1;i>0;i--)
		temp+=i;
	return temp;
}
void print(map<int,int> data){
	for(auto i :data)
		cout<<i.first<<" "<<i.second<<endl;
}
int solution(int* arr,int num){
	map<int,int> data;
	for(int i=0;i<num;i++){
		if(data.find(arr[i])!=data.end())
			data[arr[i]]++;
		else
			data.insert(make_pair(arr[i],1));
	}
	int result=0;
	for(auto i:data){
		cout<<"<<<<======Before Operation=========>\n";
		print(data);
		if(i.first == 0 ){
			result+=per(i.second);
			data[i.first]=-1;
		}
		if(i.second == -1) continue;
		else{
			int temp=0;
			if (data.find(-1*i.first)!=data.end() && data[-1*i.first] != -1){
				temp=data[i.first]*data[-1*i.first];
				data[-1*i.first]=-1;
				data[i.first]=-1;
			}
			result+=temp;
		}
		cout<<">>>>>>>After <<<<<<<<<<<<<<<<"<<result<<endl;
		print(data);
	}	
	return result;
}
int main(){
	int num;
	cin>>num;
	int *arr=new int[num];
	for(int i=0;i<num;i++) cin>>arr[i];
	cout<<solution(arr,num);
	return 0;
}
