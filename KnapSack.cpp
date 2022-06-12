#include<bits/stdc++.h>
using namespace std;

int solution(int weight[],int value[],int len, int maxWeight, vector<vector<int> >& arr){
	if(len < 0)
		return 0;
	if(arr[maxWeight][len] != -1){
		cout<<"arr=> "<<arr[maxWeight][len]<<endl;
		return arr[maxWeight][len];
	}
	int Inc=0;
	int NotInc=0;
	NotInc = solution(weight,value,len-1,maxWeight,arr);
	if((maxWeight - weight[len])>=0)
		Inc=value[len]+solution(weight,value,len-1,maxWeight - weight[len],arr);
	arr[maxWeight][len] = max(Inc,NotInc);
	cout<<"End => "<<arr[maxWeight][len]<<" len => "<<len <<" Weight=> "<<maxWeight<<endl;
	return arr[maxWeight][len];
}


int main(){
	int size;cin>>size;
	int weight[size];
	int value[size];
	for(int i=0 ;i<size;i++)
		cin>>weight[i];
	for(int i=0;i<size;i++)
		cin>>value[i];
	int maxWeight;cin>>maxWeight;
	vector<vector<int> > arr(maxWeight + 1, vector<int>(size + 1, -1));
	cout<<solution(weight,value,size,maxWeight,arr);
	return 0;
}
