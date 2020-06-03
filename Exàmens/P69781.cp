// Pseudo-seqüències de Collatz (2)  (Alejandro Campayo Fernández)

#include <cassert>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int x, y, n;
  while (cin >> x >> y >> n) {

    map<int, int> seq;
    int comptador = 0;

    while (seq.find(n) == seq.end() and n <= 100000000) {
      seq[n] = comptador;
      if (n % 2 == 0) {
        n = n / 2 + x;
      } else
        n = 3 * n + y;
      ++comptador;
    }

    if (n > 100000000)
      cout << n << endl;
    else
      cout << comptador - seq[n] << endl;
  }
}
