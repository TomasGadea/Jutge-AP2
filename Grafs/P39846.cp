// Tresors en un mapa (4)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int x, y;
};

using Grid = vector<vector<char>>;

Grid read_grid(int n, int m)
{
    Grid G(n, vector<char>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> G[i][j];
        }
    }
    return G;
}

Node read_node()
{
    Node u;
    cin >> u.x >> u.y;
    --u.x;
    --u.y;
    return u;
}

vector<Node> neighbours(const Node& u, int n, int m)
{
    //cout << "entro a neighbours" << endl;
    vector<Node> neighbours;
    neighbours.reserve(4);
    if(u.x > 0) neighbours.push_back({u.x - 1, u.y});
    if(u.x < n-1) neighbours.push_back({u.x + 1, u.y});
    if(u.y > 0) neighbours.push_back({u.x, u.y - 1});
    if(u.y < m-1) neighbours.push_back({u.x, u.y + 1});
    //cout << "surto de neighbours amb " << neighbours.size() << " nodes" << endl;
    return neighbours;
}

void furthest_treasure(const Grid& G, Node& s)
{
    int maxdist = -1;
    int n = G.size();
    int m = G[0].size();
    queue<Node> q;
    vector<vector<int>> dist(n, vector<int> (m, -1));
    dist[s.x][s.y] = 0;
    q.push(s);
    while(not q.empty()){
        Node u = q.front();
        q.pop();

        for(Node v : neighbours(u, n, m)){
            if(dist[v.x][v.y] == -1 and G[v.x][v.y] != 'X'){
                dist[v.x][v.y] = dist[u.x][u.y] + 1;
                if(G[v.x][v.y] == 't'){
                    maxdist = dist[v.x][v.y];
                }
                q.push(v);
            }
        }
    }
    if(maxdist == -1){
        cout << "no es pot arribar a cap tresor" << endl;
    }
    else{
        cout << "distancia maxima: " << maxdist << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Grid G = read_grid(n, m);
    Node s = read_node();
    furthest_treasure(G, s);
}
