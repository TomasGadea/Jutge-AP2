// Casino

#include <iostream>
#include <map>
#include <string>
using namespace std;

void enter(map<string, int>& casino, string& name){
    if(casino.count(name)){
        cout << name << " is already in the casino" << endl;
        return;
    }
    casino.insert({name, 0});
}

void win(map<string, int>& casino, string& name){
    int money; cin >> money;
    if(not casino.count(name)){
        cout << name << " is not in the casino" << endl;
        return;
    }
    casino[name] += money;
}

void leave(map<string, int>& casino, string& name){
    if(not casino.count(name)){
        cout << name << " is not in the casino" << endl;
        return;
    }
    cout << name << " has won " << casino[name] << endl;
    casino.erase(name);
}

void update(map<string, int>& casino, string& name){
    string action; cin >> action;
    if(action == "enters") enter(casino, name);
    else if(action == "wins") win(casino, name);
    else if(action == "leaves") leave(casino, name);
}

void showState(map<string, int>& casino){
    for(auto e : casino){
        cout << e.first << " is winning " << e.second << endl;
    }
}

int main(){
    string name;
    map<string, int> casino;
    while(cin >> name){
        update(casino, name);
    }
    cout << "----------" << endl;
    showState(casino);
}
