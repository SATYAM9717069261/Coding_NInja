#include<bits/stdc++.h>
using namespace std;

struct student{
	int roll;
	string name;
	int marks;
};

void print(student* report,int num){
	for(int i=0;i<num;i++)
                cout<<report[i].roll<<" " <<report[i].name<<" "<<report[i].marks<<endl;
}
bool myfunction (student i,student j) {
	if(i.marks > j.marks)
		return true;
	else if(i.marks== j.marks){
		if(i.roll < j.roll)
			return true;
		else
			return false;
	}else{
		return false;
	}
}

int main(){
	int num;
	cin>>num;
	student* report=new student[num]; 
	//vector<pair<int,string>> report;
	for(int i=0;i<num;i++){
		string name;
		cin>>name;
		int num1,num2,num3;
		cin>>num1>>num2>>num3;
		report[i]={i,name,num1+num2+num3};
	}
	cout<<"<====Before Sorting===> "<<endl;
	print(report,num);
	sort(report,report+num,myfunction);
	cout<<"<====After Sorting===>"<<endl;
	print(report,num);
	//solution(report);
	return 0;
}
