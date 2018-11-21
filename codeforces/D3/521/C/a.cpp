#include <iostream>

#define N 400200

using namespace std;

long long a[N], sum;
int c[2000100];
bool b[N];
int n, k;

int main() {
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        sum += a[i];
        c[a[i]]++;
    }

    for ( int i = 1; i <= n; i++ ){
        long long x = sum - a[i];
        if (( x%2 == 0 ) && (x/2 <= 1000000))
            if ((( c[x/2] > 0 ) && (a[i] != x/2 )) || (c[x/2] > 1)) {
                k++;
                b[i] = 1;
            }
    }
        
    cout << k << endl;
    for ( int i = 1; i <= n; i++ )
        if ( b[i] )
            cout << i << ' ';

    return 0;
}

