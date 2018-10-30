#include <iostream>
#include <stdio.h>
#include <algorithm>

#define N 100100

using namespace std;

struct data {
    int l, r, p;
};

data a[N], b[N];
int n, c[N], c2[N], k, l1, l2, r1, r2, p;
bool mark[N];

bool comp1(data x, data y) {
    return ((x.l < y.l) || ((x.l == y.l) && (x.r > y.r)));
}

bool comp2(data x, data y) {
    return ((x.r > y.r) || ((x.r == y.r) && (x.l < y.l)));
}

int main() {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d%d", &a[i].l, &a[i].r);
        if ( a[i].l > a[i].r ) {
            int x = a[i].l;
            a[i].l = a[i].r;
            a[i].r = x;
        }
        b[i].l = a[i].l;
        b[i].r = a[i].r;
        a[i].p = i;
        b[i].p = i;
    }

    sort(a+1, a+n+1, comp1);
    sort(b+1, b+n+1, comp2);
    
    p = n+1;
    for ( int i = 1; i <= n; i++ ) {
        if ((a[i].l == b[i].l) && (a[i].r == b[i].r)) {
            mark[a[i].p] = 1;
            c[i] = 1;
            k++;
        } else {
            p = i;
            break;
        }
    }
    
    c[p] = 2;
    if ( p <= n ) {
        l1 = a[p].l;
        r1 = a[p].r;

        l2 = b[p].l;
        r2 = b[p].r;
        if ( l2 > r1 ) {
            printf("NO\n");
            return 0;
        }
        mark[b[p].p] = 1;
        mark[a[p].p] = 1;
    }
    int lt = r1;
    int rt = r1;
    if ( p <= n )
        k++;
    for ( int i = p+1; i <= n; i++ ) {
        if (a[i].r > r1)
            continue;
        if ((a[i].r <= rt) && (a[i].r >= l2) && (!mark[a[i].p])) {
            c[i] = 2;
            k++;
            rt = a[i].r;
            mark[a[i].p] = 1;
        }
    }

    if (p <= n)
        k++;
    c2[p] = 3;
    for ( int i = p+1; i <= n; i++ ) {
        if (!mark[b[i].p]) {
            if ((b[i].l >= l2) &&(b[i].l <= rt)) {
                c2[i] = 3;
                k++;
                l2 = b[i].l;
            } else 
                break;
        }
    }
   /* 
    int k1 = 0;
    for ( int i = 1; i <= n; i++ ) {
        if ( c[i] > 0 )
            k1++;
        if ( c2[i] > 0 )
            k1++;
    }

    if (k1 != k)  {
        printf("ASDF");
        return 0;
    }
    */
    if ( k < n ) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for ( int i = 1; i <= n; i++ )
        if ( c[i] == 1 )
            printf("%d %d\n", a[i].l, a[i].r);

    for ( int i = 1; i <= n; i++ ) 
        if ( c[i] == 2 )
            printf("%d %d\n", a[i].l, a[i].r);

    for ( int i = n; i >= 1; i-- )
        if ( c2[i] == 3 )
            printf("%d %d\n", b[i].r, b[i].l);
    
    return 0;
}
