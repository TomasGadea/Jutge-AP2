// Xafardeig

#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;


void escriu(map<string,string> m, set<string>& sols)
{
    cout << "PARELLES:" << endl;
    for(auto parella : m){
        cout << parella.first << ' ' << parella.second << endl;
        m.erase(parella.second);
    }
    cout << "SOLS:";
    if(sols.empty()) cout << endl;
    for(string single : sols){
        cout << single << endl;
    }
    cout << "----------" << endl;
}

void update(map<string,string>& m, set<string>& sols, string& p)
{
    if(p == "liats"){
        string x, y;
        cin >> x >> y;
        sols.erase(x);
        sols.erase(y);
        sols.insert(m[x]);
        sols.insert(m[y]);
        m.erase(m[x]);
        m.erase(m[y]);
        m[x] = y;
        m[y] = x;
    }
    else if(p == "info"){
        escriu(m, sols);
    }
}


int main()
{
    map<string,string> m;
    set<string> sols;
    string p;
    while(cin >> p){
        update(m, sols, p);
    }
}
