#include<bits/stdc++.h>
using namespace std;

bool check(long long k ,long long num){
        long long half=num/2+num%2;
        long long sharma=0;
        while((num-k)>0){
                num=num-k;
                num=num-(num/10);
                sharma+=k;
        }
        if((sharma+num)>=half)
                return true;
        else
                return false;
}
void solution(long long num){
        long long k=0;
        long long start=0;
        long long end=num;
        long long mid = (end+start)/2+(end+start)%2;
        check(end,num)?k=end:k=0;
        do{
                if(check(mid,num) == true){     
                        k=mid;
                        end=mid;
                        mid=(start+end)/2+(start+end)%2;
                }else{
                        start=mid;
                        mid=(start+end)/2+(start+end)%2;
                }
        }while( (start<mid) && (mid<end));
        cout<<k<<endl;
}

int main(){
    int test;cin>>test;
    while(test--){
        long long num;
        cin>>num;
        solution(num);
    }
        return 0;
}
