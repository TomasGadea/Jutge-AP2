#include<iostream>
#include<vector>
using namespace std;

bool comprova(const int& n, const int& s, const vector<long>& l, long i){
  int count = 0; long sum = i;
  int j = 0;
  while(j < n){
    if(l[j] > sum){
      count ++;
      if(count > s) return false;
      sum = i-l[j];
    }
    else sum -= l[j];
    j++;
  }
  return true;
}

int evaluate(const int& n, const int& s, const vector<long>& l, long a, long b){
  if (b == a) return a;
  else{
    int i = (a+b)/2;
    if(comprova(n,s,l,i)) return evaluate(n,s,l,a,i);
    return evaluate(n,s,l,i+1,b);
  }
}

int main(){
  int n; int s;
  while(cin >> n){
    cin >> s;
    long x;
    vector<long> l(n); long sum = 0; long max = 0;
    for(int j = 0; j < n; j++){
      cin >> x;
      l[j] = x;
      sum += x;
      if(x > max){
        max = x;
      }
    }
    cout << evaluate(n,s,l,max,sum) << endl;
  }
}
