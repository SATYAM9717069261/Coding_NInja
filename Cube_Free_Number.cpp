#include<bits/stdc++.h>
#define MAX 1000005
#define int long long
using namespace std;
long long temp[MAX];
signed main(){
  memset(temp,0,sizeof(temp));
  temp[0] = 0;
  temp[1] = 1;
  long long count =2;
  for(long long i=2;i<100;i++){
 	if(temp[i]==0){
    	int cube = i*i*i;
    	for(int k = 1; k < MAX; k++){
        	  if(k*cube > MAX)
           			break;
          		temp[k*cube] = -1;
      		}
    	}
    }
  
	for(int i =2; i < MAX; i++){
        if(temp[i]!=-1){
            temp[i] = count;
            count++;
        }
    }
  int test;cin>>test;
  while(test--){
    long long num;cin>>num;
    if(temp[num]!=-1)
      cout<<temp[num]<<endl;
    else
      cout<<"Not Cube Free"<<endl;
  }
  return 0;
}
