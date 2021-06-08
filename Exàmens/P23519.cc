// Minimitzar el màxim de les sumes (Ferran Hernandez Caralt)



/******************************************************************************

Estratègia utilitzada per l'algorisme:
    ...
    L'estratègia és la següent: dissenyem la funció has_max_sum de tal forma que ens digui si existeix alguna
    * partició que podem fer de manera que el màxim de la suma de les parts sigui menor o igual a cert valor x
    * Aquesta la implementem recorrent linealment el vector i separant en una nova part cada cop que la suma es
    * passa del valor x. Un cop tenim això podem implementar una cerca binària. És a dir, prenem variables menor
    * i major iguals a 0 i sum respectivament, si has_max_sum de la mitjana és fals, vol dir que el valor estarà
    * entre mitjana+1 i major, si no, estarà entre menor i mitjana.

Eficiència de l'algorisme: O(nlog(sum))

Explicació de l'eficiència:
    ...
    La cerca binària d'un nombre entre 0 i un valor sum (com a molt 10^9) té un cost log(sum), pel master theorem.
    * Si, a més, fem servir la funció has_max_sum, que té cost n (mida del vector). El resultat serà
    * O(nlog(sum)) que al ser sum <= 10^9, log(sum) <= 30. És a dir, és un algorisme eficient.

******************************************************************************/
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// returns whether v has a max-sum in m parts ≤ x
bool has_max_sum(const vector<int>& v, int m, int x) {
	int nparts = 0;
	int suma = 0;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (v[i] > x) return false;   //al ser nombres naturals, en alguna part hi haurà d'haver v[i], per tant, és impossible que alguna part tingui suma màxima <= x
		suma += v[i];
		if (suma > x) {			//en aquest cas, reinicialitzem les parts, i en comencem una de nova
			nparts++;
			suma = v[i];
		}
	}
	nparts++;						//l'última part
	if (nparts <= m) return true;
	return false;

}


// returns the min-max-sum of a vector for m parts
int min_max_sum(const vector<int>& v, int m) {				//farem una cerca binària sobre els possibles valors de la suma 0...10^9
	int menor = 0;						//menor sempre serà <= min_max_sum
	int major = 0;						//major sempre serà >= min_max_sum
	int n = v.size();
	for (int i = 0; i < n; i++) {					//sumem tots els valors per ajustar una mica més la cota superior de 10^9
		major += v[i];
	}
	while (menor < major) {							//mentre menor < major, voldrà dir que encara no hem trobat el valor que volem
		int valor_mig = (menor+major)/2;
		if (has_max_sum(v, m, valor_mig)) major = valor_mig;	//cerquem aquest valor fent ús de la funció hasmax
		else menor = valor_mig + 1;
	}
	return menor;
}

// main program
int main()
{
    int m, n;
    while (cin >> m >> n) {
        vector<int> v(n);
        for (int& x : v) {
            cin >> x;
        }
        cout << min_max_sum(v, m) << endl;
    }
}
