// Mesures estadístiques

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void escriu(priority_queue<int, vector<int>, greater<int>>& q, int max, double sum){
	cout.setf(ios::fixed); cout.precision(4);

	cout << "minimum: " << q.top() <<", ";
	cout << "maximum: " << max << ", ";
	cout << "average: " << sum / q.size() <<endl;
}

int main(){
	priority_queue<int, vector<int>, greater<int>> q;
	string s;
	int max = 0;
	double sum = 0;
	while(cin >> s){
		if(s == "number"){
			int x; cin >> x;
			if(q.empty() or x > max) max = x;
			q.push(x);
			sum += x;
		}
		else if(s == "delete" and not q.empty()){
			sum -= q.top();
			q.pop();
		}
		if(q.empty()) cout << "no elements" << endl;
		else escriu(q, max, sum);
	}
}
