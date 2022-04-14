#include<bits/stdc++.h>
using namespace std;
int solution(long* arr,int num){
        long finalStart=999999999;
        long gateNumber=-1;
        for(int i=0;i<num;i++){
                int start=0;
            	if((arr[i]-i)%num == 0)
			start=(arr[i]-i)/num;
        	else if(arr[i]-i<0)
            		start=0;
		else
			start=((arr[i]-i)/num)+1;
                if(finalStart > start){
                        finalStart=start;
                        gateNumber=i;
                }
        }
        return gateNumber+1;
}


int main(){
        int num;cin>>num;
        long arr[num];
        for(int i=0;i<num;i++)
                cin>>arr[i];
        cout<<solution(arr,num);
        return 0;
} 
