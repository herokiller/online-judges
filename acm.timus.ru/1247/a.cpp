#include <stdio.h>

using namespace std;

int n, m, a[30010];

int main() {
    bool ok = 1;
    scanf("%d%d", &n, &m);
    int cur = 0;
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d", &a[i]);
        cur += a[i] - 1;
        if (cur < 0 ) {
            ok = 0;
            break;
        }
    }

    cur = 0;
    for ( int i = n; i >= 1; i-- ) {
        cur += a[i]-1;
        if ( cur < 0 ) {
            ok = 0;
            break;
        }
    }

    if ( ok ) 
        printf("YES\n");
    else 
        printf("NO\n");
    return 0;
}

