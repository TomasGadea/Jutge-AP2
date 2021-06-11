// Rutes Barates


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


using Node = int;
using Cost = int;

const int Infinite = 1e9 + 5;

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



// Returns the lowest cost needed to go from Node src to Node dst in Graph G
// Pre: vector C contains the costs of the nodes. Edges' cost is stored in G already
int dijkstra(const Graph& G, vector<Cost>& C, Node src, Node dst)
{
    if (src == dst) return 0;

    // init of dijkstra:
    int n = G.size();
    vector<Cost> dist(n, Infinite);

    vector<bool> done(n, false);
    priority_queue<Arc> q;


    q.push({src, 0});
    dist[src] = 0;

    // Begin dijkstra:
    while(not q.empty()){
        Node u = q.top().dst;
        q.pop();
        if(not done[u]){
            done[u] = true;
            if (u == dst) return dist[dst] - C[dst];  // dst cost not required, we subtract it.
            for(Arc a : G[u]){
                Node v = a.dst;
                Cost road = a.cost;
                Cost hotel = C[v];
                if(dist[v] > dist[u] + road + hotel){
                    dist[v] =  dist[u] + road + hotel;
                    q.push({v, dist[v]});
                }
            }
        }
    }
    return Infinite;
}


// Returns a vector of the cost of n nodes
vector<Cost> read_cost(int n)
{
    vector<Cost> C(n);
    for (int i = 0; i < n; ++i) cin >> C[i];
    return C;
}

// Returns a graph read from standard input of n nodes and m edges
Graph read_graph(int n, int m)
{
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        Node u, v;
        Cost c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});  // insert the reverse edge, as G is not directed
    }
    return G;
}


void write_cost(Graph& G, vector<Cost>& C, Node A, Node B, int budget)
{
    cout << "c(" << A << ',' << B << ") = ";
    if(budget == Infinite){
        cout << "+oo";
    } else {
        cout << budget;
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Cost> C = read_cost(n);
    Graph G = read_graph(n, m);

    Node A, B;
    while (cin >> A >> B) {
        int budget = dijkstra(G, C, A, B);
        write_cost(G, C, A, B, budget);
    }
}
