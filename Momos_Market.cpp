#include<bits/stdc++.h>
using namespace std;

void solution(int nshop,int* shop, int nday, int* day){
	for(int i=0;i<nday;i++){
		int momo=0;
		for(int j=0;j<nshop;j++){
			if(shop[j]<=day[i]){
				day[i]-=shop[j];
				momo++;
			}else
				break;
		}
		cout<<"momo=> "<<momo<<" remain money=> "<<day[i];
	}	
}

int main(){
	int nshop;cin>>nshop;
	int shop[nshop];
	for(int i=0;i<nshop;i++)
		cin>>shop[i];
	int nday;cin>>nday;
	int day[nday];
	for(int i=0;i<nday;i++)
		cin>>day[i];
	solution(nshop,shop,nday,day);
	return 0;
}
