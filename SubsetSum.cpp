#include<bits/stdc++.h>
using namespace std;
bool solution(int size,int* arr,int find){
        if(size == 0){
                if(find - arr[size] == 0)
                    return true;
                else
                    return false;
        }
        if(find < 0)
                return false;
        if(find == 0)
                return true;
        bool left = solution(size-1,arr,find-arr[size]);
        bool right= false;
        if(left != true)
                 right=solution(size-1,arr,find);
        
    	if(left || right)
                return true;
        
    	return false;
}
int main(){
    int test;cin>>test;
    while(test--){
        int size;cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
                cin>>arr[i];
        int find;cin>>find;
        solution(size-1,arr,find) == 0 ? cout<<"No"<<endl : cout<<"Yes"<<endl;
    }
        return 0;
}
