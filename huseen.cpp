#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int max_reach=0;

int solution(ll *arry,int n,int question){
	int result=0;
	while(question--){
		sort(arry,arry+n+1);
		if(arry[n]==1) {
			max_reach=1;
			return 1;
		}	
		result=arry[n];
		arry[n]=arry[n]/2;
	}
	return result;
}

int main(){
	int n,m;
	cin>>n>>m;
	ll arry[n];
	for(int i=0;i<n;i++) cin>>arry[i];
	int question;
	int lastquestion=0;
	sort(arry, arry + n);
	while(m--){
		cin>>question;
		if(max_reach==0) cout<<solution(arry,n-1,question-lastquestion);
		else cout<<1;
		lastquestion=question;
	}
	return 0;
}
