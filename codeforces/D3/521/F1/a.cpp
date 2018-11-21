#include <iostream>
#include <stdio.h>

#define N 222
using namespace std;

int n, x, k;
long long d[N][N], a[N], ans, m[N][N];
int main() {
    scanf("%d%d%d", &n, &k, &x);
    for ( int i = 1; i <= n; i++ )
        cin >> a[i];

    ans = -1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= min(i, x); j++ ) {
            if (( m[i-1][j-1] + a[i] > d[i][j] ) && ((i == 1) || (m[i-1][j-1] > 0)))
                d[i][j] = m[i-1][j-1] + a[i];
                        
            if (( d[i][j] > ans ) && (j == x) && (n-i < k)) {
                cout << n << ' ' << i << ' ' << d[i][j] << ' ' << n - i << endl;

                ans = d[i][j];
            }
            m[i][j] = max(d[i][j], m[i-1][j]);
        }

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ )
            cout << m[i][j] << ' ' ;
        cout << endl;
    }
    cout << endl;

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ )
            cout << d[i][j] << ' ';
        cout << endl;
    }

    cout << ans << endl;
    return 0;
}

