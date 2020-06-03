// Simulant recursivitat (1)

#include <iostream>
#include <stack>
using namespace std;

void escriu(int n){
	stack<int> s;
	s.push(n);
	while(not s.empty()){
		cout << ' ' << s.top();
		int newtop = s.top() - 1;
		s.pop();
		if(newtop >= 1){
			s.push(newtop); s.push(newtop);
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
