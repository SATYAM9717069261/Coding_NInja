#include<bits/stdc++.h>
using namespace std;
void print(int size,string keypad[]){
        for(int i=0;i<size;i++){
                cout<<keypad[i]<<endl;
        }
}
long substr(int num,string result[],string keypad[]){
        if(num == 0){
                result[0]="";
                return 1;
        }else{
                long size=substr(num/10,result,keypad);
                string current=keypad[num%10];
                long k=0;
                string tempString[size];
                for(long i=0;i<size;i++)
                        tempString[i]=result[i];
                for(long i=0;i<current.length();i++){
                        for(long j=0;j<size;j++)
                                result[k++]=tempString[j]+current[i];
                }
                return k;
        }
}

int main(){
    int test;cin>>test;
    while(test--){
    	string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        long num;cin>>num;
        string result[2000];
        long limit=substr(num,result,keypad);
        print(limit,result);
    }
 		return 0;
}
