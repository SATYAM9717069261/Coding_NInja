#include<bits/stdc++.h>
using namespace std;
/**void print(int** arr,int m,int n){
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
			sum[i][j] = arr[i][j]+sum[i+1][j]+sum[i][j+1	]-sum[i+1][j+1];
	}
	print(sum,m,n);
}**/

int kadane(int* arr, int* start, int* finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;
    int local_start = 0;
    for (i = 0; i < n; ++i){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
    if (*finish != -1)
        return maxSum;
    maxSum = arr[0];
    *start = *finish = 0;
    for (i = 1; i < n; i++){
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
void findMaxSum(int** M, int ROW,int COL)
{
    int maxSum = INT_MIN,
                 finalLeft,
                 finalRight,
                 finalTop,
                 finalBottom;
    int left, right, i;
    int temp[ROW], sum, start, finish;
    for (left = 0; left < COL; ++left) {
        memset(temp, 0, sizeof(temp));
        for (right = left; right < COL; ++right) {
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            sum = kadane(temp, &start, &finish, ROW);
            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    cout << "Max sum is: " << maxSum << endl;
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
	findMaxSum(arr,m,n);
	return 0;

}
