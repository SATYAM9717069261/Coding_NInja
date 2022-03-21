#include<bits/stdc++.h>
using namespace std;
void print(map<int,string>* student){
	for(pair<int,string>i:(*student)){
		cout<<i.second<<" "<<i.first<<endl;
	}
}
int main(){
	int num;
	cin>>num;
	map<int,string> student;
	for(int i=0;i<num;i++){
		int m1,m2,m3;
		string name;
		cin>>name;
		cin>>m1>>m2>>m3;
		student.insert(make_pair(m1+m2+m3,name));	
	}
	print(&student);
	return 0;
}
