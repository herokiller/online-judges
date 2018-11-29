#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    for ( int i = 2; i <= n+1; i++ ) {
        for ( int k = i-1; k >= 1; k-- )
            for ( int j = k; j <= i-1; j++ ) 
                printf("? %d %d\n", j, j+1);
        int x = rand()%(i-1) + 1;
        if ( n == 2 )
            x = 1;
        printf("! %d %d\n", x, x+1);
    }
    return 0;
}

