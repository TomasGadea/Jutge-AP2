/*
    WARNING: This code is no longer accepted by Jutge.org
             If you have the solution to this problem and want to share it,
             please open a PR and/or contact 01tomas.gadea@gmail.com
             This code will remain available for inspiration purposes.

             Sorry for the inconvenience
*/

// Electrical grids

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

using Node = int;

using Capacity = int;

struct Arc{
    Node dst;
    Capacity c;
};

using AdjacencyList = vector<Arc>;

using Graph = vector<AdjacencyList>;

using Flow = vector<map<Node, Node>>;

const int Nil = -1;


bool read_graph(Graph& G, Flow& F)
{
    int n, m;
    if (not (cin >> n >> m)) return false;
    G = Graph(n);
    F = Flow(n);

    for (int i = 0; i < m; ++i) {
        Node u, v;
        Capacity c;
        cin >> u >> v >> c;
        G[u].push_back({ v, c });
        F[u].insert({ v, c });
    }
    return true;
}

bool exists_path(Graph& G, Flow& F, vector<Node>& pre)
{
    int n = G.size();
    vector<bool> vis(n, false);
    queue<Node> q;
    Node s = 0;   // source node
    Node t = n-1;  // target node
    q.push(s);
    vis[s] = true;
    pre[s] = Nil;

    while (not (q.empty())) {
        Node u = q.front();
        q.pop();
        for (Arc a : G[u]) {
            Node v = a.dst;
            if (not(vis[v]) && F[u][v] != 0) {
                q.push(v);
                pre[v] = u;
                vis[v] = true;
            }
        }
    }
    return vis[t];
}

int min_edge(Graph& G, Flow& F, vector<Node>& pre)
{
    int n = G.size();
    Node s = 0;  // source node
    Node t = n-1; // target node
    int pathflow = 5001;   // just 1 unit over max capacity given by the problem

    for (Node v = t; v != s; v = pre[v]) {
        Node u = pre[v];
        pathflow = min(pathflow, F[u][v]);
    }
    return pathflow;
}

void update_edges(Graph& G, Flow& F, vector<Node>& pre, int pathflow)
{
    int n = G.size();
    Node s = 0;  // source node
    Node t = n-1; // target node
    for (Node v = t; v != s; v = pre[v]) {
        Node u = pre[v];
        F[u][v] -= pathflow;
        F[v][u] += pathflow;
    }
}

int maxflow(Graph& G, Flow& F)
{
    int n = G.size();
    vector<int> pre(n);  // vector filled by a path from bfs
    int maxflow = 0;   // value to return

    while (exists_path(G, F, pre)) {
        int pathflow = min_edge(G, F, pre);
        maxflow += pathflow;
        update_edges(G, F, pre, pathflow);
    }
    return maxflow;
}

int main()
{
    Graph G;
    Flow F;   // this will be our residual graph
    while (read_graph(G, F)) {
        cout << maxflow(G, F) << endl;
    }
}
