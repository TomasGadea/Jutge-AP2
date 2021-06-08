// Suma dels k més petits

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

int partition(vector<int>& v, int l, int r) {
    const int x = v[l];
    int i = l - 1;
    int j = r + 1;
    for (;;) {
        while (x < v[--j]);
        while (v[++i] < x);
        if (i >= j) return j;
        swap(v[i], v[j]);
    }
}

void quicksort(vector<int>& v, int l, int r, int k)
{
    if(l < r){
        const int q = partition(v, l, r);
        if(q == k-1) return;
        else if(q < k-1) quicksort(v, q+1, r, k);
        else quicksort(v, l, q, k);
    }
}

int sum_smallest (vector<int> v, int k) {
    int n = v.size();
    assert(k >= 0 and k <= n);
    quicksort(v, 0, n - 1, k);
    int s = 0;
    for (int i = 0; i < k; ++i) s += v[i];
    return s;
}
