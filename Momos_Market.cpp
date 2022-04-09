#include<bits/stdc++.h>
using namespace std;
void solution(long nshop,long* shop, long nday, long* day){
        for(long i=1;i<nshop;i++)
                shop[i]=shop[i-1]+shop[i];
        for(long i=0;i<nday;i++){
                long start=0;
                long end=nshop-1;
                long mid=(end+start)/2;
                long momo=shop[end]<day[i]?end:0;
                while(mid>start && mid < end && shop[0] < day[i] ){
                        if(day[i]>=shop[mid]){
                                momo=mid;
                                start=mid;
                        }else
                                end=mid;
                        mid=(end+start)/2;
                }
            if(shop[0]<day[i])
                cout<<momo+1<<" "<<day[i]-shop[momo]<<endl;
            else
                cout<<0<<" "<<day[i]<<endl;
        }
}


int main(){
        long nshop;cin>>nshop;
        long shop[nshop];
        for(int i=0;i<nshop;i++)
                cin>>shop[i];
        long nday;cin>>nday;
        long day[nday];
        for(long i=0;i<nday;i++)
                cin>>day[i];
        solution(nshop,shop,nday,day);
        return 0;
} 
