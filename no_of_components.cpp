#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;
int v;
vector<list<int>>gp;
void add_edge(int src , int dst, bool bi_dir= true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
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
void bfs(unordered_set<int>&visited , int node){
    visited.insert(node);
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int w= q.front();
        q.pop();
        for(auto ele: gp[w]){
            if(!visited.count(ele)){
                q.push(ele);
                visited.insert(ele);
            }
        }
    }
    
}
int f(){
    unordered_set<int>visited;
    int count=0;
    for(int i=0; i<gp.size(); i++){
        if(!visited.count(i)){
            count++;
            bfs(visited , i);
        }
    }
    return count;
}
int main(){
    cin>>v;
    gp.resize(v , list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s , d, true);
    }
    // display();
    int no= f();
    cout<<no<<endl;
    return 0;
}