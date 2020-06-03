// Weighted shortest path (5)

#include<iostream>
#include<vector>
using namespace std;

using Node = int;

using Cost = int;

const int Infinite = 1000000000;

struct Arc{
    Node dst;
    Cost cost;
};

using AdjacencyList = vector<Arc>;

using Graph = vector<AdjacencyList>;

bool read_graph(Graph& G)
{
    int n, m;
    if(not(cin >> n >> m)) return false;
    G = Graph(n);
    for(int i = 0; i < m; ++i){
        Node u, v;
        Cost c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    return true;
}

void bellman_ford(const Graph& G, Node src, vector<Cost>& dist)
{
    int n = G.size();
    dist = vector<Cost>(n, Infinite);
    dist[src] = 0;

    bool keep = true;
    int iterations = n - 1;

    while(keep and iterations > 0){
        int updates = 0;
        for(Node u = 0; u < n; ++u){
            for(Arc a : G[u]){
                Node v = a.dst;
                Cost c = a.cost;

                if(dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                    ++updates;
                }
            }
        }
        if(updates == 0){
            keep = false;
        }
    }
}

int main()
{
    Graph G;
    while(read_graph(G)){
        Node x, y;
        cin >> x >> y;

        vector<Cost> dist;

        bellman_ford(G, x, dist);

        if(dist[y] == Infinite){
            cout << "no path from " << x << " to " << y << endl;
        }else{
            cout << dist[y] << endl;
        }
    }
}
