#include <iostream>
#include <stdio.h>

#define N 200200

using namespace std;

int a[N], n, k, c[N+N];

int main() {
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d", &a[i]);
        c[a[i]]++;
    }

    int l = 1, r = n/k;

    while (l < r ) {
        int m = (l+r+1)/2;

        int x = 0;
        for ( int i = 1; i <= N; i++ ) {
            x += c[i]/m;
        }

        if ( x >= k )
            l = m;
        else 
            r = m-1;
    }
    
    int rm = k;

    for ( int i = 1; i <= N; i++ ) {
        if ( c[i]/l > 0 ) {
            for ( int j = 1; j <= c[i]/l; j++ ) {
                printf("%d ", i);
                rm--;
                if ( rm == 0 )
                    return 0;
            }
        }
    }

    return 0;
}
