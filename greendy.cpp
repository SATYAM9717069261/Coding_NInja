#include<bits/stdc++.h>
using namespace std;
int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;
    while (Set.find(Mex) != Set.end())
        Mex++;
    return (Mex);
}
  
int calculateGrundy (int n)
{
    if (n == 0)
        return (0);
    unordered_set<int> Set; // A Hash Table
    Set.insert(calculateGrundy(n/2));
    Set.insert(calculateGrundy(n/3));
    Set.insert(calculateGrundy(n/6));
    return (calculateMex(Set));
}
  
int main()
{
    int tst;cin>>tst;
    while(tst--){
    int n; cin>>n;
      cout<<calculateGrundy (n)<<endl;
    }
    return (0);
}
