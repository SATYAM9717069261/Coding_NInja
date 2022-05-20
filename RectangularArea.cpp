#include<bits/stdc++.h>
using namespace std;
bool condition(pair<int,int> first ,pair<int,int> second){
	if(first.first > second.first)
		return true;
	else
		return false;
}
int solution(vector<pair<int,int>> inp){
	sort(inp.begin(), inp.end(),condition);
	int max_y=0;
	int result=0;
	for(pair<int,int> i : inp){
		if(max_y<i.second){
			result+= (i.first * i.second );
			result-= (i.first * max_y);
			max_y = i.second;
		}
	}
	return result;
}
int main(){
	int test;cin>>test;
	vector<pair<int,int>> inp;
	while(test--){
		int x;cin>>x;
		int y;cin>>y;
		inp.push_back(make_pair(x,y));
	}
	cout<<solution(inp);
	return 0;
}
