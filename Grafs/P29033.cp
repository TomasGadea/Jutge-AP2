// Dos colors (Ferran Hernandez Caralt)

#include <iostream>
#include <vector>
using namespace std;


const int Nil = -1;
using adjacency_list = vector<int>;
using graph = vector<adjacency_list>;



void explore_and_color(graph& G, vector<int>& colors, int u, int color, bool& bipartit) {

	colors[u] = color;

	for (int v : G[u]) {
		if (colors[v] == color) bipartit = false;
		else if (colors[v] == Nil) {
			explore_and_color(G, colors, v, (color+1)%2, bipartit);
		}
	}
}


bool bipartit(graph& G) {

	int n = G.size();

	vector<int> colors(n, Nil);

	bool bipartit = true;

	for (int u = 0; u < n; u++) {
		if (colors[u] == Nil) {
			explore_and_color(G, colors, u, 0, bipartit);
		}
	}
	return bipartit;
}


bool read_graph(graph& G) {
	int V, E;
	if (not (cin >> V >> E)) return false;

	G = graph(V);

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	return true;
}


int main() {
	graph G;
	while (read_graph(G)) {

		vector<int> colors(G.size(), Nil);

		if (bipartit(G)) cout << "yes";
		else cout << "no";
		cout << endl;
	}
}
