#include <iostream>
#include <stdio.h>

#define N 111

using namespace std;

int n, m, a[N][N], b[N][N];

int main() {
    scanf("%d%d", &n, &m); 
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            scanf("%d", &a[i][j]);

    int k = 0;
    for ( int i = 1; i <= n; i+=2 )
        for ( int j = 1; j <= m; j+=2 ) {
            if (( a[i][j] == a[i][j+1] ) || ( a[i+1][j] == a[i+1][j+1])) {
                k++;
                b[i][j] = k;
                b[i+1][j] = k;
                k++;
                b[i][j+1] = k;
                b[i+1][j+1] = k;
            } else {
                k++;
                b[i][j] = k;
                b[i][j+1] = k;
                k++;
                b[i+1][j] = k;
                b[i+1][j+1] = k;
            }
        }

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ )
            printf("%d ", b[i][j]);
        printf("\n");
    }
    return 0;
}

