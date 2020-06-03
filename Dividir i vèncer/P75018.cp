// Diamants

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void isMarried(int& v, vector<int>& d){
    sort(d.begin(), d.end());
    int i = 0;
    int j = d.size() - 1;
    while(i < j){
        if(d[i] + d[j] == v){
            cout << "married" << endl;
            return;
        }
        else if(d[i] + d[j] < v){
            ++i;
        }
        else{    // d[i] + d[j] > v
            --j;
        }
    }
    cout << "single" << endl;
}


int main(){
    int v, n;
    while(cin >> v and v > 0){
        cin >> n;
        if(n == 0) break;
        else{
            vector<int> d(n);
            for(int i = 0; i < n; ++i){
                cin >> d[i];
            }
            isMarried(v, d);
        }
    }
}
