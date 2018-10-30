#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int nt, n;

int main() {
    scanf("%d", &nt);
    for ( int t = 1; t <= nt; t++ ) {
        scanf("%d", &n);
        int p, q;
        for ( int i = 2; i <= (int)(sqrt(n)); i++ )
            if (n%i == 0 ) {
                p = i;
                q = n/i;
                break;
            }
    
        printf("0 1 ");
        for ( int i = 1; i <= p; i++ ) {
            if ( (q*i - 1)%p == 0 ) 
                printf("%d ", q*i);

            if ( (q*i + 1)%p == 0 ) {
                printf("%d ", q*i+1);
            }
        }

        printf("\n");
    }

    return 0;
}

