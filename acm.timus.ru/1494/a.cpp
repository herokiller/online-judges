#include <stdio.h>

using namespace std;

int x, last, n, a[100100], k;

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d", &x);
        if ( x > last ) {
            for ( int j = last+1; j <= x-1; j++ ) {
                k++;
                a[k] = j;
            }
            last = x;
        } else {
            if ( x != a[k] ) {
                printf("Cheater\n");
                return 0;
            }
            k--;
        }
    }

    printf("Not a proof\n");
    return 0;
}

