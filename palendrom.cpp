#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(char str[]) {
    int mid= (sizeof(str)/sizeof(char))/2 + (sizeof(str)/sizeof(char)) %2;
    cout<<"Size => "<<strlen(str);
    int j=0;
   for(int i=( sizeof(str)/sizeof(char) )-1;i<mid;i--){
	cout<<"Check=> "<< str[i] << " "<<str[j]<<endl; 
       if(str[i]!=str[j])
	       return false;
       j++;
   }
    return true;
}

int main(){
	char name[100];
	cin>>name;
	cout << checkPalindrome(name);
	return 0;
}
