// Simulant recursivitat (2)

#include <iostream>
#include <stack>
using namespace std;

void escriu(int n){
	stack<int> s;
	for(int i = n; i >= 1; --i){
		s.push(i);
	}
	while(not s.empty()){
		int top = s.top();
		cout << ' ' << top;
		s.pop();
		if(top > 1){
			for(int i = top - 1; i >= 1; --i){
				s.push(i);
			}
		}
	}
}

int main(){
	int n;
	while(cin >> n){
		escriu(n);
		cout << endl;
	}
}
