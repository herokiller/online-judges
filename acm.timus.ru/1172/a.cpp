#include <iostream>
#include <stdio.h>

using namespace std;

int d[33][33][33][4][27], n, ans[1111];

int main() {
    scanf("%d", &n);

    d[1][0][0][1][1] = 1;
    
    for ( int i = 1; i <= n; i++ ) 
        for ( int j = 0; j <= n; j++ ) 
            for ( int k = 0; k <= n; k++ ) {
                if ( i > 0 ) {
                    for ( int p = 1; p <= 26; p++ )
                        d[i][j][k][1][p] += d[i-1][j][k][2][p] + d[i-1][j][k][3][p];

                    for ( int p = 1; p <= 26; p++ )
                        if ( d[i][j][k][1][p] > 9 ) {
                            d[i][j][k][1][p+1] += (d[i][j][k][1][p]/10);
                            d[i][j][k][1][p] %= 10;
                        }
                }

                if ( j > 0 ) {
                    for ( int p = 1; p <= 26; p++ )
                        d[i][j][k][2][p] = d[i][j-1][k][1][p] + d[i][j-1][k][3][p];

                    for ( int p = 1; p <= 26; p++ )
                        if ( d[i][j][k][2][p] > 9 ) {
                            d[i][j][k][2][p+1] += (d[i][j][k][2][p]/10);
                            d[i][j][k][2][p] %= 10;
                        }
                }

                if ( k > 0 ) {
                    for ( int p = 1; p <= 26; p++ )
                        d[i][j][k][3][p] = d[i][j][k-1][1][p] + d[i][j][k-1][2][p];

                    for ( int p = 1; p <= 26; p++ )
                        if ( d[i][j][k][3][p] > 9 ) {
                            d[i][j][k][3][p+1] += (d[i][j][k][3][p]/10);
                            d[i][j][k][3][p] %= 10;
                        }
                }
            }


    for ( int p = 1; p <= 26; p++ )
        ans[p] = d[n][n][n][2][p];
    
    for ( int i = 1; i <= n; i++ ) {
        if ( i < n ) {
            for ( int p = 1; p <= 1000; p++ ) {
                ans[p] = ans[p]*i*i*i;
            }
        } else {
            for ( int p = 1; p <= 1000; p++ ) {
                ans[p] = ans[p]*i*i;
            }
        }

        for ( int p = 1; p <= 1000; p++ )
            if (ans[p] > 9) {
                ans[p+1] += (ans[p]/10);
                ans[p] %= 10;
            }
    }

    for ( int p = 1000; p >= 1; p-- ) {
        if ( ans[p] > 0) {
            for ( int i = p; i >= 1; i-- )
                printf("%d", ans[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}

