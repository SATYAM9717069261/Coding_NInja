/**
 * s1="abc"
 * s2="dc"
 */

#include<bits/stdc++.h>
using namespace std;

int solution(string s1,string s2,int s1len,int s2len,int** arr){
	if(s2len ==  0)
		return s1len; //this point s2 is -1
	if(s1len == 0) 
		 return s2len;
	if(arr[s1len-1][s2len-1] != -1)
		return arr[s1len-1][s2len-1];
	if(s1[s1len-1] == s2[s2len-1])
		return solution(s1,s2,s1len-1,s2len-1,arr);

	int replace = solution(s1,s2,s1len-1,s2len-1,arr)+1;
	int insert = solution(s1,s2,s1len,s2len-1,arr)+1;
	int del = solution(s1,s2,s1len-1,s2len,arr)+1;
	arr[s1len-1][s2len-1]=min({replace,insert,del});
	return arr[s1len-1][s2len-1];
}


int main(){
	string s1,s2;
	cin>>s1>>s2;
	int s1len = s1.size();
       	int s2len = s2.size(); 	
	int** arr = new int*[s1len+1];
	for(int i=0;i<s1len;i++)
		arr[i] = new int[s2len+1];
	for(int i=0 ; i<s1len;i++)
		for(int j=0;j<s2len;j++)
			arr[i][j]=-1;
	cout<<solution(s1,s2,s1len,s2len,arr);
}
