// Grafs (2)

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;

using Node = string;
using Graph = vector<vector<Node>>;

Graph read_string_graph(map<Node, int>& pos)
{
    int n;
    cin >> n;
    Graph G(n);
    for(int i = 0; i < n; ++i){
        Node city;
        cin >> city;
        pos[city] = i;
    }
    int m;
    cin >> m;
    for(int j = 0; j < m; ++j){
        Node city1, city2;
        cin >> city1 >> city2;
        G[pos[city1]].push_back(city2);
    }
    return G;
}

bool connected(const Graph& G, map<Node,int>& pos, Node x, Node y)
{
    int n = G.size();
    vector<bool> vis(n, false);
    stack<Node> p;
    p.push(x);
    while(not p.empty()){
        Node u = p.top();
        p.pop();
        if(u == y) return true;
        vis[pos[u]] = true;
        for(Node v : G[pos[u]]){
            if(not vis[pos[v]]){
                p.push(v);
            }
        }
    }
    return false;
}

int main()
{
    map<Node, int> pos;
    Graph G = read_string_graph(pos);
    Node x, y;
    cin >> x >> y;
    cout << (connected(G, pos, x, y) ? "yes" : "no") << endl;
}
