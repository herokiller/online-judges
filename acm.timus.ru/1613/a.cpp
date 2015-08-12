#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100000

using namespace std;

struct data {
    int v, i;
};

bool comp(data a, data b) {
    return ((a.v < b.v) || ((a.v == b.v) && (a.i < b.i)));
}

data a[N];
int n, m;


int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d", &a[i].v);
        a[i].i = i;
    }

    sort(a+1, a+n+1, comp);

    scanf("%d", &m);
    for ( int i = 1; i <= m; i++ ) {
        int li, ri, vi, l0 = -1, r0 = -1;
        scanf("%d%d%d", &li, &ri, &vi);
        

        int l = 1, r = n;
        while (l < r) {
            int m = (l+r)/2;

            if (vi <= a[m].v) {
                r = m;
            } else {
                l = m+1;
            }
        }

        if ( a[l].v == vi ) {
            l0 = l;
        }

        l = 1; r = n;
        while ( l < r ) {
            int m = (l+r+1)/2;

            if ( vi >= a[m].v ) {
                l = m;
            } else {
                r = m-1;
            }
        }

        if ( a[l].v == vi ) {
            r0 = r;
        }

        if (( l0 == -1 ) || (r0 == -1)) {
            printf("0");
        } else {
            while (l0 < r0) {
                int m = (l0+r0)/2;

                if (a[m].i < li ) {
                    l0 = m+1;
                } else {
                    r0 = m;
                }
            }
            if (( a[l0].i >= li ) && ( a[l0].i <= ri )) {
                printf("1");
            } else {
                printf("0");
            }
        }
    }

    printf("\n");
    return 0;
}

