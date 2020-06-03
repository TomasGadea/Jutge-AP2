// Comprovant parèntesis

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool do_close(char& a, char&b){
	return (a == '(' and b == ')') or (a == '[' and b == ']');
}

void analize_set(string& s){
	stack<char> pila;
	for(int i = 0; i < s.size(); ++i){
		if(pila.empty()) pila.push(s[i]);
		else if(do_close(pila.top(), s[i])) pila.pop();
		else pila.push(s[i]);
	}
	(pila.empty()? cout << s << " es correcta" << endl : cout << s << " es incorrecta" << endl);
}

int main(){
	string s;
	while(cin >> s){
		analize_set(s);
	}
}
