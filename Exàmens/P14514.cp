// Coloració de grafs  (Pau Redón Muñoz)

#include <iostream>
#include <vector>

using namespace std;

using graf = vector<vector<int>>;

int golafre(graf G, int n){
	vector<int> color(n, -1);
	int color_max = 0;
	color[0] = 0;
	for (int i = 0; i<n; ++i){
		vector<bool> agafats(n, false);
		for (int v : G[i]){
			if (color[v] != -1) agafats[color[v]] = true;
		}
		int j = 0;
		while (agafats[j] == true) ++j;
		color[i] = j;
		color_max = max(color_max, j);
	}
	return color_max+1;
}

int main() {
	int n, m;
	while (cin >> n >> m){
		graf G(n);
		for(int i = 0; i<m; ++i){
			int a, b;
			cin >> a >> b;
			G[b].push_back(a);
			G[a].push_back(b);
		}
		cout << golafre(G, n) << endl;
	}
}
