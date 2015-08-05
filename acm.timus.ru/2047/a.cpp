#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int n, a[501000], d[3001000];
bool ok;

void rec(int sum, int p) {
    if ( p == n+1 ) {
        ok = 1;
        return;
    }

    for ( int i = 1; i <= 200; i++ ) {
        if ( d[sum + i] == i ) {
            a[p] = i;
            rec(sum+a[p], p+1);
            if (ok) 
                break;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= 1600000; i++ ) {
        int k = 1, x = i;
        for ( int j = 2; j <= (int)(sqrt(i)); j++ ) {
            int t = 1;
            while (x%j == 0) {
                t++;
                x /= j;
            }
            if ( d[x] > 0) {
                d[i] = t*d[x];
                break;
            }
            k *= t;
        }

        if ( x > 1 ) {
            k *= 2;
        }

        if ( d[i] == 0 ) 
            d[i] = k;
    }

    rec(0, 1);
    if ( ok ) {
        for ( int i = 1; i <= n; i++ )
            printf("%d ", a[i]);
        printf("\n");
    } else {
        printf("Impossible\n");
    }
    return 0;
}

