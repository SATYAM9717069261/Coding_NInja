#include<bits/stdc++.h>
using namespace std;
void print(int** arr,int m,int n){
	for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                        cout<<arr[i][j]<<" ";
                }
                cout<<endl;
        }
}
void solution(int** arr,int m,int n){
	int** sum = new int*[m+1];
	for(int i=0;i<m+1;i++){
		sum[i] = new int[n+1];
		for(int j=0;j<n+1;j++)
			sum[i][j]=0;
	}
	for(int i=(m-1);i>=0;--i){
		for(int j=(n-1);j>=0;--j)
			sum[i][j] = arr[i][j]+sum[i+1][j]+sum[i][j+1];
	}
	print(sum,m,n);
}
int main(){
	int m;cin>>m;
	int n;cin>>n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
		arr[i] = new int[n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	//print(arr,m,n);
	solution(arr,m,n);
	return 0;

}
