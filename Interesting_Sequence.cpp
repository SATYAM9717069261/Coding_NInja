#include<bits/stdc++.h>
using namespace std;

long cal(long op1Cost,long op2Cost,long increment, long decrement){
        if( increment >= decrement ){
                long cost = decrement * op1Cost + (increment-decrement)* op2Cost;
                return cost;
        }
        return 0;
}
long solution(vector<long> num,long op1Cost, long op2Cost,long min,long max){
        long max_cost =0;
        for(long i = min ; i <= max ; i++ ){
                long inc = 0;
                long dec = 0;
                for(long current : num){
                        if( i > current )       inc += (i - current);
                        if( i < current )       dec += (current - i);
                }
                long cost = cal(op1Cost,op2Cost,inc,dec);
                if(max_cost > cost || max_cost == 0){
                        max_cost = cost;
                }
        }
        return max_cost;
}

int main(){
        int size;cin>>size;
        long op1Cost;cin>>op1Cost;
        long op2Cost;cin>>op2Cost;
        vector<long> num;
        while(size--){
                int i;cin>>i;
                num.push_back(i);
        }
        long min = *min_element(num.begin(), num.end());
        long max = *max_element(num.begin(), num.end());
        cout<<solution(num,op1Cost,op2Cost,min,max);
        return 0;
}

