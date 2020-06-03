// Easy game?

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string& a, string& b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void casBase(string& w, set<string>& has){
    if(w != "END" and w != "QUIT") has.insert(w);
}

void play(int& game, string& w, set<string>& has, set<string>& had, vector<string>& v){
    while(cin >> w and w != "END" and w != "QUIT"){
        if(has.count(w)){ // esta a la llista
            has.erase(w);
            had.insert(w);
        }
        else if(had.count(w)){ // estava a la llista
            had.erase(w);
            has.insert(w);
        }
        else{ // nova paraula
            has.insert(w);
        }
    }
    for(string x : had) v.push_back(x);
    sort(v.begin(), v.end(), comp);
    cout << "GAME #" << game << endl;
    cout << "HAS:" << endl;
    for(string x : has) cout << x << endl;
    cout << endl;
    cout << "HAD:" << endl;
    for(string x : v) cout << x << endl;
    ++game;
}

int main(){
    int game = 1;
    string w;
    set<string> has;
    set<string> had;
    while(cin >> w){
        has = {};
        had = {};
        vector<string> v;
        casBase(w, has);
        if(w == "QUIT") break;
        if(w == "END"){
            cout << "GAME #" << game << endl;
            cout << "HAS:" << endl;
            cout << endl;
            cout << "HAD:" << endl;
            ++game;
        }
        else{
            play(game, w, has, had, v);
            if(w == "QUIT") break;
        }
        cout << endl;
    }
    if(w == "QUIT" and has.size() == 0 and had.size() == 0){
        cout << "GAME #" << game << endl;
        cout << "HAS:" << endl;
        cout << endl;
        cout << "HAD:" << endl;
    }
}
