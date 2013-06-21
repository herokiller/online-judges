#include <stdio.h>

using namespace std;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    
    int ans = k - 2;
    int x, y;

    for ( int i = 0; i < n; i++ ) {
        scanf("%d%d", &x, &y);
        ans = ans + x - y - 2;
    }

    if ( ans < 0 )
        printf("Big Bang!\n");
    else 
        printf("%d\n", ans);

    return 0;
}

