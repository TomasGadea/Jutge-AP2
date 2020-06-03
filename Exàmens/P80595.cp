#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> & V, int left, int right, int& compt) {
    vector<int> A(right-left+1);
    int mid = (left+right)/2;
    int k = 0;
    int i = left;
    int j = mid+1;
    while (j <= right and i <= mid) {
        if (V[i] > V[j]) {
            A[k] = V[j];
            compt += mid + 1 - i;
            j++;
        }
        else {
            A[k] = V[i];
            i++;
        }
        k++;
    }
    while (j <= right) {
        A[k] = V[j];
        j++;
        k++;
    }
    while (i <= mid) {
        A[k] = V[i];
        i++;
        k++;
    }
    int r = 0;
    for (int l = left; l <= right; l++) {
        V[l] = A[r];
        r++;
    }
}

void mergesort(vector<int>& v, int left, int right, int& compt) {
    if (right > left) {
        int mid = (left+right)/2;
        mergesort(v, left, mid, compt);
        mergesort(v, mid+1, right, compt);
        merge(v, left, right, compt);
    }
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> seq(n);
        for (int i = 0; i < n; i++) cin >> seq[i];
        int compt = 0;
        mergesort(seq, 0, n - 1, compt);
        cout << compt << endl;
    }
}
