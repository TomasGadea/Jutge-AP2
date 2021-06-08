// Nombre de rotacions (1)

#include<iostream>
#include<vector>
using namespace std;

int number_of_rotations(const vector<int>& V)
{
    int i = 0;
    int j = V.size()-1;

    if(V[i] < V[j]) return 0;

    while(j - i > 1){
        int mid = (i+j) / 2;
	if(V[mid] > V[i]) i = mid;
	else if(V[mid] < V[i]) j = mid;
    }
    return j;
}
