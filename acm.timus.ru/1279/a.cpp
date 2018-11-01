#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 111
using namespace std;

int a[N*N], n, m, k, ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for ( int i = 1; i <= n*m; i++ )
        scanf("%d", &a[i]);

    sort(a+1, a+n*m+1);

    a[n*m+1] = a[n*m] + 1;

    for ( int i = 1; i <= n*m; i++ ) {
        if ( a[i] < a[i+1] ) {
            if (( k - i*(a[i+1] - a[i]) > 0 ) && ( i != n*m))
                k -= i*(a[i+1] - a[i]);
            else {
                ans = a[i] + (k/i);
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

