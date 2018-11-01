#include <iostream>
#include <stdio.h>

#define N 111

using namespace std;

int a[N][N], d[N][N], n;

int sum(int i, int j, int l) {
    return (d[i][j+l-1] - d[i][j-1]);
}

bool check(int i0, int j, int l) {
    if ( j + l - 1 > n )
        return 0;
    if ( i0 - l/2 < 1 )
        return 0;
    if ( i0 + l/2 > n )
        return 0;
    int bl = 0;
    for ( int i = i0-1; i >= i0 - l/2; i-- ) {
        bl++;
        if ( sum(i, j, bl) != bl )
            return 0;
        if ( sum(i, j+bl, l-2*bl) != 0)
            return 0;
        if ( sum(i, j + l - bl, bl) != bl )
            return 0;
    }
    
    bl = 0;
    for ( int i = i0; i <= i0 + l/2; i++ ) {
        if ( sum(i, j, bl) != bl )
            return 0;
        if ( sum(i, j+bl, l-2*bl) != 0)
            return 0;
        if ( sum(i, j+l-bl, bl) != bl)
            return 0;
        bl++;
    }
    return 1;

}

int main() {
    n = 1;
    while (n > 0) {
        scanf("%d", &n);

        if ( n == 0 ) 
            break;
        
        for ( int i = 1; i <= n; i++ ) {
            int s = 0;
            for ( int j = 1; j <= n; j++ ) {
                scanf("%d", &a[i][j]);
                s += a[i][j];
                d[i][j] = s;
            }
        }

        int ans = 0;
        for ( int c = 1; c <= n; c++ ) {
            for ( int i = 1; i <= n; i++ ) {
                if ( a[i][c] == 0 ) {
                    int i0 = i+1;
                    while ( a[i0][c] == 1 ) {
                        if (check(i, c, (i0 - i)*2+1)) {
                            if ((i0 - i)*2 + 1 > ans ) {
                                ans = (i0 - i)*2 + 1;
                            }
                        }
                        i0++;
                    }
                    i = i0-1;
                }
            }
        }

        if ( ans > 0 ) 
            printf("%d\n", ans);
        else
            printf("No solution\n");
    }

    return 0;
}

