#include <iostream>
#include <stdio.h>

#define N 1010

using namespace std;

int a[N][N], n;

int main() {
    for ( int i = 1; i < N; i++ )
        for ( int j = 1; j < N; j++ ) {
            if ( j == 1 ) {
                a[i][j] = i;
                continue;
            }
            if ( a[i][j-1] <= j-1 ) {
                a[i][j] = a[i][j-1];
                continue;
            }

            int m = a[i-1][j-1];
            for ( int k = 0; k <= i-1; k++ )
                if ( max(a[k][j-1], a[i-1-k][j]) < m ) 
                    m = max(a[k][j-1], a[i-1-k][j]);

            a[i][j] = m + 1;
        }

    int x, y;
    while (scanf("%d%d", &x, &y)) {
        if (( x == 0 ) && ( y == 0 ))
            break;

        printf("%d\n", a[y][x]);
    }
    
    return 0;
}

