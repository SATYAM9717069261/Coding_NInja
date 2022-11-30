#include<bits/stdc++.h>
using namespace std;
struct Point{int x,y; };

void print(Point* data, int num){
  for(int i=0;i<num;i++)
    cout<<data[i].x<<","<<data[i].y<<endl;
}

bool change (Point p, Point q, Point r){
  int x1 = q.x - p.x;
  int y1 = q.y - p.y;
  int x2 = r.x - q.x;
  int y2 = r.y - q.y;
  int value = x1*y2 - y1*x2;
  return value>0;
}

void convex(Point* points, int num){
  vector<Point> hull;
    int left = 0 ;
    for(int i=1;i<num;i++){
      if(points[i].x < points[left].x)
        left = i;
    }
    int p = left;
    do{
      hull.push_back(points[p]);
      //cout<<"Push => "<<points[p].x <<points[p].y;
      int q = (p+1)%num;
      for(int i=0;i<num;i++){
        if(change(points[p], points[q], points[i])){
          q=i;
        }
      }
      p=q;
    }while(p!=left);
   
    //print hull
    for(int i=0;i<hull.size();i++)
      cout<<hull[i].x<<" "<<hull[i].y<<endl;
}

int main(){
  int num; cin>>num;
  Point points[num];
  for(int i=0;i<num;i++){
    cin>>points[i].x;
  }
  
  for(int i=0;i<num;i++){
    cin>>points[i].y;
  }
  convex(points,num);
  //print(points,num);
  return 0;
}
