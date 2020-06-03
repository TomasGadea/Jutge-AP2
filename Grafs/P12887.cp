// Minimum spanning trees

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using Node = int;

using Cost = int;

struct Arc{
    Node dst;
    Cost cost;
};

using AdjacencyList = vector<Arc>;

using Graph = vector<AdjacencyList>;

bool operator< (const Arc& a, const Arc& b)
{
    return a.cost > b.cost;
}

int mst_cost(const Graph& G)
{
    int mst = 0; // the value to return
    int V = G.size() - 1;
    vector<bool> vis(V, false);
    vis[1] = true;
    int n = 1;

    priority_queue<Arc> pq;
    for(Arc neighb : G[1]){
        pq.push({neighb.dst, neighb.cost});
    }

    while(n < V){
        Arc a = pq.top();
        pq.pop();
        if(not vis[a.dst]){
            vis[a.dst] = true;
            mst += a.cost;
            ++n;
        }
        for(Arc neighb : G[a.dst]){
            if(not (vis[neighb.dst])){
                pq.push({neighb.dst, neighb.cost});
            }
        }
    }
    return mst;
}

bool read_graph(Graph& G)
{
    int n, m;
    if(not (cin >> n >> m)) return false;
    G = Graph(n+1);
    for(int i = 0; i < m; ++i){
        Node u, v;
        Cost c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    return true;
}

int main()
{
    Graph G;
    while(read_graph(G)){
        cout << mst_cost(G) << endl;
    }
}
