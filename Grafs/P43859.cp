// Weighted shortest path (1)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using Node = int;

using Cost = int;

const int Nil = -1;

const int Infinite = 1000000000;

struct Arc{
    Node dst;
    Cost cost;
};

bool operator< (const Arc& a, const Arc& b)
{
    return a.cost > b.cost;
}

using AdjacencyList = vector<Arc>;

using Graph = vector<AdjacencyList>;

bool readGraph(Graph& G)
{
    int n, m;
    if(not(cin >> n >> m)){
        return false;
    }
    G = Graph(n);
    for(int i = 0; i < m; ++i){
        Node u, v;
        Cost c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    return true;
}

void dijkstra(const Graph& G, Node source, vector<Cost>& dist, vector<Node>& prev)
{
    int n = G.size();

    dist = vector<Cost>(n, Infinite);
    dist[source] = 0;

    prev = vector<Node>(n, Nil);

    priority_queue<Arc> q;
    q.push({source, 0});

    vector<bool> done(n, false);

    while(not q.empty()){
        Node u = q.top().dst;
        q.pop();
        if(not done[u]){
            done[u] = true;
            for(Arc a : G[u]){
                Node v = a.dst;
                Cost c = a.cost;
                if(dist[v] > dist[u] + c){
                    dist[v] =  dist[u] + c;
                    prev[v] = u;
                    q.push({v, dist[v]});
                }
            }
        }
    }
}

int main()
{
    Graph G;
    while(readGraph(G)){
        Node x, y;
        cin >> x >> y;

        vector<Cost> dist;
        vector<Node> prev;
        dijkstra(G, x, dist, prev);

        if(dist[y] == Infinite){
            cout << "no path from " << x << " to " << y << endl;
        }
        else{
            cout << dist[y] << endl;
        }
    }
}
