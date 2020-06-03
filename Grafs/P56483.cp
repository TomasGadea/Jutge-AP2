// Grafs (1)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using Node = int;

using Graph = vector<vector<Node>>;  // llistes d'adjacència

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

bool connected(const Graph& G, Node x, Node y)
{
    int n = G.size();
    stack<Node> p;
    vector<bool> vis(n, false);
    p.push(x);
    while(not p.empty()){
        Node u = p.top();
        p.pop();
        if(u == y) return true;

        vis[u] = true;
        for(Node v : G[u]){
            if(not vis[v]){
                p.push(v);
            }
        }
    }
    return false;
}

int main()
{
    Graph G = read_graph();

    Node x, y;
    cin >> x >> y;

    cout << (connected(G, x, y) ? "yes" : "no") << endl;
}
