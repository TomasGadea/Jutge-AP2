// Mediana dinàmica

#include <iostream>
#include <set>
#include <string>
using namespace std;

void casBase(set<string>& paraules, const string& w, set<string>::iterator& it){
    paraules.insert(w);
    it = paraules.begin();
    cout << *it << endl;
}

string mediana(set<string>& paraules, set<string>::iterator& it, const string& w){
    paraules.insert(w);
    if(w < *it and paraules.size()%2 == 0 and paraules.size() != 1) --it;
    else if(w > *it and paraules.size()%2 == 1 and paraules.size() != 1) ++it;
    return *it;
}

int main(){
    set<string> paraules;
    string w;
    cin >> w;
    if(w != "END"){
        set<string>::iterator it;
        casBase(paraules, w, it);
        while(cin >> w and w != "END"){
            cout << mediana(paraules, it, w) << endl;
        }
    }
}
