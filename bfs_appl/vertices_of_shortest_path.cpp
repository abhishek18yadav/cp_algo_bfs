#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<list>
using namespace std;
vector<list<int>>gp;
int v;

void add_edge(int src, int dst , bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void bfsA(int node, vector<int>&da){
    queue<int>q;

    unordered_set<int>visited;
    q.push(node);
    visited.insert(node);
    while(!q.empty()){
        int w=q.front();
        // cout<<w<<" ";
        q.pop();
        for(auto neighbour : gp[w]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                da[neighbour]=da[w]+1;
            }
        }
    }
    cout<<endl;
}
void bfsB(int node, vector<int>&db){
    queue<int>q;
    unordered_set<int>visited;
    q.push(node);
    visited.insert(node);
    while(!q.empty()){
        int w=q.front();
        // cout<<w<<" ";
        q.pop();
        for(auto neighbour : gp[w]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                db[neighbour]=db[w]+1;
            }
        }
    }
}
vector<int>f( int y, vector<int>&da, vector<int>&db){
    vector<int>res;
    for(int i=0; i<gp.size(); i++){
        if(da[i]+db[i]==da[y]){
            res.push_back(i);
        }
    }
    return res;
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
int main(){
    cin>>v;
    int e;
    cin>>e;
    gp.resize(v, list<int>());
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    vector<int>da(v,0);
    vector<int>db(v,0);
    // display();
    cout<<"enter pair"<<endl;
    int x,y;
    cin>>x>>y;
    bfsA(x ,da);
    bfsB(y,db);
    vector<int>ans=f(y, da,db);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    return 0;
}