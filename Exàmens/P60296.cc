// Rol classificatori

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct info{
    int elo = 1200;
    bool online = true;
};

void update_login(map<string,info>& m)
{
    string player;
    cin >> player;
    if(m.find(player) == m.end()){
        info data;
        m.insert({player, data});
    }
    else{
        m[player].online = true;
    }
}

void update_logout(map<string,info>& m)
{
    string player;
    cin >> player;
    if(m.find(player) != m.end()){
        m[player].online = false;
    }
}

void update_play(map<string,info>& m)
{
    string p1, p2;
    cin >> p1 >> p2;
    if(m.find(p1) != m.end() and m.find(p2) != m.end() and m[p1].online and m[p2].online){
        m[p1].elo += 10;
        m[p2].elo -= 10;
        if(m[p2].elo < 1200) m[p2].elo = 1200;
    }

    else cout << "jugador(s) no connectat(s)" << endl;
}

void get_elo(map<string,info>& m)
{
    string player;
    cin >> player;
    if(m.find(player) != m.end()){
        cout << player << ' ' << m[player].elo << endl;
    }
}


void update(map<string,info>& m, string& s)
{
    if(s == "LOGIN"){
        update_login(m);
    }
    else if(s == "LOGOUT"){
        update_logout(m);
    }
    else if(s == "PLAY"){
        update_play(m);
    }
    else if(s == "GET_ELO"){
        get_elo(m);
    }
}

bool comp(pair<string,info>& a, pair<string,info>& b)
{
    if(a.second.elo == b.second.elo) return a.first < b.first;
    return a.second.elo > b.second.elo;
}

void write_ranking(map<string,info>& m)
{
    vector<pair<string,info>> v;
    for(auto p : m){
        v.push_back(p);
    }
    sort(v.begin(), v.end(), comp);
    cout << endl << "RANKING" << endl;
    for(auto e : v){
        cout << e.first << ' ' << e.second.elo << endl;
    }
}

int main()
{
    map<string,info> m;
    string s;
    while(cin >> s){
        update(m, s);
    }
    write_ranking(m);
}
