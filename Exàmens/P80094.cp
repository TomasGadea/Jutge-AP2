// Honest politicians  (Martí Cortada Garcia)

#include <iostream>
#include <map>
#include <string>

using namespace std;

void R(map<string, int>& bank)
{
    string name;
    int n;
    cin >> name >> n;
    bank[name] += n;
}

void G(map<string, int>& bank)
{
    string name;
    int n;
    cin >> name >> n;
    bank[name] -= n;
}

void P(map<string, int>& bank)
{
    string name1, name2;
    int n;
    cin >> name1 >> n >> name2;
    bank[name1] -= n;
    bank[name2] += n;
}

int main()
{
    int r;

    while (cin >> r) {
        string order;
        map<string, int> bank;

        while (cin >> order and order != "END") {
            if (order == "R") R(bank);
            else if (order == "G") G(bank);
            else if (order == "P") P(bank);
        }

        // we have reached order == "END"


    }
}
