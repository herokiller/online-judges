#include <stdio.h>

using namespace std;

int n, k;

int main() {
    scanf("%d%d", &n, &k);

    if ( k%2 == 0 )
        printf("%d ", -k/2);
    for ( int i = (k-1)/2; i >= 1; i-- )
        printf("%d %d ", i, -i);

    for ( int i = 1;  i <= n - k + 1; i++ )
        printf("0 ");
    printf("\n");
}

