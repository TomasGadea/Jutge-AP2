// Col·lecció de números

#include <iostream>
#include <queue>
using namespace std;

void update(priority_queue<int>& pq, char s){
	if(s != 'S' and pq.empty()){
		cout << "error!" << endl;
		if(s == 'I' or s == 'D'){
			int num; cin >> num;
		}
		return;
	}
	if(s == 'S'){
		int x; cin >> x;
		pq.push(x);
	}
	else if(s == 'A' and not pq.empty()) cout << pq.top() << endl;
	else if(s == 'R' and not pq.empty()) pq.pop();
	else if(s == 'I' and not pq.empty()){
		int x; cin >> x;
		x += pq.top();
		pq.pop();
		pq.push(x);
	}
	else if(s == 'D' and not pq.empty()){
		int x; cin >> x;
		int z = pq.top() - x;
		pq.pop();
		pq.push(z);
	}
}


int main(){
	priority_queue<int> pq;
	char s;
	while(cin >> s){
		update(pq, s);
	}
}
