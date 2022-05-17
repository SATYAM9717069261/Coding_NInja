#include<bits/stdc++.h>
using namespace std;
int height(int sub_height){
        if(sub_height == 0 || sub_height ==  1)
                return 1;
        int MOD_Val = pow(10,9)+7;
        int x = height(sub_height-1);
        int y = height(sub_height-2);          
        long ans1=(long) x*x;
        long ans2=(long) 2*x*y;
        int mod1=(int) (ans1%MOD_Val);
        int mod2=(int) (ans2%MOD_Val);
        int ans= (mod1+mod2) % MOD_Val;
        return ans;
}


int main(){
    int test;cin>>test;
    while(test--){
        int h;
        cin>>h;
        cout<<height(h)<<endl;
    }
        return 0;
}

