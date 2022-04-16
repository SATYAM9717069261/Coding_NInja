#include<bits/stdc++.h>
using namespace std;

char* replace(char inp[],char x,char y){
	if(inp[0] != '\0'){
		if(inp[0] == x)
			inp[0] = y;
		replace(inp+1,x,y);
	}
	return inp;
}

int main(){
	char inp[100];cin>>inp;
	char x;cin>>x;
	char y;cin>>y;
	cout<<replace(inp,x,y);
	return 0;
}
