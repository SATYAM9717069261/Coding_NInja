#include<bits/stdc++.h>
using namespace std;

void insert(string a,map<string,int>& names){
	if(names[a]==0){
		names[a]=1;
         }else{
                names[a]+=1;
         }
       //cout<<names[a]<<"Find ";
}
void solution(char* input){
        map<string,int> names;
	int i=0;
	string current="";
	while(input[i]!='\0'){
		if(input[i]==' '){
			insert(current,names);
			current="";
		}
		else
			current+=input[i];
		i++;
	}
	insert(current,names);

       	for(pair<string,int> i:names) {
		if(i.second !=1)
                	cout<<i.first<<" "<<i.second<<" ";
        }

}

int main(){
	char inp[100000];
	cin.getline(inp,100000,'\n');
	solution(inp);
	return 0;
}
