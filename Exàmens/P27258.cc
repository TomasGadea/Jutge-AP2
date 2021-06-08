// Monstres en un mapa

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int x, y;
};

Node read_node()
{
    Node u;
    cin >> u.x >> u.y;
    return u;
}

using Grid = vector<vector<char>>;


vector<Node> neighbours(Node& u, int n, int m){
    vector<Node> r;
    r.reserve(4);
    if(u.x > 0) r.push_back({u.x - 1, u.y});
    if(u.x < n-1) r.push_back({u.x + 1, u.y});
    if(u.y > 0) r.push_back({u.x, u.y - 1});
    if(u.y < m-1) r.push_back({u.x, u.y + 1});
    return r;
}


Grid read_grid(int n, int m, vector<vector<bool>>& vis, Node& I)
{
    Grid G(n, vector<char>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> G[i][j];
            if(G[i][j] == 'I'){
                I.x = i;
                I.y = j;
            }
            else if(G[i][j] == 'M'){
                Node M;
                M.x = i;
                M.y = j;
                for(Node v : neighbours(M, n, m)){
                    vis[v.x][v.y] = true;
                }
            }
        }
    }
    return G;
}

bool isPath(const Grid& G, Node& I, vector<vector<bool>>& vis)
{
    int n = G.size();
    int m = G[0].size();
    stack<Node> p;
    p.push(I);
    while(not p.empty()){
        Node u = p.top();
        p.pop();
        if(G[u.x][u.y] == 'F') return true;
        vis[u.x][u.y] = true;
        for(Node v : neighbours(u, n, m)){
            if(not vis[v.x][v.y]){
                p.push(v);
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    while(cin >> n >> m){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        Node I;
        Grid G = read_grid(n, m, vis, I);
        cout << (isPath(G, I, vis) ? "SI" : "NO") << endl;
    }
}
