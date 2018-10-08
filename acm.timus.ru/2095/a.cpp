#include <iostream>
#include <stdio.h>

using namespace std;

int calc(int x) {
    int k = 2;
    while ( k <= x ) {
        x = x - x/k;
        k++;
    }
    return x;
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);

    int ans = calc(r) - calc(l-1);
    printf("%d\n", ans);
    return 0;
}

