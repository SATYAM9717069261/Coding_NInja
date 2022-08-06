#include<bits/stdc++.h>
#define limit 100000000
using namespace std;
long long phi[limit];

void PreCompute_eulerPhi(long long n){
	for(long long i=1;i<=n;i++){
		phi[i] = i;
	}
	for(int i=2;i<=n;i++){
		if(phi[i] == i){
			phi[i] = i-1;
			for(long long j=2*i;j<=n;j+=i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}
}
int main(){
  int test;cin>>test;
  PreCompute_eulerPhi(limit);
  while(test--){
    long long num;cin>>num;
    cout<<phi[num]<<endl;
  }
  return 0;
}
