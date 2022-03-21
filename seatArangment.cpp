#include<bits/stdc++.h>
using namespace std;
void print(vector<pair<int,char>> number,int num){
	for(int i=0;i<num*2;i++){
	       	cout<<"Arival=> "<< number[i].first<<" leave=> "<<number[i].second<<endl;
	}
}

int solution(int* arival,int* leave,int num){
	int seat=0;
	vector<pair<int,char>> number;
	for(int i=0;i<num;i++){
		number.push_back({arival[i],'a'});
		number.push_back({leave[i],'d'});
	}
	print(number,num);
	//sorting pending
	sort(number.begin(),number.end());
	int max_arival=0;
	for(int i=0;i<(num*2);i++){
		if(number[i].second == 'a'){
		       	max_arival++;
			if(seat<max_arival)
			       	seat=max_arival;
		}
		else max_arival--;
	}
	cout<<"<<<======================================= After =======================================>>>> "<<endl;
	print(number,num);
	return seat;
}

int main(){
	int num;
	cin>>num;
	int* arival=new int[num];
	int* leave=new int[num];
	for(int i=0;i<num;i++)	cin>>arival[i];
	for(int i=0;i<num;i++)	cin>>leave[i];
	cout<<solution(arival,leave,num);
	return 0;
}
