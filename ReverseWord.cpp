#include<bits/stdc++.h>
using namespace std;

void solution(char inp[]){
	string data;
	for(int i=strlen(inp)-1;i>=0;i--){
		if(inp[i] == ' '){
			reverse(data.begin(), data.end());
			cout<<data<<" ";
			data="";
		}else{
		       	data+=inp[i];
		}
	//	cout<<"Read Char=> "<<inp[i]<<endl;
	}
	reverse(data.begin(), data.end());
	cout<<data;
}

int main(){
	char inp[100];
	cin.getline(inp,100,'\n');
	solution(inp);
	return 0;
}
