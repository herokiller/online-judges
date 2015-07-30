#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAXN 1010

using namespace std;

struct vp {
    int v, p;
};
vp a[MAXN], b[MAXN];
int n;


bool comp1(vp x, vp y) {
    return x.v < y.v;
}

bool comp2(vp x, vp y) {
    return x.v > y.v;
}

int main() {
    scanf("%d", &n);
    int asum = 0, bsum = 0;
    for ( int i = 0; i < n; i++ ) {
        a[i].p = i+1;
        scanf("%d", &a[i].v);
        asum += a[i].v;
    }
    for ( int i = 0; i < n; i++ ) {
        b[i].p = i+1;
        scanf("%d", &b[i].v);
        bsum += b[i].v;
    }

    if ( asum > bsum ) {
        sort(a, a+n, comp1);
        sort(b, b+n, comp2);
    } else {
        sort(a, a+n, comp2);
        sort(b, b+n, comp1);
    }

    for ( int i = 0; i < n; i++ )
        printf("%d %d\n", a[i].p, b[i].p);
    return 0;
}

