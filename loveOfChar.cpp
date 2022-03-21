#include<bits/stdc++.h>
using namespace std;

void solution(int num,string inp){
    int a=0;
    int s=0;
    int p=0;
    int i=0;
    for(char i:inp){     
        if(i=='a') a++;
        if(i=='s')	s++;
        if(i=='p')	p++;
        i++;
    }
    cout<<a<<" "<<s<<" "<<p;
}
int main()
{
    int num;
    cin>>num;
    string inp;
    cin>>inp;
    solution(num,inp);
    return 0;
}
