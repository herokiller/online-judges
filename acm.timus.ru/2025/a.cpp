#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for ( int i = 0; i < t; i++ ) {
        int k, n;
        scanf("%d%d", &n, &k);
        int v1 = n/k, k1 = k - (n%k); 
        if ( k1 == 0 ) 
            k1 = k;
        int v2 = n/k + 1, k2 = n%k;

        int ans = v1*v1*(k1*(k1-1))/2 + v2*v2*(k2*(k2-1))/2 + v1*v2*k1*k2;
        printf("%d\n", ans);
    }
    return 0;
}

