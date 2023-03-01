#include<bits/stdc++.h>
#define THREEHALFS 1.5F
using namespace std;
int main(){
  int test; cin>>test;
  while(test--){
    int inp; cin>>inp;
    long i;
    float x2, y;
    float three_half = THREEHALFS;
  
    x2 = inp * 0.5F;
    y = inp;
    i = * (long *) &y;
    i = 0x5f3759df - ( i >> 1);
    y = * (float *) &i;
    y = y *( (three_half) - (x2 * y *y) );

    cout<<" Ans => "<< y << endl;
  }
  return 0;
}
