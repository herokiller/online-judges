#include <iostream>
#include <stdio.h>

#define N 1410

using namespace std;

int n, v0, v1;
bool a[N][N];

void checkDirection(int i, int j, int di, int dj) {
    int c0 = 0, c1 = 0;
    while (( i >= 1 ) && ( i <= n ) && ( j <= n ) && ( j >= 1 )) {
        if ( !a[i][j] ) {
            c1 = 0;
            c0++;
            if ( c0 > v0 )
                v0 = c0;
        } else {
            c0 = 0;
            c1++;
            if ( c1 > v1 ) 
                v1 = c1;
        }
        i += di;
        j += dj;
    }
}

int main() {
    scanf("%d\n", &n);
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            char ch;
            scanf("%c", &ch);
            if ( ch == 's' )
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
        scanf("\n");
    }

    for ( int i = 1; i <= n; i++ ) {
        checkDirection(i, 1, 1, 1);
        checkDirection(1, i, 1, 1);
        checkDirection(i, 1, -1, 1);
        checkDirection(n, i, -1, 1);
        checkDirection(i, 1, 0, 1);
        checkDirection(1, i, 1, 0);
    }

    if ( v0 > v1 )
        printf("s\n%d\n", v0);
    else if ( v0 < v1 ) 
        printf("S\n%d\n", v1);
    else
        printf("?\n%d\n", v0);

    return 0;
}

