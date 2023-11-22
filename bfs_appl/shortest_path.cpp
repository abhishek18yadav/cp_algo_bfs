#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;

vector<list<int>>gp;
int v;
 void add_edge(int src , int dst , bool bi_dir= true){
    gp[src].push_back (dst);
    if(bi_dir){
       gp[dst].push_back (src); 
    }
 }
 void display(){
    for(int i=0; i<gp.size(); i++){
        cout<<i<<"->";
        for(auto ele: gp[i]){
            cout<<ele<<",";
        }
        cout<<endl;
    }
 }
 int s(int src , int dst){
   queue<int>q;
   vector<int>dis(v, 0);
   unordered_set<int>visited;
   q.push(src);
   visited.insert(src);
   while(!q.empty()){
      int w= q.front();
      q.pop();
      for(auto ele: gp[w]){
         if(!visited.count(ele)){
            q.push(ele);
            visited.insert(ele);
            dis[ele]=dis[w]+1;
         }
      }
   }
   return dis[dst];
 }
 int main(){
    cin>>v;
    gp.resize(v , list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s, d,true);
    }
   //  display();
    int src, dst;
    cin>>src>>dst;
    int sp= s(src , dst);
    cout<<sp<<endl;
    return 0;
 }