#include<bits/stdc++.h>
using namespace std;
string solution(string inp){
	int arr[58]={0};
	for(char i:inp)
		arr[i-65]=1;
	string result="";
	for(int i=0;i<58;i++){
		if(arr[i]!=0)
			cout<<char(i+65);
	}
	return result;
}

int main(){
	string inp;
	cin>>inp;
	cout<<solution(inp);
	return 0;
}
