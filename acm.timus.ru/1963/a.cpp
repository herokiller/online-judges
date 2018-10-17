#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int x[5], y[5], l[5], ans;

int sqr(int x) {
    return x*x;
}

int main() {
    for ( int i = 1; i <= 4; i++ ) 
        scanf("%d%d", &x[i], &y[i]);
    
    for ( int i = 1; i <= 4; i++ ) {
        int j = i+1;
        if ( j == 5 ) 
            j = 1;
        l[i] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
    }
    int d1 = sqr(x[1] - x[3]) + sqr(y[1] - y[3]);
    int d2 = sqr(x[2] - x[4]) + sqr(y[2] - y[4]);
    
    if (( l[1] == l[2] ) && ( l[2] == l[3] ) && ( l[3] == l[4])) {
        if ( d1 == d2 )
            ans = 8;
        else 
            ans = 4;
    } else if ((l[1] == l[3]) && (l[2] == l[4]) && (d1 == d2)) {
        ans = 4;
    } else if (
                ((l[1] == l[2]) && (l[3] == l[4])) 
             || ((l[2] == l[3]) && (l[4] == l[1]))
             ) {
        ans = 2;
    } else if (((l[1] == l[3]) || (l[2] == l[4])) && (d1 == d2)) {
        ans = 2;
    }

    printf("%d\n", ans);
        
    return 0;
}

