// Electrical grids (Alex Serrano)

#include<iostream>
#include<vector>
#include<queue>
#include<map>

using Node = int;
using namespace std;

using Flow = vector<map<Node,int>>; //value is flow
using adjl = vector<Node>;
using Graph = vector<adjl>;

void read_graph(int m, Graph &G, Flow&F){
    for (int i=0;i<m;i++){
        Node src,dst;
        cin>>src>>dst>>F[src][dst];
        G[src].push_back(dst);
        G[dst].push_back(src);
    }
}

int min_flow_in_path(const Graph &G, Node src, Node dst, vector<Node> &pre, Flow&f){
    queue<pair<Node,int>> q;
    int mf=5001;
    for (Node& v: pre) v = -1;
    q.push({src,5001});
    while (not q.empty()){
        pair<Node,int> visiting = q.front();
        q.pop();
        for (const Node& v: G[visiting.first])
        {
            if (f[visiting.first][v]!= 0 and pre[v]==-1 and v!=src)
            {
                pre[v] = visiting.first;
                mf = min(visiting.second,f[visiting.first][v]);
                if (v == dst) return mf;
                q.push({v,mf});
            }
        }
    }
    return 0;
}

void update_edges(Flow&f,vector<Node>&pre, int mf){
    Node src = 0, dst = pre.size()-1;
    for (Node u = dst; u!=src; u=pre[u]){
        Node v = pre[u];
        f[v][u] -= mf;
        f[u][v] += mf;
    }
}

int ford_fulkerson(Graph &G, Flow &f){
    int maxflow = 0,n=G.size(),mf;
    vector<Node>pre(n,-1);
    while (mf = min_flow_in_path(G,0,n-1,pre,f)){
        maxflow+=mf;
        update_edges(f,pre,mf);
    }
    return maxflow;
}

int main (){
int n,m;
while (cin>>n>>m){
    Graph G(n);
    Flow f(n);
    read_graph(m,G,f);
    cout<<ford_fulkerson(G,f)<<endl;}
}
