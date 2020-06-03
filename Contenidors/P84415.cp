// La bossa de les paraules

#include<iostream>
#include<map>
#include<string>
using namespace std;


void update(map<string,int>& m, const string& p)
{
    if(p == "store")
    {
        string w;
        cin >> w;
        ++m[w];
    }
    else if(p == "delete"){
        string w;
        cin >> w;
        --m[w];
        if(m[w] <= 0) m.erase(w);
    }
    else if(p == "minimum?"){
        if(not m.empty()){
            auto min = m.begin();
            cout << "minimum: " << min->first << ", " << min->second << " time(s)" << endl;
        }
        else cout << "indefinite minimum" << endl;
    }
    else if(p == "maximum?"){
        if(not m.empty()){
            auto max = m.end();
            --max;
            cout << "maximum: " << max->first << ", " << max->second << " time(s)" << endl;
        }
        else cout << "indefinite maximum" << endl;
    }
}


int main()
{
    map<string,int> m;
    string p;
    while(cin >> p){
        update(m, p);
    }
}
