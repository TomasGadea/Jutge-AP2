// Honest politicians  (Ferran Hernandez Caralt)

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;




void receive_money(map<string, int>& politics) {
	string s; cin >> s;
	int money; cin >> money;
	politics[s] += money;
}

void give_money(map<string, int>& politics) {
	string s; cin >> s;
	int money; cin >> money;
	politics[s] -= money;
}

void exchange_money(map<string, int>& politics) {
	string giver; cin >> giver;
	int money; cin >> money;
	string receiver; cin >> receiver;
	politics[giver] -= money;
	politics[receiver] += money;

}

struct politic {
	string person, money;
};


void map_to_vector(map<string, int>& politics, vector< vector<politic> >& format, int r) {
	
	int i = 0;
	int j = 0;
	for (auto a : politics) {
		format[i][j].person = a.first;
		format[i][j].money = to_string(a.second);
		i++;
		if (i == r) {
			i = 0;
			j++;
		}
	}
	
}

int maxlength(vector< vector<politic> >& format, int r, int j) {
	int maxlength = 0;
	for (int i = 0; i < r; i++) {
		if (format[i][j].person.size() + format[i][j].money.size() + 1 > maxlength) {
			maxlength = format[i][j].person.size() + format[i][j].money.size() + 1;
		}
	}
	return maxlength;
}


void adapt_to_jutge(vector< vector<politic> >& format, int r, int columns) {
	for (int j = 0; j < columns; j++) {
		
		int max = maxlength(format, r, j);
		
		for (int i = 0; i < r; i++) {
			
			if (format[i][j].person != "") {
				string out = "";
				if (j != 0) out = " | ";
				
				out += format[i][j].person + ' ';
							
				int size_diff = max - (format[i][j].person.size() + format[i][j].money.size() + 1);
				for (int k = 0; k < size_diff; k++) {
					out += ' ';
				}
				
				format[i][j].person = out + format[i][j].money;
			}
		}
	}
}


void print_resultats(map<string, int>& politics, int r) {
	
	int columns = politics.size()/r + 3;
	
	vector< vector<politic> > format(r, vector<politic>(columns, {"", ""}));
	
	map_to_vector(politics, format, r);
	
	adapt_to_jutge(format, r, columns);
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < columns; j++) {
			if (format[i][j].person != "") {
				cout << format[i][j].person;
			}
		}
		cout << endl;
	}
	cout << "****************************************" << endl;
	
}

int main() {
	int n;
	while (cin >> n) {
		map<string, int> politics;
		string c;
		bool end = false;
		while (not end and cin >> c) {
			if (c == "R") receive_money(politics);
			else if (c == "G") give_money(politics);
			else if (c == "P") exchange_money(politics);
			else end = true;
		}
		print_resultats(politics, n);
	}
}
