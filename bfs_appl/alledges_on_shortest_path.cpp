#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<list>
using namespace std;
vector<list<int>>gp;
int v;
vector<int>da(v,0);
vector<int>db(v,0);
void add_edge(int src, int dst , bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void bfsA(int node){
    queue<int>q;
    unordered_set<int>visited;
    q.push(node);
    visited.insert(node);
    while(!q.empty()){
        int w=q.front();
        q.pop();
        for(auto neighbour : gp[w]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                da[neighbour]=da[w]+1;
            }
        }
    }
}
void bfsB(int node){
    queue<int>q;
    unordered_set<int>visited;
    q.push(node);
    visited.insert(node);
    while(!q.empty()){
        int w=q.front();
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
vector<pair<int,int>>f(int o, int y){
    queue<int>q;
    vector<pair<int,int>>res;
    q.push(o);
    unordered_set<int>visited;
    visited.insert(o);
     while(!q.empty()){
        int w=q.front();
        q.pop();
        for(auto neighbour : gp[w]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                if(da[w]+1+db[neighbour] == db[y]){
                    res.push_back({w,neighbour});
                }
            }
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
    // display();
    cout<<"enter pair"<<endl;
    int x,y;
    cin>>x>>y;
    bfsA(x);
    bfsB(y);
    cout<<"enter origin"<<endl;
    int o;
    cin>>o;
    vector<pair<int,int>>ans=f(o,y);
    for(auto ele:ans){
        cout<<ele.first<<" "<<ele.second<<",";
    }
    return 0;
}
