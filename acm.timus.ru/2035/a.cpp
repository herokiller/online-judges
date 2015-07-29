#include <iostream>
#include <stdio.h>

using namespace std;

int x, y, z;

int main() {
    scanf("%d%d%d", &x, &y, &z);
    if (x + y < z) {
        printf("Impossible\n");
    } else {
        if ( x > y ) {
            if (z-y >= 0)
                printf("%d %d\n", z-y, y);
            else
                printf("%d %d\n", 0, z);
        } else {
            if (z-x >= 0)
                printf("%d %d\n", x, z-x);
            else
                printf("%d %d\n", z, 0);
        }
    }
    return 0;
}

