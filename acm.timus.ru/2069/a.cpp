#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, i1, i2, j1, j2, im, jm;

int main() {
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ ) {
        int x;
        scanf("%d", &x);
        if ( i == 1 ) 
           i1 = x;
        if ( i == n )
           i2 = x;
        if ( x > im )
           im = x; 
    }

    for ( int j = 1; j <= m; j++ ) {
        int x;
        scanf("%d", &x);
        if ( j == 1 ) 
            j1 = x;
        if ( j == m )
            j2 = x;
        if ( x > jm )
            jm = x;
    }

    int ans = 0, t;
    t = min(i1, j2);
    if ( t > ans ) 
        ans = t;
    t = min(j1, i2);
    if ( t > ans )
        ans = t;
    t = min(min(i1, i2), jm);
    if ( t > ans )
        ans = t;
    t = min(min(j1, j2), im);
    if ( t > ans )
        ans = t;

    printf("%d\n", ans);
    return 0;
}

