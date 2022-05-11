#include<bits/stdc++.h>
using namespace std;
#define LIMIT 10
void print(char arr[][LIMIT]){
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
}
void placedLettersPrint(vector<pair<int,int>> data){
	for(pair<int,int> i : data)
		cout<<i.first<<" "<<i.second<<endl;
	cout<<endl;
}
bool verticalPlaceWords(string word, int x,int y , char board[][LIMIT],vector< pair<int,int>>& placedLetters){
	int wordStart = 0; 
	for(int i=x;i<LIMIT && wordStart < word.size();i++){
		if(board[i][y] == '-' || board[i][y] == word[wordStart]){
			if (board[i][y] == '-') 
				placedLetters.push_back(make_pair(i,y));
			board[i][y] = word[wordStart++];
		}else
			return false;
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
		}else
			return false;
		
	}
	return wordStart == word.size() ? true: false; 
}
void reverse(char board[][LIMIT],vector<pair<int,int>> places){
	for(pair<int,int> i: places) 
		board[i.first][i.second] = '-';
}
bool solution(char board[][LIMIT],vector<string> letters,int start=0){
	if(start == letters.size()){
		return true;
	}
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){
			if(board[i][j] == '-' || board[i][j] == letters[start][0]){
				vector< pair<int,int> > h_placedLetters;
				if(verticalPlaceWords(letters[start],i,j,board,h_placedLetters)){
					if(solution(board,letters,start+1 )) 
						return true;
					else 
						reverse(board,h_placedLetters);
				}else
					reverse(board,h_placedLetters);
				vector< pair<int,int> > v_placedLetters;
				if(horizontaalPlaceWords(letters[start],i,j,board,v_placedLetters)){
					if(solution(board,letters,start+1))
						return true;
					else 
						reverse(board,v_placedLetters);
				}else
					reverse(board,v_placedLetters);
			}
		}
	}
	return false;
}
int main(){
	char board[LIMIT][LIMIT];
	string inp;
	for(int i=0;i<LIMIT;i++){
		for(int j=0;j<LIMIT;j++){
			cin>>board[i][j];
		}
	}
	cin>>inp;
	vector<string> stringInp;
	string currentstring="";
	for(char i : inp){
		if(i==';'){
			stringInp.push_back(currentstring);
			currentstring = "";
		}
		else
			currentstring+=i;
	}
	stringInp.push_back(currentstring);
//	for(int i = 0;i<stringInp.size();i++)
//		cout<<stringInp[i]<<endl;
       	if( solution(board,stringInp) )
		print(board);
	else
		cout<<"Not Posible ";
	return 0;	
}
