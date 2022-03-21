#include<bits/stdc++.h>
using namespace std;

void reverse(char* inp, int start,int end){
	int mid=start+(end-start)/2;
	//cout<<"Start=> "<<start<<"end=>"<<end<<" Mid=>"<<mid<<endl;
	for(int i=start,j=end;i<=mid;i++,j--){
		char temp=inp[i];
		inp[i]=inp[j];
		inp[j]=temp;
	}
	//cout<<"after Reverse=> "<<inp<<endl;
}

void solution(char inp[]){
	int start=0,end=strlen(inp);
	for(int i=0;i<end;i++){
		if(inp[i]==' '){
			reverse(inp,start,i-1);
			start=i+1;
		}
	}
	reverse(inp,start,end-1);
	reverse(inp,0,end-1);
}

int main(){
	char inp[100];
	cin.getline(inp,100,'\n');
	solution(inp);
	cout<<inp;
	return 0;
}
