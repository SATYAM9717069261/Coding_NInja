#include<bits/stdc++.h>
using namespace std;

void solution(int* start,int* end, int size,int* result){
        for(int i=1;i<=size;i++){
                start[i] = start[i-1]+start[i] - end[i-1];
        }
        for(int i=1;i<=size;i++)
                result[start[i]]++;
        int total=0;
        for(int i = size;i>=0;i--){
                result[i]+=total;
                total=result[i];
        }
}

int main(){
    int test;cin>>test;
    while(test--){
        int boxSize;cin>>boxSize;
        int query;cin>>query;
        int start[boxSize+1]={0};
        int end[boxSize+1]={0};
        int result[boxSize+1]={0};
        while(query--){
                int st;cin>>st;
                int ed;cin>>ed;
                start[st]++;
                end[ed]++;
        }
        solution(start,end,boxSize,result);
        int ans;cin>>ans;
        for(int i=0;i<ans;i++){
            int k;cin>>k;
            cout<<result[k]<<endl;
        }
    }
        return 0;
}
