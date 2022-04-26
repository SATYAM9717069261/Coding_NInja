#include<bits/stdc++.h>
using namespace std;
void print(int* board,int b_size){
	for(int i=0;i<b_size;i++){
		for(int j=0;j<b_size;j++)
			cout<<*((board+i*b_size) + j)<<"\t";
		cout<<endl;
	}
	cout<<endl;
}

bool solution(int* board,int b_size,pair<int,int> rat_pos,pair<int,int> dest){
	if(rat_pos.first == dest.first && rat_pos.second == dest.second){
		cout<<"Found=> "<<rat_pos.first<<" "<< rat_pos.second<<endl;
		print(board,b_size);
		return true;
	}
	else{
		*((board+rat_pos.first*b_size)+rat_pos.second)=0;
		//print(board,b_size);
		if(rat_pos.second-1 >= 0 && *((board+rat_pos.first*b_size)+rat_pos.second-1)!= 0 ){
			//cout<<"Position left=> "<<rat_pos.first<<" "<< rat_pos.second-1<<endl;
			pair<int,int>newPos={rat_pos.first,rat_pos.second-1};
			solution(board,b_size,newPos,dest); 
				*((board+rat_pos.first*b_size)+rat_pos.second)=1;
			//	print(board,b_size); 
				//return true;
			 //else return false;
		}
		if(rat_pos.second+1 < b_size && *((board+rat_pos.first*b_size)+rat_pos.second+1)!= 0 ){
			//cout<<"Position right=> "<<rat_pos.first<<" "<< rat_pos.second+1<<endl;
			pair<int,int>newPos={rat_pos.first,rat_pos.second+1};
                        solution(board,b_size,newPos,dest); 
				*((board+rat_pos.first*b_size)+rat_pos.second)=1;
			//	print(board,b_size); 
				//return true;
			 //else return false;
		}
		if(rat_pos.first-1 >= 0 && *((board+(rat_pos.first-1)*b_size)+rat_pos.second)!= 0 ){
			//cout<<"Position up=> "<<rat_pos.first-1<<" "<< rat_pos.second<<endl;
			pair<int,int>newPos={rat_pos.first-1,rat_pos.second};
                        solution(board,b_size,newPos,dest); 
				*((board+rat_pos.first*b_size)+rat_pos.second)=1;
			//	print(board,b_size);
			       	//return true;
			 //else return false;
		}
		if(rat_pos.first+1 < b_size && *((board+(rat_pos.first+1)*b_size)+rat_pos.second)!= 0 ){
			//cout<<"Position down=> "<<rat_pos.first+1<<" "<< rat_pos.second<<endl;
			pair<int,int>newPos={rat_pos.first+1,rat_pos.second};
                        solution(board,b_size,newPos,dest);
				*((board+rat_pos.first*b_size)+rat_pos.second)=1;
			       	//print(board,b_size);
				//return true;
			 //else return false;
		}
		*((board+rat_pos.first*b_size)+rat_pos.second)=0;
	}
	return false;
}
int main(){
	int num;cin>>num;
	int board[num][num];
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			cin>>board[i][j];
	//int num=3;
	//int board[num][num]={{1,0,1},{1,1,1},{1,1,1}};
	pair<int,int> rat_pos={0,0};
	pair<int,int> dest={num-1,num-1};
	print((int*)board,num);
	cout<<solution((int*)board,num,rat_pos,dest);
	return 0;
}
