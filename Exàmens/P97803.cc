// Biblioteca

#include<iostream>
#include<sstream>
#include<stack>
#include<vector>
using namespace std;

void input_books(vector<stack<string>>& v)
{
    int n = v.size();
    for(int i = -1; i < n; ++i){
        string s;
        getline(cin, s);
        istringstream iss(s);
        string book;
        while(iss >> book){
            v[i].push(book);
        }
    }
}

void output_books(vector<stack<string>>& v)
{
    int n = v.size();
    for(int i = 0; i < n; ++i){
        cout << "Pila " << i+1 << ':';

        stack<string> p;
        while(not v[i].empty()){
            p.push(v[i].top());
            v[i].pop();
        }
        while(not p.empty()){
            cout <<' '<< p.top();
            p.pop();
        }
        cout << endl;
    }
}

void update(vector<stack<string>>& v, string& cmd)
{
    int n = v.size();

    if(cmd == "PRESTEC"){
        int type;
        cin >> type;
        if(0 < type and type <= n and not v[type-1].empty()){
            v[--type].pop();
        }
    }
    else if(cmd == "RETORN"){
        string book;
        cin >> book;
        int type;
        cin >> type;
        if(0 < type and type <= n){
            v[--type].push(book);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<stack<string>> v(n);
    input_books(v);

    string cmd;
    while(cin >> cmd){
        update(v, cmd);
    }
    output_books(v);
}
