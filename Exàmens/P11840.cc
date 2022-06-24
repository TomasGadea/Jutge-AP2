// Amistat a la xarxa (Nathatniel Mitrani)

#include<iostream>
#include<vector>
using namespace std;

using Node = int;
using CCID = vector<int>;
using CCUsers = vector<int>;

int main()
{
    int n, q;
    while (cin >> n >> q) {
        CCID ccid(n);
        CCUsers ccusers(n, 1);

        for (int i=0;i<n;i++) ccid[i]=i;

        for (int i = 0; i < q; ++i) {
            char op;
            cin >> op;

            if (op == 'a') {
                Node x, y;
                cin >> x >> y;
                x--;
                y--;
                if (ccid[x] != ccid[y]) {
                    int ccidx = ccid[x], ccidy = ccid[y];
                    for (int& elem : ccid) {
                        if (elem == ccidy)
                            elem = ccidx;
                    }
                    ccusers[ccid[x]] += ccusers[ccidy];
                }
            } else { // op == 'c'
                Node x;
                cin >> x;
                x--;
                cout << ccusers[ccid[x]] << endl;
            }
        }
        cout << "----------" << endl;
    }
}
