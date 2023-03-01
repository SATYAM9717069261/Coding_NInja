#include <bits/stdc++.h>
using namespace std;

int main() {
    int test; cin>>test;
    while(test--){
        int size; cin>>size;
        int arr[size];
        for(int& i: arr)
            cin>>i;
        int ans =INT_MAX;
        for(int i=0;i<size-2;i++){
            for(int j=i+1;j<size-1;j++){
                for(int k=j+1;k<size;k++){
                    cout<<"INside ";
                    int temp =3* abs( (arr[i] + arr[j] + arr[k] )/3 - arr[j]);
                    if(ans > temp){
                        ans = temp;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

