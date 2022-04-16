#include<bits/stdc++.h>
using namespace std;

char* replace(char inp[]){
        if(inp[0] != '\0'){
                if(inp[0] == inp[1]){
                        //shift all element
			int i=0; 
			for(; inp[i]!='\0';i++){
				inp[i]=inp[i+1];
			}
			inp[i]='\0';
			replace(inp);  //test case tttttt
		}
                replace(inp+1);
        }
        return inp;
}

int main(){
        char inp[100];cin>>inp;
        cout<<replace(inp);
        return 0;
}
