// Exponenciació modular

#include<iostream>
using namespace std;

int compute(int& n, int& k, int& m)
{
    int exp = 1;
    int x = n % m;
    while(k > 0){
        if(k % 2 == 1){
            exp = (exp * x) % m;
        }
        x = (x * x) % m;
        k /= 2;
    }
    return exp;
}


int main()
{
    int n, k, m;
    while(cin >> n >> k >> m){
        cout << compute(n, k, m) << endl;
    }
}
