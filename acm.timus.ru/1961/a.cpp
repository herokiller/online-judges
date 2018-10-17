#include <iostream>
#include <stdio.h>

using namespace std;

long long n, m, N, M;

int main() {
    cin >> n >> m >> N;
    M = N*m/n;

    while ((M > 0) && (((M - m)*(N - M + 1))/((N - M - n + m + 1)*M) >= 1)) 
        M--;

    while ((M < N) && (((M+1)*(N - M - n + m))/((N - M)*(M - m + 1)) >= 1))
        M++;

    cout << M << endl;
    return 0;
}

