// Nombre d'Erdős (2)  (Pau Redón Muñoz)

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;
using graf = vector<vector<int>>;

vector<int> bfs(const graf& G, int n){
	vector<int> v(n, -1);
	queue<int> q;
	v[0] = 0;
	q.push(0);

	while (not q.empty()){
		int a = q.front();
		q.pop();
		for (int i : G[a]){
			if (v[i] == -1){
				q.push(i);
				v[i] = v[a]+1;
			}
		}
	}
	return v;
}

int main(){
	int n, t;
	while (cin >> n >> t){
		graf G(n);
		//Entro el putissim graf
		for (int i = 0; i<t; ++i){
			int m;
			cin >> m;
			vector<int> v(m);
			for (int j = 0; j<m; ++j) cin >> v[j];
			for (int j = 0; j<m; ++j){
				for (int k = j+1; k<m; ++k){
					G[v[j]].push_back(v[k]);
					G[v[k]].push_back(v[j]);
				}
			}
		}
		vector<int> res = bfs(G, n);
		for (int i = 0; i<n; ++i){
			cout << i << " : ";
			if (res[i] == -1) cout << "no" << endl;
			else cout << res[i] << endl;
		}
		cout << "----------" << endl;
	}
}
