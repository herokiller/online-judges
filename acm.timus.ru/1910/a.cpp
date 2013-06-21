#include <stdio.h>

using namespace std;

int n, a[2000], m, ans;

int main() {
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &a[i]);

    m = a[0] + a[1] + a[2];
    ans = 2;

    for ( int i = 1; i < n-1; i++ )
        if ( a[i-1] + a[i] + a[i+1] > m ) {
            m = a[i-1] + a[i] + a[i+1];
            ans = i+1;
        }

    printf("%d %d\n", m, ans);

    return 0;
}

