// Las Zamburguesas

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point{
    double x, y;
};

struct Node{    // Rock
    Point c;
    double r;
    int dist = -1;
    vector<int> neighbours;
};

using Graph = vector<Node>;

bool distance(Node& a, Node& b, double d){
    return (b.c.x - a.c.x)*(b.c.x - a.c.x) + (b.c.y - a.c.y)*(b.c.y - a.c.y) < (d + a.r + b.r)*(d + a.r + b.r);
}

void add_neighbours(Graph& G, int i, double d){
    for(int j = 0; j < i; ++j){
        if(distance(G[j], G[i], d)){
            G[j].neighbours.push_back(i);
            G[i].neighbours.push_back(j);
        }
    }
}

Node read_node(){
    Node u;
    cin >> u.c.x >> u.c.y >> u.r;
    return u;
}

Graph read_graph(int n, double d){
    Graph G(n);
    for(int i = 0; i < n; ++i){
        Node u = read_node();
        G[i] = u;
        add_neighbours(G, i, d);
    }
    return G;
}

void shortest_path(Graph& G){
    int n = G.size();
    queue<int> q;
    q.push(0);
    G[0].dist = 0;
    while(not q.empty()){
        int index = q.front();
        q.pop();
        for(int x : G[index].neighbours){
            if(G[x].dist == -1){
                G[x].dist = G[index].dist + 1;
                if(x == n-1){
                    cout << G[x].dist << endl;
                    return;
                }
                q.push(x);
            }
        }
    }
    cout << "Xof!" << endl;
}

int main(){
    int n;
    double d;
    while(cin >> n >> d){
        Graph G = read_graph(n, d);
        shortest_path(G);
    }
}
