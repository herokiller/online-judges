#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
};

struct vect { 
    double v;
    int p;
};

int n, mi, mx, my;
point a[10010];
vect c[10010];

bool comp(vect a, vect b) {
    return a.v < b.v;
}

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d%d", &a[i].x, &a[i].y);
        if (( a[i].x < mx ) || ((a[i].x == mx) && (a[i].y < my)) || (i == 1)) {
            mx = a[i].x;
            my = a[i].y;
            mi = i;
        }
    }

    for ( int i = 1; i <= n; i++ ) {
        if ( a[i].x - mx == 0 )
            c[i].v = 1000000100;
        else
            c[i].v = (double)(a[i].y - my)/(double)(a[i].x - mx);
        c[i].p = i;
    }
    /*
    for ( int i = 1; i <= n; i++ )
        printf("%.2lf %d\n", c[i].v, c[i].p);
    cout << endl;
    */
    sort(c+1, c+n+1, comp);
    /*
    for ( int i = 1; i <= n; i++ )
        printf("%.2lf %d\n", c[i].v, c[i].p);
    */
    printf("%d %d\n", mi, c[n/2].p);
    return 0;
}

