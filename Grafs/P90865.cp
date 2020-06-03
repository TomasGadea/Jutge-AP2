// Strongly connected components

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

using Node = int;

using AdjacencyList = vector<Node>;

using Graph = vector<AdjacencyList>;


Graph read_graph()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for(int i = 0; i < m; ++i){
        Node u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    return G;
}

Graph reverse(const Graph& G)
{
    int n = G.size();
    Graph GR(n);
    for(Node u = 0; u < n; ++u){
        for(Node v : G[u]){
            GR[v].push_back(u);
        }
    }
    return GR;
}

void explore(const Graph& GR, Node v, vector<bool>& vis, stack<Node>& p)
{
    vis[v] = true;
    for(Node u : GR[v]){
        if(not(vis[u])){
            explore(GR, u, vis, p);
        }
    }
    p.push(v);
}

// performs a dfs in a graph and fills the stack with the sorted nodes by postnumber
void dfs(const Graph& GR, stack<Node>& p)
{
    int n = GR.size();
    vector<bool> vis(n, false);
    for(Node v = 0; v < n; ++v){
        if(not(vis[v])){
            explore(GR, v, vis, p);
        }
    }
}

// returns a stack with the sorted nodes of the graph by their postnumber when dfs is performed on them
stack<Node> postnumbers(const Graph& GR)
{
    stack<Node> p;
    dfs(GR, p);
    return p;
}

void explore_cc(const Graph& G, Node v, vector<int>& ccnum, int cc)
{
    ccnum[v] = cc;
    for(Node u : G[v]){
        if(ccnum[u] == 0){
            explore_cc(G, u, ccnum, cc);
        }
    }
}

int ConnComp(const Graph& G, stack<Node>& p)
{
    int n = G.size();
    vector<int> ccnum(n, 0);
    int cc = 1;
    while(not(p.empty())){
        Node v = p.top();
        p.pop();
        if(ccnum[v] == 0){
            explore_cc(G, v, ccnum, cc);
            ++cc;
        }
    }
    return --cc;
}

int scc(const Graph& G)
{
    Graph GR = reverse(G);
    stack<Node> p = postnumbers(GR);
    return ConnComp(G, p);
}

int main()
{
    int cases;
    cin >> cases;
    int i = 1;
    while(i <= cases){
        Graph G = read_graph();
        cout <<"Graph #"<<i<<" has "<< scc(G) <<" strongly connected component(s)."<< endl;
        ++i;
    }
}
