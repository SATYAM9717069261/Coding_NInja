#include<bits/stdc++.h>
using namespace std;
void print(int board[][],int row , int col){
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}
}

void helper(int board[][],int board_col,int board_row,int queen_x,int queen_y,int oper_num){
	for(int i=0;i<board_row;i++){
		board[i][queen_y]+=oper_num; //Set x-axis
	}
	for(int i=0;i<board_col;i++){
		board[queen_x][i]+=per_num; //Set y_axis
	}
}

bool solution(int current_col,int board[][], int board_row,int board_col, int n_queen, int previous_queen_x,int previous_queen_y){
	if(n_queen == 0)
		return true;
	else{
		for(int i=0;i<board_row;i++){
			if(board[current_col][j] == 0){
				//set
				if(solution(current_col+1,board,board_row,board_col,n_queen-1,i,j) == true)
					return true;
			}
		}
		return false;
	}
}


int main(){
	int board[4][4]={0};
	int n_queen = 4;
	int previous_queen_x=0;
	int previous_queen_y=0;
	int current_col=0;
	solution(current_col,board,4,4,n_queen,previous_queen_x,previous_queen_y);
	return 0;
}


