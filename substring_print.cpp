#include<bits/stdc++.h>
using namespace std;
void substr(string input,string output){
	if(input.length() == 0){
		cout<<output<<endl;
	}else{
		substr(input.substr(1),output);
		substr(input.substr(1),output+input[0]);
	}
}
int main(){
	string input;cin>>input;
	string result;
	substr(input,result);
	//cout<<input+1;
	return 0;
}
