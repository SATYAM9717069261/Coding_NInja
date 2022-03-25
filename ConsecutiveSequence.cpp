#include<bits/stdc++.h>
using namespace std;

void print(set<int> data){
	for(int i:data)
		cout<<i<<" ";
}

void solution(int* arr,int num){
	set<int> inp;
	map<int,int> position;
	for(int i=0;i<num;i++){
		inp.insert(arr[i]);
		position.insert(make_pair(arr[i],i));
	}
	//print(inp);
	int start=*inp.begin(),end =*inp.begin();
	int final_start=start,final_end=end;
	int  max=1;
	int count=1;
	for(int i:inp){
		if(end+1 == i){
			count++;
			end=i;
		}else{
			if(max<=count){
				if(max == count){
					final_start = position[final_start] < position[start] ? final_start:start;
					final_end = position[final_start] < position[start] ? final_end:end;
				}else{
					final_start=start;
					final_end=end;
				}
				max=count;
			}
			end=i;
			count=1;
			start=i;
		}
	}
	if(max<=count){
		if(max == count){
			final_start = position[final_start] < position[start] ? final_start:start;
                        final_end = position[final_start] < position[start] ? final_end:end;
		}else{
			final_start=start;
			final_end=end;
		}
	}
	cout<<final_start<<" "<<final_end<<" ";
	//print(inp);
}

int main(){
	int num;
	cin>>num;
	int* arr=new int[num];
	for(int i=0;i<num;i++){
		cin>>arr[i];
	}
	solution(arr,num);
	return 0;
}
