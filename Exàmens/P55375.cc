// Nombre de rotacions (2)

#include<iostream>
#include<vector>
using namespace std;


int func(const vector<int>& V, int& i, int& j)
{
	if(j - i == 1) return j;

	int mid = (i+j) / 2;
	if(V[i] < V[mid])  return func(V, mid, j);
	else if(V[j] > V[mid]) return func(V, i, mid);
}

int number_of_rotations(const vector<int>& V)
{
	int i = 0;
	int j = V.size()-1;

	if(V[i] < V[j]) return 0;

	return func(V, i, j);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << "number of rotations " << number_of_rotations(v) << endl;
}
