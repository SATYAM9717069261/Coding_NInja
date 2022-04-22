#include<bits/stdc++.h>
using namespace std;
void substr(int num,string keypad[],string result=""){
	if(num==0)
		cout<<result<<endl;
	else{
		string current=keypad[num%10];
		for(int i=0;i<current.length();i++){
			substr(num/10,keypad,result+current[i]);
		}
	}
}

int main(){
	string keypad[10]={" ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int num;cin>>num;
	substr(num,keypad);
	return 0;
}
