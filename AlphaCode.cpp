#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int len){
	for(int i = 0 ; i<len;i++)
		cout<<arr[i]<<" ";
}

string character(int num){
	string res;
	res.push_back( (char)num+64 );
	return res;
}
int solution(int arr[], int len , int res[]){
	if(len == 0)
	       return 0;
	if(len == 1)
		return 1;
	cout<<"Find In res=> "<<(arr[0]*10)+arr[1]<<endl;
	int two_digit_num= (arr[0]*10)+arr[1];
	if(res[two_digit_num]!=0 && two_digit_num <27)
		return res[two_digit_num];;
	int out = solution(arr+1,len-1,res);
	if( (arr[0]*10)+arr[1] <27 && (len-2) >= 0)
		out+=solution(arr+2,len-2,res);
	res[two_digit_num] = out;
	return out;
}

int main() {
	string inp;cin>>inp;
        int len = inp.length();
        int arr[len];
	for(int i= 0; i<len;i++){
                arr[i] = inp[i] - '0';
        }
	//print(arr,len);
	int res[26]={0};
	cout<<solution(arr,len,res);
	cout<<"Res=> "<<endl;
	print(res,26);
	return 0;
}

