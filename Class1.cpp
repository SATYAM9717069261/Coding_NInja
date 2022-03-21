#include<bits/stdc++.h>
using namespace std;

class Student{
	int age;
	char* name;

	public: Student(int age,char* name){
			this->age=age;
			this->name=name;
		}

		void display(){
			cout<<"Name=> "<<name<<"\nage=>"<<age;
		}
};

int main(){
	Student* s1=new Student(23,"Satyam");
	(*s1).display();
	return 0;
}
