#include<bits/stdc++.h>
using namespace std;

vector<int> erase_data(vector<int>& data, int value){
        vector<int> temp;
        for(int i=0;i<data.size();i++){
                if(data[i]!=value)
                        temp.push_back(data[i]);
        }
        return temp;
}

vector<int> lru(vector<vector<int>> &inp,int cache_size, int query_size){
       
        vector<int> output;
        pair<int,int> cache[1000];
        vector<int> freq[1000];
        
        for(int i=0;i<1000;i++){
                cache[i] = make_pair(-1,0);
                freq[i] = {};
        }

        for (int i = 0; i < inp.size(); i++) {
                if(inp[i][0] == 1){
                        cache[inp[i][1]].first=inp[i][2];
                        if(cache[inp[i][1]].second != 0){
                                freq[cache[inp[i][1]].second] = erase_data(freq[cache[inp[i][1]].second], inp[i][1]);
                        }else{
                                //cache[inp[i][1]].second == 0 it means new element add
                                cache_size--; 
                        }
                        if(cache_size == 0){
                                //delete cache 
                                for(int i=0;i<1000;i++){
                                        if(!freq[i].empty()){
                                                cache[freq[i][0]].first = -1;
                                                cache[freq[i][0]].second = 0;
                                                freq[i].erase(freq[i].begin()); 
                                                break;                         
                                        }
                                }
                        }
                        cache[inp[i][1]].second++;
                        freq[cache[inp[i][1]].second].push_back(inp[i][1]);
                }else{
                        output.push_back(cache[inp[i][1]].first);
                }
        }
        return output;
}
int main(){
        int test; cin>>test;
        while(test--){
               vector<vector<int>> inp;
               int cache_size; cin>>cache_size;
               int query_size; cin>>query_size;
               
               while(query_size--){
                        int oper; cin>>oper;
                        if(oper==1){
                                int key;cin>>key;
                                int val;cin>>val;
                                inp.push_back({oper,key,val});
                        }else{
                                int key;cin>>key;
                                inp.push_back({oper,key});
                        }
               }
               vector<int> ans = lru(inp,cache_size,query_size);
               for(int i=0;i<ans.size();i++)
                       cout<<ans[i]<<" ";
               cout<<endl;
        }
        return 0;
}
