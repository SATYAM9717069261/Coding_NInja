#include<bits/stdc++.h>
using namespace std;
#define SUDO_SIZE 9

void print(int sudoku[][SUDO_SIZE]){
	for(int i=0;i<SUDO_SIZE;i++){
                for(int j=0;j<SUDO_SIZE;j++)
                        cout<<sudoku[i][j];
		cout<<endl;
	}
}

bool check_vertical(int sudoku[][SUDO_SIZE],int x,int y,int currentNumber){
	for(int i=0;i<SUDO_SIZE;i++){
		if(sudoku[i][y] == currentNumber)
			return false;
	}
	return true;
}

bool check_horizontal(int sudoku[][SUDO_SIZE],int x,int y,int currentNumber){
        for(int i=0;i<SUDO_SIZE;i++){
                if(sudoku[x][i] == currentNumber)
                        return false;
        }
        return true;
}
bool check_subSquare(int sudoku[][SUDO_SIZE],int x,int y,int currentNumber){
	int start_x=x/3;
	start_x*=3;
	int start_y=y/3;
	start_y*=3;
	int end_x=start_x+3;
	int end_y=start_y+3;
        for(int i=start_x;i<end_x;i++){
		for(int j=start_y;j<end_y;j++){
                	if(sudoku[i][j] == currentNumber)
                        	return false;
		}
        }
        return true;
}

bool solution(int sudoku[][SUDO_SIZE],int x,int y){
	if(x == SUDO_SIZE-1 && y == SUDO_SIZE-1){
		return true;
	}
	else{
		if(y == SUDO_SIZE){
			y=0;
			x++;
		}
		if(sudoku[x][y]==0){
			for(int i=1;i<=9;i++){
				if(check_vertical(sudoku,x,y,i) && check_horizontal(sudoku,x,y,i) && check_subSquare(sudoku,x,y,i)){
					sudoku[x][y] = i;
					if( solution(sudoku,x,y+1) )
						return true;
					else
						sudoku[x][y]=0;
					
				}
			}
		}else{
			if( solution(sudoku,x,y+1) )
				return true;
		}
	}
	return false;
}


int main(){
	int sudoku[SUDO_SIZE][SUDO_SIZE];
	for(int i=0;i<SUDO_SIZE;i++)
		for(int j=0;j<SUDO_SIZE;j++)
			cin>>sudoku[i][j];
	if(solution(sudoku,0,0))
		print(sudoku);
	else
		cout<<"Not Possible";
	return 0;
}
