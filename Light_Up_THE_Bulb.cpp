#include<bits/stdc++.h>
using namespace std;
int countGroup(string inp){
	int count = 0;
	for(int i=0 ; inp[i] != '\0';i++){
		if(inp[i] == '1' && inp[i]!='\0' && inp[i+1] == '0')
			count++;
	}
	if(inp[0] == '0')
		count++;
	return count;
}
int solution(string inp,int RevCost,int FlipCost){
	int groupCount = countGroup(inp);
	int totalCostBoth = ( (groupCount-1)*RevCost + FlipCost );
	int TotalFlipCost = groupCount*FlipCost;
	return min(totalCostBoth, TotalFlipCost);
}
int main(){
	int stringSize;cin>>stringSize;
	int RevCost;cin>>RevCost;
	int FlipCost;cin>>FlipCost;
	string inp;cin>>inp;
	cout<<solution(inp,RevCost,FlipCost);
	return 0;
}
