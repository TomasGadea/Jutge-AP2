// Codis de Huffman

#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

double huffman_average_bits(int n)
{
    priority_queue<double, vector<double>, greater<double>> pq;
    for(int i = 0; i < n; ++i){
        double freq;
        cin >> freq;
        pq.push(freq);
    }
    double average = 0;
    while(pq.size() > 1){
        double a = pq.top();
        pq.pop();
        double b = pq.top();
        pq.pop();
        average += (a+b)/100;
        pq.push(a+b);
    }
    return average;
}

int main()
{
    cout << setprecision(4) << fixed;

    int n;
    cin >> n;
    cout << "nombre esperat de bits per lletra: " << huffman_average_bits(n) << endl;
}
