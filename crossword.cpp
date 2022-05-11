#include<bits/stdc++.h>
using namespace std;
#define LIMIT 10
#define Words 4
void print(char arr[][LIMIT]){
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
}
void placedLettersPrint(vector<pair<int,int>> data){
	cout<<"Record= >";
	for(pair<int,int> i : data)
		cout<<i.first<<" "<<i.second<<endl;
	cout<<endl;
}
bool verticalPlaceWords(string word, int x,int y , char board[][LIMIT],vector< pair<int,int>>& placedLetters){
	//cout<<"Try to fit => "<<word;
	int wordStart = 0; 
	for(int i=x;i<LIMIT && wordStart < word.size();i++){
		if(board[i][y] == '-' || board[i][y] == word[wordStart]){
			if (board[i][y] == '-') 
				placedLetters.push_back(make_pair(i,y));
			board[i][y] = word[wordStart++];
		}else{
			//placedLettersPrint(placedLetters);
			return false;
		}
	}
	return wordStart == word.size() ? true:false; 
}
bool horizontaalPlaceWords(string word, int x,int y, char board[][LIMIT],vector< pair<int,int>>& placedLetters){
	int wordStart = 0;
	for(int j=y;j<LIMIT && wordStart<word.size() ;j++){
		if(board[x][j] == '-' || board[x][j] == word[wordStart]){
			if( board[x][j] == '-')
				placedLetters.push_back(make_pair(x,j));
			board[x][j] = word[wordStart++];
		}else{
			return false;
		}
	}
	return wordStart == word.size() ? true: false; 
}
void reverse(char board[][LIMIT],vector<pair<int,int>> places){
	for(pair<int,int> i: places){
		board[i.first][i.second] = '-';
	}
	 //print(board);
}
bool solution(char board[][LIMIT],string letters[],int lettercount=Words){
	//cout<<"Place => "<< letters[0]<<"letter Count => "<<lettercount<<endl;
	//Store where we put letters
	if(lettercount == 0){
		//cout<<"Finnal => "<<endl;
		//print(board);
		return true;
	}
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){
			if(board[i][j] == '-' || board[i][j] == letters[0][0]){
				vector< pair<int,int> > h_placedLetters;
	//			cout<<"Blank Space = > "<< i << j<<endl;
				if(verticalPlaceWords(letters[0],i,j,board,h_placedLetters)){	
	//				print(board);
					if(solution(board,letters+1,lettercount-1 )){ //false -> revert last changes and continue
						return true;
					}
					else{
	//					cout<<"Not Fit=> "<< letters+1 << "Revert => "<< letters[0];
						reverse(board,h_placedLetters);
					}
				}else{
	//				placedLettersPrint(h_placedLetters);
					reverse(board,h_placedLetters);
	//				cout<<"Revert it => "<<endl;
	//				print(board);
				}
				vector< pair<int,int> > v_placedLetters;
				if(horizontaalPlaceWords(letters[0],i,j,board,v_placedLetters)){
	//				print(board);
				       	if(solution(board,letters+1,lettercount-1)){
						return true;
					}else{
	//					cout<<"Not Fit=> "<< letters+1 << "Revert => "<< letters[0];
						reverse(board,h_placedLetters);
					}
				}else{
	//				placedLettersPrint(v_placedLetters);
					reverse(board,v_placedLetters);
	//				cout<<"Revert it => "<<endl;
	//				print(board);
				}
			}
		}
	}
	return false;
}
int main(){
	char board[LIMIT][LIMIT];
	string letters[Words]={"CALIFORNIA","NIGERIA","CANADA","TELAVIV"};
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){
			cin>>board[i][j];
		}
	}
       	if( solution(board,letters) )
		print(board);
	else
		cout<<"Not Posible ";
	return 0;	
}
