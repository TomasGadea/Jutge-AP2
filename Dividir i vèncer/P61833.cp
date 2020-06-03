// Powers of a matrix

#include<iostream>
#include<vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix create_matrix(int a, int b, int c, int d)
{
    Matrix M(2, vector<int>(2));
    M[0][0] = a;
    M[0][1] = b;
    M[1][0] = c;
    M[1][1] = d;

    return M;
}

void write_matrix(const Matrix& M)
{
    cout << M[0][0] << ' ' << M[0][1] << endl;
    cout << M[1][0] << ' ' << M[1][1] << endl;
    cout << "----------" << endl;
}

Matrix mul(Matrix& A, Matrix& B, int m)
{
    Matrix M(2, vector<int>(2));
    M[0][0] = (A[0][0]%m * B[0][0]%m  +  A[0][1]%m * B[1][0]%m) % m;
    M[0][1] = (A[0][0]%m * B[0][1]%m  +  A[0][1]%m * B[1][1]%m) % m;
    M[1][0] = (A[1][0]%m * B[0][0]%m  +  A[1][1]%m * B[1][0]%m) % m;
    M[1][1] = (A[1][0]%m * B[0][1]%m  +  A[1][1]%m * B[1][1]%m) % m;

    return M;
}

Matrix power(Matrix& M, int n, int m)
{
    if(n == 0){
        Matrix A(2, vector<int>(2));
        A[0][0] = A[1][1] = 1;
        A[0][1] = A[1][0] = 0;
        return A;
    }
    else if(n%2 == 0){
        Matrix A = power(M, n/2, m);
        return mul(A, A, m);
    }
    else if(n%2 == 1){
        Matrix A = power(M, n/2, m);
        A = mul(A, A, m);
        return mul(M, A, m);
    }
}

int main()
{
    int a, b, c, d, n, m;
    while(cin >> a >> b >> c >> d >> n >> m){
        Matrix M = create_matrix(a, b, c, d);
        M = power(M, n, m);
        write_matrix(M);
    }
}
