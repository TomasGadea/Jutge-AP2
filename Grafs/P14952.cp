// Ordenació topològica

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using Node = int;
using Graph = vector<vector<Node>>;

Graph create_graph(int n, int m, vector<int>& pre)
{
    Graph G(n);
    for(int i = 0; i < m; ++i){
        Node u, v;
        cin >> u >> v;
        G[u].push_back(v);
        ++pre[v];
    }
    return G;
}


vector<Node> linearize(const Graph& G, vector<int>& pre)
{
    vector<Node> linearization;
    int n = G.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; ++i){
        if(pre[i] == 0){
            pq.push(i);
        }
    }
    while(not pq.empty()){
        Node u = pq.top();
        pq.pop();
        linearization.push_back(u);
        for(Node x : G[u]){
            --pre[x];
            if(pre[x] == 0){
                pq.push(x);
            }
        }
    }
    return linearization;
}

int main()
{
    int n, m;
    while(cin >> n >> m){
        vector<int> pre(n, 0);
        Graph G = create_graph(n, m, pre);
        vector<Node> lin = linearize(G, pre);
        for(int i = 0; i < n-1; ++i){
            cout << lin[i] << ' ';
        }
        cout << lin[lin.size()-1] << endl;
    }
}
