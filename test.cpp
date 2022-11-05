#include<bits/stdc++.h>
using namespace std;
int main(){
  string x;
    cin >> x;
    string s(2 * x.size() + 1, '#');
    for (int i = 0; i < x.size(); i++) {
        s[2 * i + 1] = x[i];
    }
    cout<<"String = >"<<s;
    return 0;
}
