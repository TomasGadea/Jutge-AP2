// Number of shortest paths (Nathaniel Mitrani)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using Vertex = int;
using adjlist = vector<Vertex>;
using Graph = vector<adjlist>;

Graph read_graph(int n, int m){
    Graph G(n);
    for (int i=0;i<m;i++){
        Vertex u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    return G;
}

vector<pair<int,int>> bfs(const Graph &G, Vertex src){
    int n=G.size();
    vector<pair<int,int>> info(n,{100000,0}); //dist,#sp.
    info[src]={0,1};
    vector<bool> visited(n,false);
    queue<pair<Vertex,int>>s;
    pair<Vertex,int>i={src,0}; //vertex, length of path.
    visited[src]=true;
    s.push(i);
    while (not s.empty()){
        pair<Vertex,int> v=s.front();
        visited[v.first]=true;
        s.pop();
        for (Vertex u: G[v.first]){
            if (v.second + 1 < info[u].first) info[u]={v.second+1,1};
            else if (v.second + 1 == info[u].first) info[u].second++;
            if (not visited[u]) s.push({u,v.second+1});
        }
    }
    return info;
}

int main (){
    int n,m;
    while (cin>>n>>m){
    Graph G = read_graph(n,m);
    Vertex src = 0;
    vector<pair<int,int>>dist=bfs(G,src);
    for (Vertex x=0;x<n;x++){
        (dist[x].first != 100000) ? cout<<x<<": "<<dist[x].first<<" "<<dist[x].second<<endl : cout<<x<<": -1"<<endl;
    }
    cout<<endl;
    }
}
