#include<bits/stdc++.h>
using namespace std;
struct Point{int x,y; };
bool collinear(Point p, Point q, Point r){
  int x1 = q.x - p.x;
  int y1 = q.y - p.y;
  int x2 = r.x - q.x;
  int y2 = r.y - q.y;
  int value = x1*y2 - y1*x2;
  return value == 0;
}
int main(){
  int num;cin>>num;
  while(num--){
    Point p,q,r;
    cin>>p.x;cin>>p.y;
    cin>>q.x;cin>>q.y;
    cin>>r.x;cin>>r.y;
    cout<<(collinear(p,q,r)?"Yes":"No")<<endl;
  }
  return 0;
}
