// Notació polonesa inversa

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int main(){
	string s;
	stack<int> pila;
	while(getline(cin, s)){
		istringstream iss(s);
		string c;
    	while(iss >> c){
    		if(isdigit(c[0])) pila.push(stoi(c));
			else{
				int x = pila.top(); pila.pop();
				int y = pila.top(); pila.pop();
				if(c == "+") pila.push(y + x);
				else if(c == "-") pila.push(y - x);
				else              pila.push(y * x);
			}
    	}
    	(pila.empty() ? cout << endl : cout << pila.top() << endl);
	}
}
