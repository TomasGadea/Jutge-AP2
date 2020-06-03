// Omplint la bossa

#include <iostream>
#include <set>
#include <string>
using namespace std;

void add(const long& val, set<long>& bag, set<long>& box, long& sum, const int& bs){
    if(bag.size() < bs){
        bag.insert(val);
        sum += val;
    }
    else if(val > *bag.begin()){
        bag.insert(val);
        sum += val;
        long min = *bag.begin();
        bag.erase(min);
        sum -= min;
        box.insert(min);
    }
    else{
        box.insert(val);
    }
}

void remove(const long& val, set<long>& bag, set<long>& box, long& sum, const int& bs){
    if(val >= *bag.begin()){
        bag.erase(val);
        sum -= val;
        if(not box.empty()){
            long max = *--box.end();
            box.erase(max);
            bag.insert(max);
            sum += max;
        }
    }
    else{
        box.erase(val);
    }
}

void update(set<long>& bag, set<long>& box, string& s, long& sum, const int& bs){
    long val; cin >> val;
    if(s == "deixar"){
        add(val, bag, box, sum, bs);
    }
    else{
        remove(val, bag, box, sum, bs);
    }
}

int main(){
    set<long> bag;
    set<long> box;
    string s;
    long sum = 0;
    int bs; cin >> bs;  // bs stands for 'bag size'
    while(cin >> s){
        update(bag, box, s, sum, bs);
        cout << sum << endl;
    }
}
