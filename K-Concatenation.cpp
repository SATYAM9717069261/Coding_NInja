#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solution(vector<int> arry,ll arrySize,ll repeat){
	for(auto i=arry.begin();i<arry.end();i++){
		cout<<i;
	}
	return repeat;
}

int main(){
	int test_case;
	while(test_case--){
		ll arrySize;
		ll repeat;
		vector <int> arry;
		int number;
		while(--arrySize){
			cin>>number;
			arry.push_back(number);
		}
		solution(arry,arrySize,repeat);
	}
	return 0;
}
	
